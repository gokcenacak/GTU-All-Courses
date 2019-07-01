#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <signal.h> 
#include <time.h>   

int bank_alive = 1;
int counter_writer_fd[4][2];
int child_index;

struct Queue{
	int front, end, size; 
    int capacity; 
    int* array; 
};

struct Queue * create_queue(int capacity){
	struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = 0;
    queue->size = 0;  
    queue->end = capacity - 1;  
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
}

int is_full(struct Queue* queue){
	return (queue->size == queue->capacity);
} 
  

int is_empty(struct Queue* queue){
	return (queue->size == 0);
} 
  
void enqueue(struct Queue* queue, int item){ 
    if (!is_full(queue)) {    
		queue->end = (queue->end + 1)%queue->capacity; 
		queue->array[queue->end] = item; 
		queue->size = queue->size + 1; 
    }
} 
  
int dequeue(struct Queue* queue){ 
    if (!is_empty(queue)) {
    	int item = queue->array[queue->front]; 
	    queue->front = (queue->front + 1)%queue->capacity; 
	    queue->size = queue->size - 1; 
	    return item; 
    }  
} 

void destroy_queue(struct Queue * queue){
	free(queue->array);
	free(queue);
}
  
void close_bank(union sigval sv) {
	printf("Bank is closed\n");
	bank_alive = 0;
}

void respond(union sigval sv){
    char * counter_req = sv.sival_ptr;
	char response[64];
	int i;
	//printf("(DEBUG) Request Recieved At Bank Child %d: %s\n", child_index , counter_req);
	char client_res_fifo_fn[64] = "/tmp/Client_";
	strcat(client_res_fifo_fn,counter_req);
	int client_response_fifo = open(client_res_fifo_fn, O_WRONLY);
	srand(time(NULL));
	int money = (rand() % 100) + 1;

	if(!bank_alive){
		sprintf(response, "%d" ,0);
	}
	else{
		sprintf(response, "%d" ,money);
	}

	write(client_response_fifo, response, sizeof(response));
	close(client_response_fifo);
	char response_to_bank[64];
	sprintf(response_to_bank, "%s %s", counter_req, response);
	//printf("(DEBUG) Response Sending At Bank Child %d: %s\n", child_index, response_to_bank);
	write(counter_writer_fd[child_index][1],response_to_bank,sizeof(response_to_bank));
	

	for(i = 0 ; i < 64 ; i++){
		counter_req[i] = 0;
		client_res_fifo_fn[i] = 0;
		response_to_bank[i] = 0;
	}
}

void sigint_handler(int signo) {
	bank_alive = 0;
}

int main(int argc,char *argv[]) {
	FILE * log_file;
	int bank_req_fifo;
	char bank_req_buf[64];
	char counter_req[64];
	char counter_res[64];
	char response[64];
	pid_t bank_pid;
	pid_t counter_pid[4];
	int counter_reader_fd[4][2];
	int is_counter_empty[4] = {1,1,1,1};
	int counter_client_count[4] = {0,0,0,0};
	struct Queue * q = create_queue(8192);

	log_file = fopen("Banka.log","w");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(log_file,"%d/%d/%d tarihinde islem basladi. Bankamiz %s saniye hizmet verecek.\n",tm.tm_mday,tm.tm_mon +1 ,tm.tm_year + 1900,argv[1]);
	fprintf(log_file, "clientPid\t\tprocessNo\t\tPara\t\tislem bitis zamani\n");
	fprintf(log_file, "---------\t\t---------\t\t----\t\t------------------\n");
	signal(SIGINT, sigint_handler);

	struct timespec start_time;
	clock_gettime(CLOCK_MONOTONIC_RAW,&start_time);

	int i;
	if(argc != 2){
		printf("./Banka [execution time in seconds]\n");
		exit(EXIT_FAILURE);
	}

	/*Timer code has been taken and formatted from https://riptutorial.com/posix/example/16306/posix-timer-with-sigev-thread-notification*/
    timer_t timerid;
    struct sigevent sev;
    struct itimerspec trigger;

    memset(&sev, 0, sizeof(struct sigevent));
    memset(&trigger, 0, sizeof(struct itimerspec));

    sev.sigev_notify = SIGEV_THREAD;
    sev.sigev_notify_function = &close_bank;

    timer_create(CLOCK_REALTIME, &sev, &timerid);

    trigger.it_value.tv_sec = atoi(argv[1]);
    timer_settime(timerid, 0, &trigger, NULL);

    if(mkfifo("/tmp/Request" , 0666) == -1 ){
    	printf("An error has occured during the bank_request FIFO creation process.\n");
    	exit(EXIT_FAILURE);
    }

    bank_req_fifo = open("/tmp/Request" , O_RDONLY | O_NONBLOCK);
    for(i = 0 ; i < 4 ; i++){
		pipe(counter_reader_fd[i]);
		pipe(counter_writer_fd[i]);
	}

	for(i = 0 ; i < 4 ; i++){
	    switch(bank_pid = fork()){
				case -1:
					printf("An error has occured during the creation of the child process\n");
					exit(EXIT_FAILURE);
				/*Child process action*/
				case  0:
					signal(SIGINT, sigint_handler);
					child_index = i;	
					close(counter_writer_fd[i][0]);
					close(counter_reader_fd[i][1]);

					while(bank_alive){
						if(read(counter_reader_fd[i][0],counter_req,sizeof(counter_req)) > 0){
							/*Timer code has been taken and formatted from https://riptutorial.com/posix/example/16306/posix-timer-with-sigev-thread-notification*/
							timer_t timerid_child;
							struct sigevent sev_child;
							struct itimerspec trigger_child;

							memset(&sev_child, 0, sizeof(struct sigevent));
							memset(&trigger_child, 0, sizeof(struct itimerspec));

							sev_child.sigev_notify = SIGEV_THREAD;
							sev_child.sigev_notify_function = &respond;
							sev_child.sigev_value.sival_ptr = &counter_req;

							timer_create(CLOCK_REALTIME, &sev_child, &timerid_child);

							trigger_child.it_value.tv_sec = 1;
							trigger_child.it_value.tv_nsec = 500000000;


							timer_settime(timerid_child, 0, &trigger_child, NULL);
						}
					}

					exit(EXIT_SUCCESS);
					break;

				default:	
					counter_pid[i] = bank_pid;
					close(counter_reader_fd[i][0]);
					close(counter_writer_fd[i][1]);
					fcntl(counter_writer_fd[i][0], F_SETFL, O_NONBLOCK);

		}
	}

    while(bank_alive){

    	int bytes = read(bank_req_fifo , bank_req_buf , sizeof(bank_req_buf));


    	if(bytes > 0) {
    		//printf("(DEBUG) Request Received At Bank Main: %s\n", bank_req_buf);
    		enqueue(q,atoi(bank_req_buf));	
    	}
    	for(i = 0 ; i < 4 ; i++){
	    	if(is_counter_empty[i] && !is_empty(q)){
	    		int temp = dequeue(q);
	    		char client_pid[64];
	    		sprintf(client_pid,"%d",temp);
	    		//printf("(DEBUG) Bank is Sending Request to counter %d: %s\n",i, client_pid);
				write(counter_reader_fd[i][1],client_pid,sizeof(client_pid));
				is_counter_empty[i] = 0;
	    	}
	    
	    	if(read(counter_writer_fd[i][0], counter_res, sizeof(counter_res)) > 0){
	    		is_counter_empty[i] = 1;
	    		struct timespec current_time;
	    		clock_gettime(CLOCK_MONOTONIC_RAW,&current_time);
	    		long int total_time = (current_time.tv_sec - start_time.tv_sec) * 1000000 + (current_time.tv_nsec - start_time.tv_nsec) / 1000;
	    		total_time/=1000;
	    		counter_client_count[i]++;
				//printf("(DEBUG) Response Received from counter %d At Bank Main: %s at time %ld\n",i, counter_res , total_time);
				int res_pid,res_money;
				sscanf(counter_res,"%d %d",&res_pid,&res_money);
				fprintf(log_file, "%d\t\t\tprocess%d\t\t%d\t\t\t%ld msec\n", res_pid , i+1 ,res_money , total_time);
	    	}
		}
    	
    }

    while(!is_empty(q)){
    	int temp = dequeue(q);
    	char fifo_name[64];
    	sprintf(fifo_name,"/tmp/Client_%d",temp);
    	int client_response_fifo = open(fifo_name, O_WRONLY);
		sprintf(response, "0");
		write(client_response_fifo, response, sizeof(response));
		close(client_response_fifo);
    }

    for(i = 0 ; i < 4 ; i++){
    	kill(counter_pid[i], SIGINT);
    }

    fprintf(log_file, "\n%s saniye dolmustur %d musteriye hizmet verdik\n", argv[1], counter_client_count[0] + counter_client_count[1] + counter_client_count[2] + counter_client_count[3]);
    for(i = 0 ; i < 4 ; i++){
    	fprintf(log_file, "\nprocess%d %d", i+1 , counter_client_count[i]);
    }
    fprintf(log_file, " musteriye hizmet sundu ....\n");
    unlink("/tmp/Request");
    timer_delete(timerid);
    destroy_queue(q);
    fclose(log_file);
    return 0;
}

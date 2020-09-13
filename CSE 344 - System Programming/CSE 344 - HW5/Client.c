#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{
	int client_count = atoi(argv[1]);
	pid_t client_pid;
	int client_status;
	char client_fifo_name[64];
	int client_response_fifo;
	int bank_request_fifo;
	pid_t *client_pid_arr;
	int i;
	client_pid_arr = (pid_t*)calloc(client_count,sizeof(pid_t));

	/* code */
	if(argc != 2){
		printf("./Client [client number]\n");
		exit(EXIT_FAILURE);
	}
	printf("%d \n", client_count);
	for(i = 0 ; i < client_count ; i++){
		switch(client_pid = fork()){
			case -1:	printf("An error has occured during the creation of the child process\n");
						exit(EXIT_FAILURE);
			/*Child process action*/
			case  0:	sprintf(client_fifo_name , "/tmp/Client_%d" , getpid());
						mkfifo(client_fifo_name,0666);
						bank_request_fifo = open("/tmp/Request",O_WRONLY);
						if(bank_request_fifo == -1) {
							printf("Failed to open bank request fifo\n");
							unlink(client_fifo_name);
							exit(EXIT_FAILURE);
						}
						char pid_str[64];
						sprintf(pid_str,"%d",getpid());
						write(bank_request_fifo,pid_str,sizeof(pid_str));
						client_response_fifo = open(client_fifo_name,O_RDONLY);
						char bank_response[64];
						read(client_response_fifo, bank_response, sizeof(bank_response));
						if(strcmp(bank_response,"0") == 0){
							printf("Musteri %d parasini alamadi :(\n",getpid());
						}
						else{
							printf("Musteri %d %s lira aldi :)\n",getpid(),bank_response);

						}
						close(client_response_fifo);
						close(bank_request_fifo);
						unlink(client_fifo_name);
						exit(EXIT_SUCCESS);
						break;

			default:	client_pid_arr[i] = client_pid;
		}
	}
	for(i = 0 ; i < client_count ; i++){
		waitpid(client_pid_arr[i],&client_status,0);
	}

	free(client_pid_arr);
	return 0;
}
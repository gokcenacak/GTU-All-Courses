#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/file.h>

#define PATH_MAX 4096

typedef struct{
	int fd_source;
	int fd_destination;
	char pathname_source[PATH_MAX];
	char pathname_destination[PATH_MAX];
	char file_name[256];
} buffer_item;

buffer_item * buffer;
int buffer_size;
int counter;
pthread_mutex_t mutex;
sem_t full, empty;
int should_finish = 0;
int total_dirs_copied;
int total_bytes_copied;
int total_files_copied;
pthread_t * consumer_id;
int consumer_count;

void sig_handler(int signo){
    if(signo == SIGINT){
    	int i;
        printf("\n==Recieved SIGINT==\nWaiting for running copy operation to finish.\n");
        counter = 0;
        should_finish = 1;
        sem_post(&full);
		for(i=0; i<consumer_count; i++){
			pthread_join(consumer_id[i], NULL);
		}
		free(buffer);
		free(consumer_id); 
        exit(EXIT_SUCCESS);
    }
}
void *producer_thread(void * fn){
	char (*file_names)[256] = fn;
    DIR * dir_source;
    DIR * dir_dest;

	struct dirent * subdirent;
    struct stat filestat;
	char new_file_names[2][256];

    dir_source = opendir(file_names[0]);
	dir_dest = opendir(file_names[1]);
	total_dirs_copied++;

    if(dir_dest == NULL){
    	mkdir(file_names[1], 0777);
    }
    else{
    	closedir(dir_dest);
    }

	while((subdirent = readdir(dir_source)) != NULL){
        char pathname_source[PATH_MAX];
        strcpy(pathname_source,file_names[0]);
        strcat(pathname_source,"/");
        strcat(pathname_source,subdirent->d_name);
        lstat(pathname_source,&filestat);

      	char pathname_dest[PATH_MAX];
        strcpy(pathname_dest,file_names[1]);
        strcat(pathname_dest,"/");
        strcat(pathname_dest,subdirent->d_name);

        if(S_ISDIR(filestat.st_mode)){
            if(strcmp(subdirent->d_name,".") == 0 || strcmp(subdirent->d_name,"..") == 0)
                continue;
            strcpy(new_file_names[0],pathname_source);
            strcpy(new_file_names[1],pathname_dest);
            producer_thread(new_file_names);
        }
        else{   
        	buffer_item item;
        	strcpy(item.pathname_source,file_names[0]);
        	strcpy(item.pathname_destination,file_names[1]);
        	strcat(item.pathname_source,"/");
        	strcat(item.pathname_destination,"/");

            if(S_ISREG(filestat.st_mode)){
            	item.fd_source = open(pathname_source, O_RDONLY);
            	item.fd_destination = open(pathname_dest, O_CREAT | O_TRUNC | O_WRONLY,0666);
            	strcpy(item.file_name,subdirent->d_name);
            }
            else if(S_ISFIFO(filestat.st_mode)){
            	item.fd_source = -2;
            	item.fd_destination = -2;
            	strcpy(item.file_name,subdirent->d_name);
            }

            else if(S_ISLNK(filestat.st_mode)){
            	item.fd_source = -3;
            	item.fd_destination = -3;
            	strcpy(item.file_name,subdirent->d_name);
            }

            sem_wait(&empty);
			pthread_mutex_lock(&mutex);
        	if(counter < buffer_size){
        		buffer[counter] = item;
        		counter++;
        	}
			pthread_mutex_unlock(&mutex);
			sem_post(&full);
        }
    }
    closedir(dir_source);
}

void *consumer_thread(void * arg){
	buffer_item item;
	int i;
	while(counter > 0 || !should_finish){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		if(counter > 0) {
		    item = buffer[(counter-1)];
		    counter--;
		} 
		else {
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	    int count = 0;
	    if(item.fd_source > -1 && item.fd_destination > -1){
			char read_buf[256];
			int read_bytes;
			while((read_bytes = read(item.fd_source,read_buf,256)) > 0 ){
				int copied_bytes;
				copied_bytes = write(item.fd_destination,read_buf, 256);
				count += copied_bytes;
				total_bytes_copied += copied_bytes;
				for(i = 0; i < 256; i++) {
					read_buf[i] = 0;
				}
			}
			close(item.fd_source);
			close(item.fd_destination);
			printf("%10s\t\t%10s\t\t%10d\n", item.file_name, "REG", count);

		}
		/*If FIFO*/
		else if(item.fd_source == -2 && item.fd_destination == -2){
			char fifo_path[PATH_MAX];
			strcpy(fifo_path, item.pathname_destination);
			strcat(fifo_path, "/");
			strcat(fifo_path, item.file_name);
			mkfifo(fifo_path,0666);
			printf("%10s\t\t%10s\t\t%10d\n", item.file_name, "FIFO", 0);
		}
		/*If symlink*/
		else if(item.fd_source == -3 && item.fd_destination == -3){
			char full_link_pathname[PATH_MAX], link_point[PATH_MAX], full_link_point[PATH_MAX];
			char current_working_dir[PATH_MAX];
			getcwd(current_working_dir, sizeof(current_working_dir));
			strcpy(full_link_pathname,item.pathname_source);
			strcat(full_link_pathname,item.file_name);
			strcpy(full_link_point, current_working_dir);
			strcat(full_link_point, "/");
			strcat(full_link_point, item.pathname_destination);
			readlink(full_link_pathname,link_point,sizeof(link_point));
			strcat(full_link_point, link_point);
			strcpy(full_link_pathname,item.pathname_destination);
			strcat(full_link_pathname,item.file_name);
			symlink(full_link_point, full_link_pathname);
			printf("%10s\t\t%10s\t\t%10d\n", item.file_name, "LINK", 0);
		}
		total_files_copied++;
		
	}
	sem_post(&full);
}

int main(int argc, char const *argv[])
{
	char file_names[2][256];
	pthread_t producer_id;
	pthread_attr_t attr;
	struct timeval starting_time;
	struct timeval ending_time;

	if(signal(SIGINT,sig_handler) == SIG_ERR)
        exit(1);
	/*EXTRA: Check the validity of the arguments*/
	if(argc != 5){
		printf("Usage: pCp [number of consumers] [buffer size] [source directory] [destination directory]\n");
		exit(EXIT_FAILURE);
	}
	counter = 0;
	buffer_size = atoi(argv[2]);
	consumer_count = atoi(argv[1]);
	buffer = (buffer_item *) malloc(buffer_size*sizeof(buffer_item));
	consumer_id = (pthread_t *) malloc(atoi(argv[1])*sizeof(pthread_t));

	strcpy(file_names[0],argv[3]);
	strcpy(file_names[1],argv[4]);

	pthread_mutex_init(&mutex, NULL);
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, buffer_size);
	pthread_attr_init(&attr);

	gettimeofday(&starting_time, NULL);

	printf("      NAME\t\t      TYPE\t\t      SIZE\n");
	printf("==========================================================\n");

	pthread_create(&producer_id, &attr , producer_thread , file_names);
	
	int i;
	for(i=0;i<atoi(argv[1]) ; i++){
		pthread_create(&consumer_id[i],&attr,consumer_thread,NULL);
	}
	
	pthread_join(producer_id, NULL);

	should_finish = 1;

	sem_post(&full);

	for(i=0;i<atoi(argv[1]) ; i++){
		pthread_join(consumer_id[i], NULL);
	}
	
	gettimeofday(&ending_time, NULL);
	printf("Time Passed: %ld second(s)\n", (ending_time.tv_sec-starting_time.tv_sec));
	printf("Directories Copied: %d\n", total_dirs_copied);
	printf("Files Copied: %d\n", total_files_copied);
	printf("Bytes Copied: %d\n", total_bytes_copied);

	free(buffer);
	free(consumer_id);

	return 0;
}
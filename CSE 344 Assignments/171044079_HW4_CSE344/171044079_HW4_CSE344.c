#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>
#define PATH_MAX 4096
#define FIFO_NAME "171044079sizes"

int zArgCheck = 0;
int global_fifo;
void sig_handler(int signo){
    if(signo == SIGINT){
        printf("Recieved SIGINT");
        unlink(FIFO_NAME);
        exit(1);
    }
}
/*Traverses the tree, starting at path. It applies the pathfun
function to each file that it encounters in the traversal.
The function returns the sum of the positive return values
of pathfun or -1 if it failed to traverse any subdirectory*/
int postOrderApply(char * path , int pathfun (char * path1)){
    int total = 0;
    int temp = 0;
    int temp_fd; 
    DIR *dir;
    struct dirent * subdirent;
    struct stat filestat;
    int pipe_file_descr[2];
        char pid_size_path[PATH_MAX];
        char special_file[PATH_MAX];

    pid_t child_pid;
    int child_stat;
    /*Opening the directory by the given path, also error checking
    if the directory is opened or not*/
    if((dir = opendir(path)) == NULL){
        return -1;
    }

    /*Reading contents of the directory*/
    while((subdirent = readdir(dir)) != NULL){
        char pathname[PATH_MAX];
        char pipe_output[PATH_MAX];
        char * token;
        strcpy(pathname,path);
        strcat(pathname,"/");
        strcat(pathname,subdirent->d_name);
        lstat(pathname,&filestat);

        /*If the content is a directory, does the checks for .. and . (being itself or a higher directory)
        then recursively calls the functiion again so it can apply on to the current directory too. If -z 
        argument is used and there is no error in the recursive call, sums up all the return values by this function. */
        if(S_ISDIR(filestat.st_mode)){
        	if(pipe(pipe_file_descr) == -1){
        		printf("Error in creating pipe.\n");
        		exit(1);
        	}
          
            if(strcmp(subdirent->d_name,".") == 0 || strcmp(subdirent->d_name,"..") == 0)
                continue;
            switch(child_pid = fork()){
            	case -1 : fprintf(stderr, "Error while creating a new process\n");
            			  break;
            	case 0 : if(close(pipe_file_descr[0]) ==  -1){
            				printf("Error in closing the read end - child.\n");
        					exit(1);
            			 }
                        temp_fd = open("childCount.txt", O_RDWR | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
                        write(temp_fd,"+",1);
                        close(temp_fd);
            			temp = postOrderApply(pathname,pathfun);
            			sprintf(pid_size_path,"%d\t%d\t%s\n",getpid(),temp,pathname);
            			write(pipe_file_descr[1],pid_size_path,strlen(pid_size_path));
                        close(global_fifo);

                        
            			exit(EXIT_SUCCESS);
            			break;
			             
			    default: waitpid(child_pid,&child_stat,WUNTRACED);
			    		 if(close(pipe_file_descr[1]) ==  -1){
            				printf("Error in closing the write end - parent.\n");
        					exit(1);
            			 }
                         
            			 read(pipe_file_descr[0], pipe_output , sizeof(pipe_output));
            			 if(temp != -1 && zArgCheck == 1){
            			 	token = strtok(pipe_output,"\t");
		                	token = strtok(NULL,"\t");
		                	temp = atoi(token);
	 				        total += temp;

            			 }
                         
            			 break;
            }
            
        }
        /*If the content is not a directory, checks if its a regular file to add its size to the total size. If it is 
        not a regular file it prints out the name and the string "special file"*/
        else{   
            if(S_ISREG(filestat.st_mode)){
               temp = pathfun(pathname);
                if(temp != -1)
                    total += temp;
                
            }
            else if(S_ISBLK(filestat.st_mode) ||
                    S_ISCHR(filestat.st_mode) ||
                    S_ISFIFO(filestat.st_mode)||
                    S_ISLNK(filestat.st_mode)) {
                    if((global_fifo=open(FIFO_NAME,O_WRONLY)) == -1){
                        printf("Child cannot open fifo to write\n");
                        exit(1);
                    }
                    sprintf(special_file,"%d\t-1\tSpecial file %s\n", getpid(),subdirent->d_name);
                    write(global_fifo,special_file,strlen(special_file));
                }
        }
    }
    closedir(dir);
    /*Printing of the path and size*/
    if((global_fifo=open(FIFO_NAME,O_WRONLY)) == -1){
        printf("Child cannot open fifo to write\n");
        exit(1);
    }
    sprintf(pid_size_path,"%d\t%d\t%s\n",getpid(),total/1024, path);
    write(global_fifo,pid_size_path,strlen(pid_size_path));
    return total;
}

/*The function outputs path along with the other information
obtained by calling lstat for path. The function returns
the size in block of the file given by path or -1 if path does
not corresponds to an ordinary file.*/
int sizepathfun(char * path){
    struct stat filestat;
    int flag = lstat(path,&filestat);

    /*Getting the file contents with lstat and checking if lstat has an error*/
    if(flag == 0)
        return filestat.st_size;
    else
        return -1;

}

int main(int argc , char** argv) {
    /*Checking if the given argument count is between 1 and 4 (2 or 3 is acceptable), also
    checks if the 2nd argument is -z or not and prints out the proper usage if needed.*/
    pid_t child_pid;
    int glob_fi;
    int nbytes = 1;
    char line[4096];
    FILE * countfd;
    char * childCounter;
        size_t bufferSize = PATH_MAX;

    int childCount;
    if(signal(SIGINT,sig_handler) == SIG_ERR)
        exit(1);

    if (1 < argc && argc < 4){
        if(argc == 3 && strcmp(argv[1],"-z") != 0){
            fprintf(stderr, "Usage: buNeDuFPF -z rootpath\n");
            exit(1); 
        }
	}
    /*Printing the usage*/
    else{
        fprintf(stderr, "Usage: buNeDuFPF rootpath OR  buNeDuFPF -z rootpath\n");
        exit(1); 
    }

    if(mkfifo(FIFO_NAME,S_IRUSR|S_IWUSR) == -1){
        printf("Fifo failed.");
        exit(1);
    }
    
    /*Setting the z argument flag so postOrderApply can understand if there is z argument or not, and
    also calling the function with the argument at argv[2] since argv[1] is -z now.*/
    printf("PID\tSIZE\tPATH\n");
    
    switch(child_pid = fork()){
            case -1 : fprintf(stderr, "Error while creating a new process\n");
                break;
            case 0:
                    if((strcmp(argv[1],"-z") == 0) && argc == 3){
                        zArgCheck = 1;
                        postOrderApply(argv[2],sizepathfun);
                    } else {
                        postOrderApply(argv[1],sizepathfun);
                    }
                  break;
            default:
                glob_fi = open(FIFO_NAME, O_RDONLY);
                while(nbytes > 0)  {
                    nbytes = (read(glob_fi, line, 4096));
                    printf("%s\n", line);
                    strcpy(line, "\0");
                    sleep(1);
                }
                unlink(FIFO_NAME);
                close(glob_fi);
                countfd = fopen("childCount.txt", "rt");
                childCount = getline(&childCounter, &bufferSize ,countfd);
                printf("%d child processes created. Main process is %d\n" , (int)(childCount + 1), getpid());
                remove("childCount.txt");
                break;
    }
    return 0;
}


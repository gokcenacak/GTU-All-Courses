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
int zArgCheck = 0;
/*Traverses the tree, starting at path. It applies the pathfun
function to each file that it encounters in the traversal.
The function returns the sum of the positive return values
of pathfun or -1 if it failed to traverse any subdirectory*/
int postOrderApply(char * path , int pathfun (char * path1)){
    int total = 0;
    int temp = 0;
    DIR *dir;
    struct dirent * subdirent;
    struct stat filestat;
    int fd = open("171044079sizes.txt", O_RDWR | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    int tempfile = open("childCount.txt", O_RDWR | O_CREAT | O_APPEND , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	char dirpath[PATH_MAX];
 	char pathname[PATH_MAX];
    char tempstr[PATH_MAX];
    strcpy(dirpath, path);

    /*File opening checks*/
    if(fd==-1){
    	fprintf(stderr, "An error has occured while opening the file.\n");
    	exit(1);
    }
    if(tempfile==-1){
    	exit(1);
    }
 	
 
    /*Opening the directory by the given path, also error checking
    if the directory is opened or not*/
    if((dir = opendir(path)) == NULL){
        return -1;
    }
   
    /*Reading contents of the directory*/
    while((subdirent = readdir(dir)) != NULL){
        pid_t child_pid;
        int child_stat;
        strcpy(pathname,path);
        strcat(pathname,"/");
        strcat(pathname,subdirent->d_name);
        lstat(pathname,&filestat);

        /*If the content is a directory, does the checks for .. and . (being itself or a higher directory)
        then it creates a child process to check the inner directories*/
        if(S_ISDIR(filestat.st_mode)){

           if(strcmp(subdirent->d_name,".") == 0 || strcmp(subdirent->d_name,"..") == 0)
                continue;
           
           switch(child_pid = fork()){
               /*Child process action*/
               case 0 : 
                        total = 0;
                        strcpy(dirpath, pathname);
                        closedir(dir);
                        strcpy(path,pathname);
                        dir = opendir(pathname);
                        break;
                /*Process creation fail*/
               case -1 : fprintf(stderr, "Error while creating a new process.\n");
                         break;
               /*Parent process action*/
               default :
                        waitpid(child_pid , &child_stat , WUNTRACED); 
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
                    S_ISLNK(filestat.st_mode)){
            	    
				 	sprintf(tempstr,"%d\t \tSpecial file %s\n", getpid() , subdirent->d_name);
				    flock(fd,LOCK_EX);
				    write(fd, tempstr,strlen(tempstr));
				    flock(fd,LOCK_UN);
            }
        }
    }
    closedir(dir);
    /*Writing the path and the size and the PID to the file. File locking is provided.*/
    sprintf(tempstr,"%d\t%d\t%s\n" , getpid() , total/1024 , dirpath );
    flock(fd,LOCK_EX);
    write(fd, tempstr,strlen(tempstr));
    flock(fd,LOCK_UN);
    flock(tempfile,LOCK_EX);
    write(tempfile,"+",1);
    flock(fd,LOCK_UN);
    close(fd);
    close(tempfile);
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
    pid_t child_pid;
    int child_stat; 
    int directorySize;
	int i,j,k,x,pidNo;
	int slashIndex = -1;  
	char tempstr[PATH_MAX];
    char tempstr2[PATH_MAX];
    int * sizeArray = NULL;  
    char * childCounter = NULL;
    char * currentChar = NULL;
	char * tempDirPar = NULL;
    char * processSize = NULL;
    char * token = NULL;
	char * completePath = NULL;
	char ** pathArray = NULL;
    char ** dashZFileContent = NULL;
 	size_t bufferSize = PATH_MAX;
    size_t childCount = 0 ;

    int fd = open("171044079sizes.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    int tempfile = open("childCount.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    FILE* f_ptr = fopen("childCount.txt", "rt");
    FILE* f_ptr2;

    /*File opening checks*/
    if(fd==-1){
    	fprintf(stderr, "An error has occured while opening the file.\n");
    	exit(1);
    }
    if(tempfile==-1){
    	exit(1);
    }

    if(f_ptr == NULL){
    	exit(1);
    }
  

    /*Checking if the given argument count is between 1 and 4 (2 or 3 is acceptable), also
    checks if the 2nd argument is -z or not and prints out the proper usage if needed.*/
    if (1 < argc && argc < 4){
        if(argc == 3 && strcmp(argv[1],"-z") != 0){
            fprintf(stderr, "Usage: buNeDuFork -z rootpath\n");
            exit(1); 
        }
	}
    /*Printing the usage*/
    else{
        fprintf(stderr, "Usage: buNeDuFork rootpath OR  buNeDu -z rootpath\n");
        exit(1); 
    }
    /*Setting the z argument flag so postOrderApply can understand if there is z argument or not, and
    also calling the function with the argument at argv[2] since argv[1] is -z now. For the function 
    call a new process is created.*/
    if((strcmp(argv[1],"-z") == 0) && argc == 3){
        zArgCheck = 1;
        switch(child_pid = fork()){
        	/*Child process action*/
            case 0 : 
                    postOrderApply(argv[2],sizepathfun);
                    close(fd);
				    fclose(f_ptr);
				    close(tempfile);
                    exit(EXIT_SUCCESS);
                    break;
            /*Process creation failure*/
            case -1:
                    fprintf(stderr, "Error while creating a new process.\n");
                    break;
            /*Parent process action*/        
            default:
                    waitpid(child_pid , &child_stat , WUNTRACED); 
                    close(fd);

	                f_ptr2 = fopen("171044079sizes.txt","r");
	             	pathArray = malloc(20000 * sizeof(char *));

	             	for(i = 0 ; i < 20000 ; ++i){
	             		pathArray[i] = malloc(PATH_MAX * sizeof(char));
	             	}

	             	sizeArray = malloc(20000 * sizeof(int));
	             	x = 0;
	             	/*Creating two parallel arrays pathArray and sizeArray to keep the path strings and their sizes. */
	                while(fgets(tempstr,PATH_MAX,f_ptr2)!=NULL){
	                	token = strtok(tempstr,"\t");
	                	token = strtok(NULL,"\t");
	                	directorySize = atoi(token);
	                	if(strcmp(token," ") != 0){
	                		token = strtok(NULL,"\n");
	                		if(token!=NULL)
	                			strcpy(pathArray[x],token);
	                		sizeArray[x] = directorySize;
	                		x++;
	                	}
	                }
	                /*Checking if the directory path has a parent directory, adding the sizes using the sizeArray values*/
	                for(i = 0 ; i < x ; ++i){
	                	tempDirPar = malloc(PATH_MAX * sizeof(char));
	                	slashIndex = -1;
	                	for(j = 0 ; j < strlen(pathArray[i]) ; ++j){

	                		if(pathArray[i][j] =='/'){
	                			slashIndex = j;
	                		}
	                	}
	                	if(slashIndex >= 0){
	                		strcpy(tempDirPar,pathArray[i]);
	                		tempDirPar[slashIndex]='\0';
							for(j = 0 ; j < x ; ++j){
								if(tempDirPar!=NULL){
									if(strcmp(tempDirPar,pathArray[j]) == 0){
										sizeArray[j] += sizeArray[i];
									}
								}
							}

	                	}
		                free(tempDirPar);
	                }

 	                fclose(f_ptr2);
				    f_ptr2 = fopen("171044079sizes.txt", "rt");

				    k=0;

				    /*Creating a new string array to keep the new file content*/	
				    dashZFileContent = malloc(20000 * sizeof(char *));

	             	for(i =0 ; i < 20000 ; ++i){
	             		dashZFileContent[i] = malloc(PATH_MAX * sizeof(char));
	             		dashZFileContent[i][0] = '\0';
	             	}

				    while(fgets(tempstr,bufferSize,f_ptr2) != NULL){
				    	pidNo = atoi(strtok(tempstr,"\t"));
				    	processSize = strtok(NULL,"\t");
				    	completePath = strtok(NULL ,"\n");
				    	
				    	if(strcmp(processSize," ") != 0){
				    		for(i=0;i<x;i++){
				    			if(strcmp(pathArray[i],completePath) == 0){
    								sprintf(tempstr2,"%d\t%d\t%s\n" , pidNo , sizeArray[i] , completePath);
    								if(tempstr2!=NULL){
    									strcpy(dashZFileContent[k],tempstr2);
    									k++;
    								}
    									
				    			}
				    		}
				    	}
				    	else{
		    				sprintf(tempstr2,"%d\t%s\t%s\n" , pidNo , processSize , completePath);
							strcpy(dashZFileContent[k],tempstr2);
		    				k++;
				    	}
				    }

	                fclose(f_ptr2);

	                f_ptr2 = fopen("171044079sizes.txt", "rt");
	                fd = open("171044079sizes.txt", O_RDWR | O_CREAT | O_APPEND | O_TRUNC , S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
	                /*Writing the new file content to the file for the -z argument*/
	                for(i = 0 ; i <= k ; i++){
	                	flock(fd,LOCK_EX);
	                	if(dashZFileContent[i]!=NULL)
							write(fd, dashZFileContent[i],strlen(dashZFileContent[i]));
						flock(fd,LOCK_UN);
	                }
	                free(sizeArray);

	                for(i = 0 ; i < 20000 ; i++){
	                	currentChar = pathArray[i];
	                	free(currentChar);
	                }
	                free(pathArray);

	                 for(i = 0 ; i < 20000 ; i++){
	                	currentChar = dashZFileContent[i];
	                	free(currentChar);
	                }
	                free(dashZFileContent);

	                fclose(f_ptr2);
        }
    }
    else{
         switch(child_pid = fork()){
            case 0 : 
                    postOrderApply(argv[1],sizepathfun);
                    close(fd);
				    fclose(f_ptr);
				    close(tempfile);
                    exit(EXIT_SUCCESS);
                    break;
            case -1:
                    fprintf(stderr, "Error while creating a new process.\n");
                    break;
            default:
                    waitpid(child_pid , &child_stat , WUNTRACED); 
        }
    }
    /*Each child puts a + to a hidden file to calculate the total child size*/
    flock(tempfile,LOCK_EX);
    write(tempfile,"+",1);
    flock(tempfile,LOCK_UN);
    close(tempfile);
    childCount = getline(&childCounter, &bufferSize ,f_ptr);

    close(fd);

    fd = open("171044079sizes.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    f_ptr2 = fopen("171044079sizes.txt", "r");

    /*Printing the complete file input*/
    printf("PID\tSIZE\tPATH\n");
    while(fgets(tempstr,bufferSize,f_ptr2) != NULL){
    	printf("%s", tempstr);
    }
    close(fd);
    fclose(f_ptr2);
   	fd = open("171044079sizes.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);

    printf("%d child processes created. Main process is %d\n" , (int)(childCount - 1), getpid());
   
   
    close(fd);

    fclose(f_ptr);
    close(tempfile);
    free(childCounter);
    remove("childCount.txt");
    return 0;
}
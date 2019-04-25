#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PATH_MAX 4096
int main(int argc , char ** argv){
    DIR *dir;
    struct dirent * subdirent;
    struct stat filestat;
    char cwd[PATH_MAX];
    
    getcwd(cwd,sizeof(cwd));

    if((dir = opendir(cwd)) == NULL){
        return -1;
    }

    while((subdirent = readdir(dir)) != NULL){
        char pathname[PATH_MAX];
        strcpy(pathname,cwd);
        strcat(pathname,"/");
        strcat(pathname,subdirent->d_name);
        lstat(pathname,&filestat);
        if(!S_ISDIR(filestat.st_mode)){
        	if(S_ISREG(filestat.st_mode)){
				printf("R ");            
	        }
	        else if(S_ISBLK(filestat.st_mode) ||
	                S_ISCHR(filestat.st_mode) ||
	                S_ISFIFO(filestat.st_mode)||
	                S_ISLNK(filestat.st_mode))
	            printf("S ");

	        if(S_IRUSR & filestat.st_mode) printf("r");
	        else printf("-");

    	    if(S_IWUSR & filestat.st_mode) printf("w");
	        else printf("-");

	        if(S_IXUSR & filestat.st_mode) printf("x"); 
	        else printf("-");

	        if(S_IRGRP & filestat.st_mode) printf("r");
	        else printf("-");

    	    if(S_IWGRP & filestat.st_mode) printf("w");
	        else printf("-");

	        if(S_IXGRP & filestat.st_mode) printf("x");
	        else printf("-");

	        if(S_IROTH & filestat.st_mode) printf("r");
	        else printf("-");

    	    if(S_IWOTH & filestat.st_mode) printf("w");
	        else printf("-");

	        if(S_IXOTH & filestat.st_mode) printf("x");   
	        else printf("-");

          

	        printf(" %d %s\n", (int)filestat.st_size , subdirent->d_name);
        }
       
    }
    closedir(dir);
	return 0;	
}
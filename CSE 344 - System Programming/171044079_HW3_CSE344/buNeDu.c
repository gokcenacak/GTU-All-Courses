#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PATH_MAX 4096
int zArgCheck = 0;

int postOrderApply(char * path , int pathfun (char * path1)){
    int total = 0;
    int temp;
    DIR *dir;
    struct dirent * subdirent;
    struct stat filestat;

   
    if((dir = opendir(path)) == NULL){
        return -1;
    }

    
    while((subdirent = readdir(dir)) != NULL){
        char pathname[PATH_MAX];
        strcpy(pathname,path);
        strcat(pathname,"/");
        strcat(pathname,subdirent->d_name);
        lstat(pathname,&filestat);

  
        if(S_ISDIR(filestat.st_mode)){
            if(strcmp(subdirent->d_name,".") == 0 || strcmp(subdirent->d_name,"..") == 0)
                continue;
            temp = postOrderApply(pathname,pathfun);
            if(temp != -1 && zArgCheck == 1)
                total += temp;
        }
        
        else{   
            if(S_ISREG(filestat.st_mode)){
               temp = pathfun(pathname);
                if(temp != -1)
                    total += temp;
                
            }
            else if(S_ISBLK(filestat.st_mode) ||
                    S_ISCHR(filestat.st_mode) ||
                    S_ISFIFO(filestat.st_mode)||
                    S_ISLNK(filestat.st_mode))
                fprintf(stdout,"Special file %s\n", subdirent->d_name);
        }
    }
    closedir(dir);
    printf("%d %s\n" ,total/1024 , path);
    return total;
}


int sizepathfun(char * path){
    struct stat filestat;
    int flag = lstat(path,&filestat);

    if(flag == 0)
        return filestat.st_size;
    else
        return -1;

}

int main(int argc , char** argv) {
    char path[PATH_MAX];
   
    if(argc > 3) {
        fprintf(stderr, "Usage: bunedu -z rootpath\n");
        exit(1); 
    }
    else if(argc == 3 && strcmp(argv[1],"-z") != 0){
        fprintf(stderr, "Usage: bunedu -z rootpath\n");
        exit(1); 
    }
	if(argc == 1){
        scanf("%s",path);
        postOrderApply(path,sizepathfun);
    }
    else if(argc == 2 && strcmp(argv[1], "-z") == 0){
        scanf("%s",path);
        zArgCheck = 1;
        postOrderApply(path,sizepathfun);

    } else if(argc == 2 && strcmp(argv[1], "-z") != 0) {
        postOrderApply(argv[1],sizepathfun);
    } else if(argc == 3){
        zArgCheck = 1;
        postOrderApply(argv[2],sizepathfun);
    }
    return 0;
}



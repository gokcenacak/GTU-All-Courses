#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#define PATH_MAX 4096
int zArgCheck = 0;
/*Traverses the tree, starting at path. It applies the pathfun
function to each file that it encounters in the traversal.
The function returns the sum of the positive return values
of pathfun or -1 if it failed to traverse any subdirectory*/
int postOrderApply(char * path , int pathfun (char * path1)){
    int total = 0;
    int temp;
    DIR *dir;
    struct dirent * subdirent;
    struct stat filestat;

    /*Opening the directory by the given path, also error checking
    if the directory is opened or not*/
    if((dir = opendir(path)) == NULL){
        return -1;
    }

    /*Reading contents of the directory*/
    while((subdirent = readdir(dir)) != NULL){
        char pathname[PATH_MAX];
        strcpy(pathname,path);
        strcat(pathname,"/");
        strcat(pathname,subdirent->d_name);
        lstat(pathname,&filestat);

        /*If the content is a directory, does the checks for .. and . (being itself or a higher directory)
        then recursively calls the functiion again so it can apply on to the current directory too. If -z 
        argument is used and there is no error in the recursive call, sums up all the return values by this function. */
        if(S_ISDIR(filestat.st_mode)){
            if(strcmp(subdirent->d_name,".") == 0 || strcmp(subdirent->d_name,"..") == 0)
                continue;
            temp = postOrderApply(pathname,pathfun);
            if(temp != -1 && zArgCheck == 1)
                total += temp;
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
                    S_ISLNK(filestat.st_mode))
                fprintf(stdout,"Special file %s\n", subdirent->d_name);
        }
    }
    closedir(dir);
    /*Printing of the path and size*/
    printf("%d %s\n" ,total/1024 , path);
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
    if (1 < argc && argc < 4){
        if(argc == 3 && strcmp(argv[1],"-z") != 0){
            fprintf(stderr, "Usage: buNeDu -z rootpath\n");
            exit(1); 
        }
	}
    /*Printing the usage*/
    else{
        fprintf(stderr, "Usage: buNeDu rootpath OR  buNeDu -z rootpath\n");
        exit(1); 
    }
    /*Setting the z argument flag so postOrderApply can understand if there is z argument or not, and
    also calling the function with the argument at argv[2] since argv[1] is -z now.*/
    if((strcmp(argv[1],"-z") == 0) && argc == 3){
        zArgCheck = 1;
        postOrderApply(argv[2],sizepathfun);
    }
    else{
        postOrderApply(argv[1],sizepathfun);
    }
 
    return 0;
}



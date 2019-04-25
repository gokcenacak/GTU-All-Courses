#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_LENGTH 8192

int main(int argc , char ** argv){
	char cwd[MAX_LENGTH];
	getcwd(cwd,sizeof(cwd));
	printf("%s\n",cwd);
	return 0;
}
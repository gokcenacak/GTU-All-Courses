#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 8192

int main(int argc , char ** argv){
	char str[MAX_LENGTH];
	FILE * file;

	if(argc > 2) {
		printf("Usage : cat OR cat [filename]\n");
		exit(EXIT_FAILURE);
	}
	
	if(argc == 1) {
		while(fgets(str,MAX_LENGTH,stdin)!=NULL){
			printf("%s",str);
		}
	}
	else{
		file = fopen(argv[1],"r");
		if(file == NULL) {
			fprintf(stderr, "%s %s\n", "Can not open file.", argv[1]);
			exit(EXIT_FAILURE);
		}
		while(fgets(str,MAX_LENGTH,file)!=NULL){
			printf("%s",str);
		}
		fclose(file);
	}
	return 0;
}
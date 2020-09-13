#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 8192

int main(int argc , char ** argv){
	char str[MAX_LENGTH];
	FILE * file;
	int line_count = 0;
	if(argc > 2) {
		printf("Usage : wc OR wc [filename]\n");
		exit(EXIT_FAILURE);
	}
	
	if(argc == 1) {
		while(fgets(str,MAX_LENGTH,stdin)!=NULL){
			line_count++;
		}
	}
	else{
		file = fopen(argv[1],"r");
		if(file == NULL) {
			fprintf(stderr, "%s %s\n", "Can not open file.", argv[1]);
			exit(EXIT_FAILURE);
		}
		while(fgets(str,MAX_LENGTH,file)!=NULL){
			line_count++;
		}
		fclose(file);
	}
	printf("%d\n", line_count );
	return 0;
}
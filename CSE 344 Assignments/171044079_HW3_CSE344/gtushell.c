#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_LENGTH 8192

int validate_command(char * command);
int is_directory(char * path);

void sig_handler(int signo){
    if(signo == SIGTERM){
        printf("Recieved SIGTERM\n");
        exit(1);
    }
}
int tokenize(char* str, char** tokens) {
	int token_count = 0;
	const char s[2] = " ";
	char *token;

	if (strlen(str) == 0) {
		return 0;
	}

	token = strtok(str, s);

	while(token != NULL) {
		tokens[token_count] = (char *) malloc (MAX_LENGTH * sizeof(char));
		strcpy(tokens[token_count], token);
		token_count++;
		token = strtok(NULL, s);
	}

	return token_count;
}

void clear_tokens(int token_count, char** tokens) {
	int i;
	for (i = 0; i < token_count; i++) {
		free(tokens[i]);
	}
	for (i = 0; i < MAX_LENGTH; i++)
		tokens[i] = NULL;
}

int input_redirection_exists(char ** tokens, int token_count){
	int i;
	int res = 0;
	for(i=0;i<token_count;i++){
		if(strcmp(tokens[i],"<") == 0)
			res = 1;
	}
	return res;
}
int output_redirection_exists(char ** tokens, int token_count){
	int i;
	int res = 0;
	for(i=0;i<token_count;i++){
		if(strcmp(tokens[i],">") == 0)
			res = 1;
	}
	return res;
}
int pipe_exists(char ** tokens, int token_count){
	int i;
	int res = 0;
	for(i=0;i<token_count;i++){
		if(strcmp(tokens[i],"|") == 0)
			res = 1;
	}
	return res;
}


int main(int argc , char ** argv){
	char * str;
	pid_t child_pid;
	int child_status;
	char cwd[MAX_LENGTH];
	char exe_directory[MAX_LENGTH];
	int i, n,j;
	int command_history_index = 0;
	char command_history[512][128];
	char *tokens[MAX_LENGTH];
	char *first_exec[MAX_LENGTH];
	char *second_exec[MAX_LENGTH];

	int token_count = 0;
	int file_desr;
	int temp;

	setbuf(stdout, 0);

	str = (char *) malloc (MAX_LENGTH * sizeof(char));

	if(signal(SIGTERM,sig_handler) == SIG_ERR)
        exit(1);

	getcwd(exe_directory,sizeof(exe_directory));
	while(1){
		char strcopy[MAX_LENGTH];
		getcwd(cwd,sizeof(cwd));
		printf("gtushell:~%s:~",cwd);
		fgets(str,MAX_LENGTH,stdin);
		str[strlen(str)-1]='\0';
		strcpy(strcopy, str);

		token_count = tokenize(str, tokens);
		if(token_count == 0){
			printf("There is no command to execute, exiting... \n");
			exit(-1);
		}

		strcat(exe_directory,"/");
		strcat(exe_directory, tokens[0]);
		if(str[0] != '!') {
			strcpy(command_history[command_history_index], strcopy);
			command_history_index++;
		} 
		if(str[0] == '!'){
			n = atoi(&str[1]);
			strcpy(str, command_history[command_history_index - n]);
			strcpy(command_history[command_history_index], str);
			command_history_index++;
			clear_tokens(token_count, tokens);
			token_count = tokenize(str, tokens);

			for(i = strlen(exe_directory) - 1 ; i>=0 ; --i ){
			 	if(exe_directory[i] == '/'){
			 		exe_directory[i] = '\0';
			 		break;
			 	}
			}
			strcat(exe_directory,"/");
			strcat(exe_directory,tokens[0]);
		}
		if(validate_command(tokens[0]) == 0){
			printf("%s : invalid command\n", tokens[0]);
		}
		else if(strcmp(tokens[0],"exit") == 0){
			free(str);
			clear_tokens(token_count, tokens);
			exit(1);
		}
		else if(strcmp(tokens[0],"cd") == 0 && token_count == 2){
			if(is_directory(tokens[1])){
				getcwd(cwd,sizeof(cwd));
				strcat(cwd,"/");
				strcat(cwd,tokens[1]);
				chdir(cwd);
			}
			else{
				printf("This path is not a directory.\n");
			}
		}
		else if(strcmp(tokens[0],"help") == 0){
			printf("	lsf : Lists file attributes.\n");
			printf("	pwd : Prints the path of the current working directory.\n");
			printf("	cd [directoryname] : Changes the current working directory\n");
			printf("	help : Shows the available commands\n");
			printf("	cat [filename] : Prints the given file contents.\n");
			printf("	wc [filename] : Prints the number of lines in  the given file.\n");
			printf("	bunedu [directoryname] - buNeDu -z [directoryname] : Prints the disk usage for the given directory.\n");
			printf("	exit : Exits the shell.\n");

		}
		else{
			if(pipe_exists(tokens,token_count) == 0) {
				switch(child_pid = fork()){
					case -1 : printf("An error has occured during the creation of the child process\n");
							  exit(-1);

					case 0 :if(input_redirection_exists(tokens,token_count) == 1){
								for(i=0;i<token_count;i++){
									if(strcmp(tokens[i],"<") == 0){
										temp = i;
									}
								}
								file_desr = open(tokens[temp+1],O_RDONLY);
								dup2(file_desr,STDIN_FILENO);

								tokens[temp] = NULL;
								tokens[temp+1]= NULL;
							}

							else if(output_redirection_exists(tokens,token_count) == 1){
								for(i=0;i<token_count;i++){
									if(strcmp(tokens[i],">") == 0){
										temp = i;
									}
								}
								file_desr = open(tokens[temp+1],O_WRONLY|O_CREAT|O_TRUNC,0666);

								dup2(file_desr,STDOUT_FILENO);

								tokens[temp] = NULL;
								tokens[temp+1]= NULL;

							}

							execv(exe_directory, tokens);
							exit(EXIT_FAILURE);

					default: waitpid(child_pid,&child_status,0);
				}
			}
			else {
				int fec = 0, sec = 0;
				for(i=0;strcmp(tokens[i],"|") != 0;i++){
					first_exec[fec] = (char *)malloc(MAX_LENGTH * sizeof(char));
					strcpy(first_exec[fec],tokens[i]);
					fec++;
				}
				for(j=i+1;j<token_count;j++){
					second_exec[sec] = (char *)malloc(MAX_LENGTH * sizeof(char));
					strcpy(second_exec[sec],tokens[j]);
					sec++;
				}

				int pipe_fd[2];
				pipe(pipe_fd);

				pid_t first_child_pid;
				int first_child_status;
				switch(first_child_pid = fork()) {
					case -1 : printf("An error has occured during the creation of the child process\n");
							  exit(-1);

					case 0 :
							close(pipe_fd[0]);
							dup2(pipe_fd[1], STDOUT_FILENO);
							close(pipe_fd[1]);

							execv(first_exec[0], first_exec);
							exit(EXIT_FAILURE);

					default: break;
				}

				pid_t second_child_pid;
				int second_child_status;
				switch(second_child_pid = fork()) {
					case -1 : printf("An error has occured during the creation of the child process\n");
							  exit(-1);

					case 0 :
							close(pipe_fd[1]);
							dup2(pipe_fd[0], STDIN_FILENO);
							close(pipe_fd[0]);

							execv(second_exec[0], second_exec);
							exit(EXIT_FAILURE);

					default: break;
				}

				close(pipe_fd[0]);
				close(pipe_fd[1]);

				waitpid(first_child_pid,&first_child_status,0);
				waitpid(second_child_pid,&second_child_status,0);

				clear_tokens(fec, first_exec);
				clear_tokens(sec, second_exec);
			}
		}
		for(i = strlen(exe_directory) - 1 ; i>=0 ; --i ){
		 	if(exe_directory[i] == '/'){
		 		exe_directory[i] = '\0';
		 		break;
		 	}
		}

		clear_tokens(token_count, tokens);
		strcpy(str, "");
	}
	return 0;
}

int validate_command(char * command){
	char commands[10][10] = {"lsf","pwd","cd","help","cat","wc","exit","bunedu"};
	int result = 0;
	int i;
	for(i = 0 ; i < 8 ; i++){
		if(strcmp(commands[i],command) == 0){
			result = 1;
		}
	}

	return result;

}

int is_directory(char * path){
	struct stat path_status;
	lstat(path,&path_status);
	return S_ISDIR(path_status.st_mode);
}
#include <stdio.h>
void encrypt_open_msg();
int find_size_of_line(char line[]);
void reverse_line(char line[],int line_length);
void decrypt_secret_msg();
/*Menu makes user choose an option and either encrypts a message, decrypts 
message or exits when 0 is entered. At all other scenerios menu keeps getting
printed on the screen.*/
void menu(){
	int choice;

	do{
	printf("----------\n1.Encrypt\n2.Decrypt\n0.Exit\n----------\n");
	scanf("%d",&choice);
		switch(choice){
			case 1:	encrypt_open_msg();
					break;
			case 2: decrypt_secret_msg();
					break;
			default:
					break;
		}
	}while(choice!=0);
}
/*Reads lines from a file and reverses them and encrypts the line according to 
a key that user entered*/
void encrypt_open_msg(){
	int i,j,k,l,flag;
	FILE * fin;
	FILE * fout;
	char str[1024];
	int ch,key;
	char alpha['z'-'a'+1];
		/*The array of the alphabet*/
		for(k=0;'a' + k <= 'z';k++){
			alpha[k]='a'+k;
		}
	/*Opening files*/
	fin=fopen("open_msg.txt","r");
	fout=fopen("secret_msg.txt","w");
	do{
	printf("Key:");
	scanf("%d",&key);
	}while(!(key>=1 && key<=26));
	
	while(fgets(str,1024,fin)){
		/*To make sure that no extra newlines are printed.*/
		for(l=0;l<find_size_of_line(str);l++){
			if(str[l]=='\r' || str[l]=='\n'){
				str[l]=0;
			}
		}
		/*Printing the original line*/
		printf("%s\n",str);
		/*Reversing the line*/
		reverse_line(str,find_size_of_line(str));
		/*Checks if the element is ., space or lowercase characters if it is 
		lowercase letters it replaces the letter with a corresponding letter
		which is in the reverse direction according to key*/
		for(i=0;str[i]!='\0';i++){
			if(str[i]=='.'){
				str[i]='*';
			}
			else if(str[i]==' '){
				str[i]='_';
			}
			else if(str[i]>='a' && str[i]<='z'){
				flag=0;
				for(j=0;(alpha[j]!='\0'&&flag==0);j++){
					if(str[i]==alpha[j]){
						if(j-key<0){
							str[i]=alpha[j-key+26];
							
						}
						else{
							str[i]=alpha[(j-key)];	
						}
						flag=1;
					}
				}
			}
		}
		/*Prints the new created line to screen,and writes the new created line
		to the file*/
		printf("%s\n",str);
		fprintf(fout, "%s\n", str);
	}
	fclose(fin);
	fclose(fout);
}

void decrypt_secret_msg(){
	int i,j,k,l,flag;
	int tmp;
	FILE * fin;
	FILE * fout;
	char str[1024];
	char alpha['z'-'a'+1];
	/*The array of the alphabet*/
	for(k=0;'a' + k <= 'z';k++){
		alpha[k]='a'+k;
	}
	int ch,key;
	/*Opening files*/
	fin=fopen("secret_msg.txt","r");
	fout=fopen("open_msg.txt","w");
	do{
	printf("Key:");
	scanf("%d",&key);
	}while(!(key>=1 && key<=26));

	while(fgets(str,1024,fin)){
		/*To make sure that no extra newlines are printed.*/
		for(l=0;l<find_size_of_line(str);l++){
			if(str[l]=='\r' || str[l]=='\n'){
				str[l]=0;
			}
		}
		/*Printing the original line*/
		printf("%s\n",str);
		/*Reversing the line*/
		reverse_line(str,find_size_of_line(str));
		/*Checks if the element is ., space or lowercase characters if it is 
		lowercase letters it replaces the letter with a corresponding letter
		which is like the reverse of the encryption process.*/
		for(i=0;str[i]!='\0';i++){
			
			if(str[i]=='*'){
				str[i]='.';
			}
			else if(str[i]=='_'){
				str[i]=' ';
			}
			else if(str[i]>='a' && str[i]<='z'){
				flag=0;
				for(j=0;alpha[j]!='\0'&&flag==0;j++){
					if(str[i]==alpha[j]){
						if(j+key>25)
							str[i]=alpha[j+key-26];
						else {
							str[i]=alpha[(j+key)];
						}
					flag=1;
					}
				}
			}
		
		}
		printf("%s\n",str);
		fprintf(fout,"%s\n",str);
	}
	fclose(fin);
	fclose(fout);
}
/*Finding the size of the line*/
int find_size_of_line(char line[]){
	int i;
		for(i=0;line[i]!='\0';i++);
	
	return i;
}
/*Reversing the line*/
void reverse_line(char line[],int line_length){
	int i,j;
	char ch;
	i=0;
	j=line_length-1;
	while(i<j){
			ch=line[i];
			line[i]=line[j];
			line[j]=ch;
			i++;
			j--;
	}
}
int main(){
	menu();
return 0;
}

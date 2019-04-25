/*Homework 10
	To Do List
	-Create a linked list +
	-Create a dynamic allocated array +
	-Write a function that gets a line from the file.+
	-Write a function that calculates whether a given number is prime or not +
	-Write a function that records the prime numbers in the linked list +
	-Write a function that records the prime numbers in the dynamic alloc.array +
	-Compare the calculation time for linked list and array
		*between 1-500.000
		*between 1-750.000
		*between 1-1.000.000
	-Write the results to output_prime_LinkedList.txt and output_prime_dynamic_array.txt
	-Calculate writing time for both txt files for data between 1-1.000.000
*/
	
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
typedef struct node_s{
	int num;
	struct node_s *linkp;
}node_t;

/*Question 1*/
int get_line(FILE *f){
	int res;
	char *str;
	int c;
	int i=0;
	str=(char*)calloc(10,sizeof(char));
	
	while((c=fgetc(f))!='\n' && c!=EOF){
			str[i]=c;
			i++;
	}
	sscanf(str,"%d",&res);

	return res;	
}
/*Question 2*/
int isPrime(int num){
	int i,res=1;

	for(i=2;i<=num/2;i++){
		if(num%i==0){
			return 0;
		}
	}
	if(num==1){
		return 0;
	}
	else 
		return 1;
}
/*Question 2.a and 3 for 2.a together in this function*/
/*Recording all numbers in to the linked list and printing only the values which
are prime. This function also calculates the calculation time between 
1-500.000 , 1-750.000 and 1-1.000.000 and writes it to output_prime_linked_list.txt
*/
void record_to_linked_list(FILE *f,node_t *head){
	FILE *list_file;
	struct timeval start, end500000,end750000,end1000000;
	double time_int1,time_int2,time_int3;
	int i;
	node_t *current;

	list_file=fopen("output_prime_linked_list.txt","w");

    gettimeofday(&start, NULL);

	if(head==NULL){
		head->num=get_line(f);
		head->linkp=NULL;
			if(isPrime(current->num)==1){
				printf("%d\n",current->num);
				fprintf(list_file,"%d\n",current->num);
			}
	}

	current=head;

	for(i=0;i<1000000;i++){
		current->linkp=(node_t*)malloc(sizeof(node_t));
		current=current->linkp;
		current->num=get_line(f);

		if(isPrime(current->num)==1){
			printf("%d\n",current->num);
			fprintf(list_file,"%d\n",current->num);
		}
		if(i==500000-1){
			gettimeofday(&end500000, NULL);
			time_int1=(end500000.tv_sec-start.tv_sec)*1000+(end500000.tv_usec-start.tv_usec)/1000;
		}
		if(i==750000-1){
			gettimeofday(&end750000, NULL);
			time_int2=(end750000.tv_sec-start.tv_sec)*1000+(end750000.tv_usec-start.tv_usec)/1000;
		}
			
	}
	current->linkp=NULL;
    gettimeofday(&end1000000, NULL);
	time_int3=(end1000000.tv_sec-start.tv_sec)*1000+(end1000000.tv_usec-start.tv_usec)/1000;

	printf("Time spent for 1-500.000:%lf ms\n",time_int1);
	printf("Time spent for 1-750.000:%lf ms\n",time_int2);
	printf("Time spent for 1-1.000.000:%lf ms\n",time_int3);
	fprintf(list_file,"Time spent for 1-500.000:%lf\n",time_int1);
	fprintf(list_file,"Time spent for 1-750.000:%lf\n",time_int2);
	fprintf(list_file,"Time spent for 1-1.000.000:%lf\n",time_int3);

	fclose(list_file);
	
}
/*Question 2.b and 3 for 2.b together in this function*/
/*Recording the values at file to a dynamic allocated array. And printing the value
if the value is a prime number. In this function the calculation time is also 
calculated by the gettimeofday functions.*/
void record_to_array(int *dynamic_alloc_array,FILE *f){
	FILE *array_file;
	struct timeval starta,start1, end500000a,end750000a,end1000000a,end1;
	double time_int1,time_int2,time_int3;
	int num;
	int i=0;

	array_file=fopen("output_prime_dynamic_array.txt","w");
    gettimeofday(&starta, NULL);
	
	while(i<1000000){
		num=get_line(f);
		dynamic_alloc_array[i]=num;
			if(isPrime(dynamic_alloc_array[i])==1){
				printf("%d\n",dynamic_alloc_array[i]);
				fprintf(array_file,"%d\n",dynamic_alloc_array[i]);
			}
		if(i==500000-1){
			gettimeofday(&end500000a, NULL);
			time_int1=(end500000a.tv_sec-starta.tv_sec)*1000+(end500000a.tv_usec-starta.tv_usec)/1000;
		}
		if(i==750000-1){
			gettimeofday(&end750000a, NULL);
			time_int2=(end750000a.tv_sec-starta.tv_sec)*1000+(end750000a.tv_usec-starta.tv_usec)/1000;
		}
		
		i++;	
	}

 	gettimeofday(&end1000000a, NULL);
	time_int3=(end1000000a.tv_sec-starta.tv_sec)*1000+(end1000000a.tv_usec-starta.tv_usec)/1000;
	printf("Time spent for 1-500.000:%lf ms\n",time_int1);
	printf("Time spent for 1-750.000:%lf ms\n",time_int2);
	printf("Time spent for 1-1.000.000:%lf ms\n",time_int3);
	fprintf(array_file,"Time spent for 1-500.000:%lf\n",time_int1);
	fprintf(array_file,"Time spent for 1-750.000:%lf\n",time_int2);
	fprintf(array_file,"Time spent for 1-1.000.000:%lf\n",time_int3);

	fclose(array_file);
}
int main(){
 	FILE *f;
	node_t *head,*current;
	int *dynamic_alloc_array;

	head=(node_t*)malloc(sizeof(node_t));
	dynamic_alloc_array=(int*)calloc(1000000,sizeof(int));

	f=fopen("data.txt","r");
	record_to_array(dynamic_alloc_array,f);
	fclose(f);

	f=fopen("data.txt","r");
 	record_to_linked_list(f,head);
	fclose(f);

	free(dynamic_alloc_array);

	while(head!=NULL){
		current=head;
		head=head->linkp;
		free(current);
	}
	return 0;
}

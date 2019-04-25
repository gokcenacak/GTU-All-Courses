/*arr[]: given numbers
  expected_value: given solution
  operations[]: empty array at first then will be filled with the true sequence of operations
  cursor: keeps track of the next element to do operations
  current: the result of that current operation
*/
	
/*Prints all operator combinations but the result is calculated wrong*/
/*Left some printf statements so it can be controlled that the operators are 
removed and replaced by another one but the returned result is an array which its elements are removed completely

' ' represents removed operations during process

The program works and finds the current result for the corresponding operations for the first 7 times then it starts calculating 
from backwards and that results wrong in that case program doesnt go in to the base condition and does not return a full operations array
but return a full empty array.

*/

#include <stdio.h>

char* find_operations(int arr[],int expected_val,char operations[],size_t arr_len,int cursor,int current){
			/*Checks if the current value is equal to the expected one and checks if cursor is in the end*/
			if(current==expected_val && cursor==arr_len ){
				return operations;
			}

			/*Does the + operation and fills up the operations with +'s first*/
			operations[cursor-1]='+';
			current+=arr[cursor];
			
			printf("check1:%d %s\n",current,operations);
			/*Checks if operations char array didnt full up*/
			if(operations[cursor]!='\0' && current!=expected_val){
				find_operations(arr,expected_val,operations,arr_len,cursor+1,current);
			}
			/*When all +'s fail program tries - and * */
			operations[cursor-1]='-';
			current-=arr[cursor];
					
			printf("check2:%d %s\n",current,operations);
			/*Checks if operations char array didnt full up*/
			if(operations[cursor]!='\0'&& current!=expected_val){
				find_operations(arr,expected_val,operations,arr_len,cursor+1,current);
			}
			operations[cursor-1]='*';
			current*=arr[cursor];
					
			printf("check3:%d %s\n",current,operations);
			/*Checks if operations char array didnt full up*/
			if(operations[cursor]!='\0'&& current!=expected_val){
				find_operations(arr,expected_val,operations,arr_len,cursor+1,current);
			}
			operations[cursor-1]=' ';



}


int main(){

	int arr_len=6;
	int arr[6]={25,12,6,10,32,8};
	char operations[6]={' ',' ',' ',' ',' '};
	int expected_val=41;
	printf("result:%s",find_operations(arr,expected_val,operations,6,1,arr[0]));
return 0;
}













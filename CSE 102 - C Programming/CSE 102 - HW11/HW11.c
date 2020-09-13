#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Structure definitions for Customers and Rooms*/
typedef struct Customers{
	int room_num;
	char *surname;
	char *name;
	int age;
	char *gender;
	struct Customers *related_customer;
}Customer;

typedef struct Rooms{
	int number;
	int capacity;
	int floor;
	Customer *customers;
	struct Rooms *next_room;
}Room;

void add_customer_to_end();
void show_vacancy();
void link_customers_to_room();
	
/*Creating the rooms linked list*/
void room_linked_list(FILE *room_file,FILE *customer_file,Room *room_head){
	char line[1024];
	Room *room;

	if(room_head->next_room==NULL){
		fgets(line,1024,room_file);
		sscanf(line,"%d,%d,%d",&room_head->number,&room_head->capacity,&room_head->floor);

	}
	room=room_head;
		while(fgets(line,1024,room_file)){
			room->next_room=(Room *)malloc(sizeof(Room));
			room=room->next_room;
			sscanf(line,"%d,%d,%d",&room->number,&room->capacity,&room->floor);

		}
		room->next_room=NULL;

}
/*Function which adds a room to the end of the rooms linked list, the attributes are taken from the user*/
void add_room_to_end(Room *room_head){
	Room *new_room;	
	Room *last_room;
	last_room=room_head;
	new_room=(Room *)malloc(sizeof(Room));
	printf("Please enter room number:");
	scanf("%d",&new_room->number);
	printf("Please enter capacity:");
	scanf("%d",&new_room->capacity);
	printf("Please enter floor:");
	scanf("%d",&new_room->floor);
	new_room->next_room=NULL;

	if(room_head==NULL){
		room_head=new_room;
	}

	while(last_room->next_room!=NULL){
		last_room=last_room->next_room;
	}
	last_room->next_room=new_room;
}
/*Prints the room list but without the customers*/
void print_list(Room *room_head){
	Room *room;
	room=room_head;

	while(room!=NULL){
		/*When head node is removed at remove room function it leaves 0 0 0 as values to delete it completely on screen this if condition is added*/
		if(room->number!=0 && room->floor!=0){
		printf("Room %d (Floor %d - capacity %dx):\n",room->number,room->floor,room->capacity);

		}
		room=room->next_room;
		
	}
}
/*Prints rooms which is at the entered floor*/
void get_by_floor(Room *room_head){
	Room *room;
	int floor_num;
	int flag=0;
	room=room_head;
	printf("Please enter a floor number:");
	scanf("%d",&floor_num);
	while(room!=NULL){

		if(room->number!=0 && room->floor!=0 && room->floor==floor_num){
			printf("Room %d (Floor %d - capacity %dx)\n",room->number,room->floor,room->capacity);
			flag=1;
		}
		room=room->next_room;
		
	}
	if(flag==0)
	printf("There is no room in that floor.\n");
}
/*Adds a room after the given room number. Room attributes are taken from the user*/
void add_room_after_room_number(Room *room_head){
	int target_num;
	Room *target_room;
	Room *new_room;
	target_room=room_head;
	new_room=(Room *)malloc(sizeof(Room));
	printf("Please enter the room number to add your room after:");
	scanf("%d",&target_num);

	printf("Please enter room number:");
	scanf("%d",&new_room->number);
	printf("Please enter capacity:");
	scanf("%d",&new_room->capacity);
	printf("Please enter floor:");
	scanf("%d",&new_room->floor);

		if(room_head->next_room==NULL){
			room_head=new_room;
		}

		while(target_room->number!=target_num && target_room->next_room!=NULL){
			target_room=target_room->next_room;
		}
		if(target_room->number==target_num){
			new_room->next_room=target_room->next_room;
			target_room->next_room=new_room;
		}
		else{
			target_room->next_room=(Room *)malloc(sizeof(Room));
			target_room->next_room=new_room;
			new_room->next_room=NULL;
		}
		
}
/*Removes a room whose room number is given by the user*/
void remove_room(Room *room_head){
	Room *prev_room;
	int target_num;

	printf("Please enter the room number to be deleted:");
	scanf("%d",&target_num);


	prev_room=room_head;
	if(room_head->number==target_num){
		room_head=prev_room->next_room;
		free(prev_room);
	}
	else{
		while(prev_room->next_room->number!=target_num && prev_room->next_room!=NULL){
			prev_room=prev_room->next_room;
		}
		if(prev_room->next_room->number==target_num){
			prev_room->next_room=prev_room->next_room->next_room;
		}
	}

}

int main(){
	char line[1024];
	FILE *room_file;
	FILE *customer_file;
	Customer *customer;
	Room *room_head;
	room_file=fopen("rooms.txt","r");
	customer_file=fopen("customers.txt","r");
	room_head=(Room *)malloc(sizeof(Room));

	int choice;
	do{
		printf("\n1-Creating the linked list of rooms\n2-Adding room to the end\n3-Adding room after a given room number\n4-Removing a given room\n5-Printing rooms by floor\n**Customer related functions are not implemented yet.**\n\nPlease press 0 to exit.\nYour choice:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:	room_linked_list(room_file,customer_file,room_head);
					print_list(room_head);
					break;

			case 2:	add_room_to_end(room_head);
					print_list(room_head);
					break;

			case 3:	add_room_after_room_number(room_head);
					print_list(room_head);
					break;

			case 4:	remove_room(room_head);
					print_list(room_head);
					break;
		
			case 5:	get_by_floor(room_head);
					break;
		}
	}while(choice!=0);

return 0;
}

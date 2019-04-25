
/*HW08part1.c by Gokce Nur Erer*/
/*Difference from the actual homework, if the dice roll makes the player move
  more than 100 the player moves and stops at 100 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum Blocks{
	P,S,M,B,T,Normal
}Blocktype;
typedef struct{
	char text[9];
	int data;
	Blocktype type;
	int pos_x;
	int pos_y;
	int jump_x;
	int jump_y;
}block;

/*Copies the string*/
void string_copy(char * str1,char str2[]){
	int i;
	for(i=0;str2[i]!='\0';i++){
		str1[i]=str2[i];
	}
	str1[i]='\0';
}
/*Initializes the board, even and odd numbered rows are differently initialized.*/
void init_board(block board[][10]){
	char *num_str[100]={"1","2","3","4","5","6","7","8","9","10",
					 "11","12","13","14","15","16","17","18","19","20",
					 "21","22","23","24","25","26","27","28","29","30",
					 "31","32","33","34","35","36","37","38","39","40",
					 "41","42","43","44","45","46","47","48","49","50",
					 "51","52","53","54","55","56","57","58","59","60",
					 "61","62","63","64","65","66","67","68","69","70",
					 "71","72","73","74","75","76","77","78","79","80",
					 "81","82","83","84","85","86","87","88","89","90",
					 "91","92","93","94","95","96","97","98","99","100"};
	int i,j,data_val=1;
	for(i=9;i>=0;i--){
		if(i%2!=0){
			for(j=9;j>=0;j--){
				board[i][j].data=data_val;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;
				board[i][j].type=Normal;
				board[i][j].jump_x=0;
				board[i][j].jump_y=0;
				string_copy(board[i][j].text,num_str[data_val-1]);

					if(data_val==1){
						string_copy(board[i][j].text,"1(Start)");
					}
					else if(data_val==7){
						string_copy(board[i][j].text,"M{11}");
						board[i][j].type=M;
						board[i][j].jump_x=8;
						board[i][j].jump_y=0;
					}
					else if(data_val==6){
						string_copy(board[i][j].text,"S{1}");
						board[i][j].type=S;
						board[i][j].jump_x=9;
						board[i][j].jump_y=9;
					}
					else if(data_val==29 || data_val==50 || data_val==66 || data_val==82){
						string_copy(board[i][j].text,"B");
						board[i][j].type=B;
						if(data_val==29 || data_val==50 || data_val==66){
							board[i][j].jump_x=i-1;
							board[i][j].jump_y=(5-j)-1;
						}
						else{
							board[i][j].jump_x=i;
							board[i][j].jump_y=(j-5);

						}
					}
					else if(data_val==25){
						string_copy(board[i][j].text,"S{12}");
						board[i][j].type=S;
						board[i][j].jump_x=8;
						board[i][j].jump_y=1;
					}
					else if(data_val==48 || data_val==85){
						string_copy(board[i][j].text,"P");
						board[i][j].type=P;
						board[i][j].jump_x=i;
						board[i][j].jump_y=j;
					}
					else if(data_val==45){
						string_copy(board[i][j].text,"S{22}");
						board[i][j].type=S;
						board[i][j].jump_x=7;
						board[i][j].jump_y=8;
					}
					else if(data_val==69){
						string_copy(board[i][j].text,"M{77}");
						board[i][j].type=M;
						board[i][j].jump_x=2;
						board[i][j].jump_y=6;
					}
					else if(data_val==63){
						string_copy(board[i][j].text,"S{52}");
						board[i][j].type=S;
						board[i][j].jump_x=4;
						board[i][j].jump_y=1;
					}
					else if(data_val==89){
						string_copy(board[i][j].text,"M{94}");
						board[i][j].type=M;
						board[i][j].jump_x=0;
						board[i][j].jump_y=3;
					}
					data_val++;
			}
		}
		if(i%2==0){
			for(j=0;j<10;j++){
				board[i][j].data=data_val;
				string_copy(board[i][j].text,num_str[data_val-1]);
				board[i][j].type=Normal;
				board[i][j].pos_x=i;
				board[i][j].pos_y=j;

				if(data_val==100){
						string_copy(board[i][j].text,"100(Finish)");
				}
				else if(data_val==13){
					string_copy(board[i][j].text,"P");
					board[i][j].type=P;
					board[i][j].jump_x=i;
					board[i][j].jump_y=j;
				}
				else if(data_val==17){
						string_copy(board[i][j].text,"M{28}");
						board[i][j].type=M;
						board[i][j].jump_x=7;
						board[i][j].jump_y=2;
				}
				else if(data_val==32){
						string_copy(board[i][j].text,"M{52}");
						board[i][j].type=M;
						board[i][j].jump_x=4;
						board[i][j].jump_y=1;
				}
				else if(data_val==36){
						string_copy(board[i][j].text,"B");
						board[i][j].type=B;
						board[i][j].jump_x=5;
						board[i][j].jump_y=9;
				}
				else if(data_val==40 ||data_val==54 || data_val==79 || data_val==93){
						string_copy(board[i][j].text,"T");
						board[i][j].type=T;
					if(j-5<0){
						board[i][j].jump_x=i+1;
						board[i][j].jump_y=(5-j)-1;
					}
					else{
						board[i][j].jump_x=i;
						board[i][j].jump_y=j-5;
					}
				}
				else if(data_val==57){
						string_copy(board[i][j].text,"M{77}");
						board[i][j].type=M;
						board[i][j].jump_x=2;
						board[i][j].jump_y=6;
				}
				else if(data_val==60){
						string_copy(board[i][j].text,"S{44}");
						board[i][j].type=S;
						board[i][j].jump_x=5;
						board[i][j].jump_y=6;
				}
				else if(data_val==73){
						string_copy(board[i][j].text,"S{68}");
						board[i][j].type=S;
						board[i][j].jump_x=3;
						board[i][j].jump_y=2;
				}
				else if(data_val==76){
						string_copy(board[i][j].text,"M{83}");
						board[i][j].type=M;
						board[i][j].jump_x=1;
						board[i][j].jump_y=7;
				}
				else if(data_val==98){
						string_copy(board[i][j].text,"S{72}");
						board[i][j].type=S;
						board[i][j].jump_x=2;
						board[i][j].jump_y=1;
				}
				else if(data_val==99){
						string_copy(board[i][j].text,"S{56}");
						board[i][j].type=S;
						board[i][j].jump_x=4;
						board[i][j].jump_y=5;
				}
				data_val++;

			}
		}
	}
}
/*Prints the board*/
void print_board(block board[][10]){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			printf("%-5s ",board[i][j].text);
		}
				printf("\n");

	}
}
/*Prints the moves backwards and returns the move value*/
int single_player_game(block board[][10],int row, int column,int moves){
	moves++;
	block current_block;
	int dice_roll;
	dice_roll=1+rand()%6;
	int jump_x;
	int jump_y;
	if(board[row][column].data+dice_roll<100){
		if(row%2!=0){
			if(column-dice_roll>=0){
				current_block=board[row][column-dice_roll];
					if(current_block.type==S || current_block.type==M || current_block.type==B || current_block.type==T|| current_block.type==P){
						if(current_block.type==P){
							jump_x=row;
							jump_y=column;
						}
						else{
							jump_x=current_block.jump_x;
							jump_y=current_block.jump_y;
						}
						current_block=board[jump_x][jump_y];
					}
			}
			else{
				current_block=board[row-1][dice_roll-column-1];
					if(current_block.type==S || current_block.type==M || current_block.type==B || current_block.type==T|| current_block.type==P){
						if(current_block.type==P){
							jump_x=row;
							jump_y=column;
						}
						else{
							jump_x=current_block.jump_x;
							jump_y=current_block.jump_y;
						}
						current_block=board[jump_x][jump_y];
						
					}
			}
		}
		else if(row%2==0){
			if(column+dice_roll<=9){
				current_block=board[row][column+dice_roll];
					if(current_block.type==S || current_block.type==M || current_block.type==B || current_block.type==T|| current_block.type==P){
						if(current_block.type==P){
							jump_x=row;
							jump_y=column;
						}
						else{
							jump_x=current_block.jump_x;
							jump_y=current_block.jump_y;
						}
						current_block=board[jump_x][jump_y];
					}
			}
			else{
				current_block=board[row-1][9-(dice_roll+column)%10];
					if(current_block.type==S || current_block.type==M || current_block.type==B || current_block.type==T|| current_block.type==P){
						if(current_block.type==P){
							jump_x=row;
							jump_y=column;
						}
						else{
							jump_x=current_block.jump_x;
							jump_y=current_block.jump_y;
						}
						current_block=board[jump_x][jump_y];
					}
			}
		}
			if(current_block.data!=100){
				moves=single_player_game(board,current_block.pos_x,current_block.pos_y,moves);
				printf("Move: Dice:%d New Block:%d\n",dice_roll,current_block.data);
			}

		}
		else{
			if(board[row][column].data+dice_roll==100){
				current_block=board[row][column+dice_roll];
				printf("Move: Dice:%d New Block:%d\n",dice_roll,current_block.data);
			}
			else{
				current_block=board[row][column];
				moves=single_player_game(board,row,column,moves);
				printf("Move: Dice:%d New Block:%d\n",dice_roll,current_block.data);
				
			}
	
		}
			return moves;
	}
/*Plays two seperate games for 2 players and compare moves, prints the player who
has the least move*/
void multiplayer_game(block board[][10]){
	int player1;
	int player2;
	printf("---------Player 1----------\n");
	player1=single_player_game(board,9,9,0);
	printf("Player 1 move #:%d\n",player1);
	printf("\n---------Player 2----------\n");
	player2=single_player_game(board,9,9,0);
	printf("Player 2 move #:%d\n",player2);

	if(player1>player2){
		printf("\nWinner is player 2.\n");
	}
	else if(player1<player2){
		printf("\nWinner is player 1.\n");
	}
	else if(player1==player2)
		printf("\n	  Tie!\n");
	else
		printf("There is no winner!\n");
}
int main(){
	srand(time(NULL));
	block board[10][10];
	int num;
	init_board(board);
	print_board(board);
	printf("\n  TEST FOR SINGLE PLAYER GAME\n");
	printf("-------------------------------\n\n");
	num=single_player_game(board,9,9,0);
	printf("Move #:%d\n",num);
	printf("\n  TEST FOR MULTIPLAYER GAME\n");
	printf("------------------------------\n\n");
	multiplayer_game(board);
return 0;
}

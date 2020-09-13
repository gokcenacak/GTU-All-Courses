#include <stdio.h>

typedef enum {white_man,black_man,white_king,black_king,empty} piece;
typedef enum {white=10,black=20} player;

void init_board(piece board[][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(i==0 || i==3 || i==4 || i==7){
				board[i][j]=empty;
			}
			if(i==1 || i==2){
				board[i][j]=black_man;
			}
			if(i==5 || i==6){
				board[i][j]=white_man;
			}
		}
	}
}
/*Displays the board*/
void display_board(piece board[][8]){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]==empty){
				printf("-");
			}
			if(board[i][j]==white_man){
				printf("w");
			}
			if(board[i][j]==black_man){
				printf("b");
			}
			if(board[i][j]==white_king){
				printf("W");
			}
			if(board[i][j]==black_king){
				printf("B");
			}
		}
		printf("\n");
	}
}
/*Controls moves*/
int control_move(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p){
/*Opponent's piece*/
	if(p==white && (board[from_x][from_y]==black_man || board[from_x][from_y]==black_king)){
		printf("Wrong piece!");
		return -1;
	}
	/*Opponent's piece*/
	else if(p==black && (board[from_x][from_y]==white_man || board[from_x][from_y]==white_king)){
		printf("Wrong piece!");
		return -1;
	}
	/*Backwards move control for white*/
	else if(p==white && board[from_x][from_y]==white_man && (from_x<to_x && from_y==to_y)){
		printf("Backwards move is not allowed!");
		return -2;
	}
	/*Backwards move control for black*/
	else if(p==black && board[from_x][from_y]==black_man && (from_x>to_x && from_y==to_y)){
		printf("Backwards move is not allowed!");
		return -2;
	}
	/*Controlling the move if player is trying to move on to their own piece*/	
	else if(p==white && (board[to_x][to_y]==white_man || board[to_x][to_y]==white_king)){
		printf("Your piece is here!\n");
		return -2;
	}
	else if(p==black && (board[to_x][to_y]==black_man || board[to_x][to_y]==black_king)){
		printf("Your piece is here!\n");
		return -2;
	}
	/*White piece moving horizontally more than one squares control*/
	else if(p=white && (board[from_x][from_y]==white_man) && (from_x-to_x>1)){
		printf("You cannot move multiple squares!\n");
		return -2;
	}
	/*Black piece moving horizontally more than one squares control*/
	else if(p=black && (board[from_x][from_y]==black_man) && (to_x-from_x>1)){
		printf("You cannot move multiple squares!\n");
		return -2;
	}
	/*Horizontal multiple move control*/
	else if(((board[from_x][from_y]==white_man) ||(board[from_x][from_y]==black_man)) && (from_y-to_y>1 || to_y-from_y>1)){
		printf("You cannot move multiple squares!\n");
		return -2;
	}
	/*Out of borders*/
	else if((to_x>=8 || to_x<0) || (to_y>=8 || to_y<0)){
		printf("Out of borders\n");
		return -2;
	}
	else if(from_y!=to_y && from_x!=to_x){
		printf("You cannot move in more than one direction!\n");
		return -2;
	}
	else
		return 0;
	

}

int capture_for_man(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p,int captured);

/*Horizontal captures for man*/
void horizontal_capture(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p,int captured){

	/*White*/
if(board[from_x][from_y]==white_man){
 	if(((p==white)&&(board[from_x][to_y]==black_man || board[from_x][to_y]==black_king))){
			board[from_x][from_y]=empty;
			board[from_x][to_y]=empty;

			if(from_y<to_y &&  board[from_x][to_y+1]==empty){
				board[from_x][to_y+1]=white_man;
				from_y=to_y+1;
				to_y=from_y+1;
			}
			if(from_y>to_y && board[from_x][to_y-1]==empty){
				board[from_x][to_y-1]=white_man;
				from_y=to_y-1;
				to_y=from_y-1;
			}
			captured++;
	}
		if((board[from_x][to_y]==black_man || board[from_x][to_y]==black_king) && from_y<7 && from_y>0 && to_y<7 && to_y>0 && ((board[from_x][to_y+1]==empty || board[from_x][to_y+1]==empty) || (board[from_x][to_y-1]==empty || board[from_x][to_y-1]==empty))){
			horizontal_capture(board,from_x,from_y,to_x,to_y,white,captured);
		}
		if(board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king){
			to_x=from_x-1;
			capture_for_man(board,from_x,from_y,to_x,to_y,white,captured);
		}
		
	}
	/*Black*/
	if((p==black)&&(board[from_x][to_y]==white_man || board[from_x][to_y]==white_king)){

		if(board[from_x][from_y]==black_man){
			board[from_x][from_y]=empty;
			board[from_x][to_y]=empty;

			if(from_y<to_y && board[from_x][to_y+1]==empty){
				board[from_x][to_y+1]=black_man;
				from_y=to_y+1;
				to_y=from_y+1;
			}
			else if(from_y>to_y&& board[from_x][to_y-1]==empty){
				board[from_x][to_y-1]=black_man;
				from_y=to_y-1;
				to_y=from_y-1;
			}
			captured++;

		if((board[from_x][to_y]==white_man || board[from_x][to_y]==white_king) && (from_y<7 && from_y>0) && (to_y<7 && to_y>0) && ((board[from_x][to_y+1]==empty || board[from_x][to_y+1]==empty)|| (board[from_x][to_y-1]==empty || board[from_x][to_y-1]==empty))){

			horizontal_capture(board,from_x,from_y,to_x,to_y,black,captured);
		}
		if(board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king){
			to_x=from_x+1;
			capture_for_man(board,from_x,from_y,to_x,to_y,black,captured);
		}
	}
	

	
	
}
}
/*Captures for man*/
int capture_for_man(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p,int captured){
	if(p==white && board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
			if(to_x==7){
				board[to_x][to_y]=white_king;
			}
			else{
				board[to_x][to_y]=white_man;
			}
		}
		else if(p==black && board[to_x][to_y]==empty){
				board[from_x][from_y]=empty;
			if(to_x==0){
				board[to_x][to_y]=black_king;
			}
			else{
				board[to_x][to_y]=black_man;
			}
	}

	/*White man capturing*/
	if(p==white && board[from_x][from_y]==white_man && (board[to_x][from_y]==black_man || board[to_x][from_y]==black_king)){

			board[from_x][from_y]=empty;
			board[to_x-1][from_y]=white_man;
			board[to_x][from_y]=empty;

			if(to_x-1==0){		
				board[to_x-1][from_y]=white_king;
			}
			from_x=to_x-1;
			to_x=from_x-1;
			from_y=to_y;
			captured++;
		
		if((board[to_x][to_y]==black_man || board[to_x][to_y]==black_king)&& from_x>=0 && to_x>=0){
			capture_for_man(board,from_x,from_y,to_x,to_y,white,captured);
			captured++;
		}
}
		if((board[from_x][from_y+1]==black_man ||board[from_x][from_y+1]==black_king)){
			to_y=from_y+1;
			horizontal_capture(board,from_x,from_y,to_x,to_y,white,captured);
		} 
		else if(board[from_x][from_y-1]==black_man ||board[from_x][from_y-1]==black_king){
			to_y=from_y-1;
			horizontal_capture(board,from_x,from_y,to_x,to_y,white,captured);
		} 
		
		
	

	/*Black capturing*/
	if(p==black && board[from_x][from_y]==black_man && (board[to_x][from_y]==white_man || board[to_x][from_y]==white_king)){

			board[from_x][from_y]=empty;
			board[to_x+1][from_y]=black_man;
			board[to_x][from_y]=empty;

			if(to_x+1==7){	
				board[to_x+1][from_y]=black_king;
			}
			from_x=to_x+1;
			to_x=from_x+1;
			from_y=to_y;
			captured++;


			if((board[to_x][to_y]==white_man || board[to_x][to_y]==white_king)&& from_x<=7 && to_x<=7){
				capture_for_man(board,from_x,from_y,to_x,to_y,black,captured);
				captured++;
			}
	}
	if((board[from_x][from_y+1]==white_man || board[from_x][from_y+1]==white_king) &&board[from_x][from_y+2]==empty){
		to_y=from_y+1;
		horizontal_capture(board,from_x,from_y,to_x,to_y,black,captured);
	} 

	else if((board[from_x][from_y-1]==white_man || board[from_x][from_y-1]==white_king)&&board[from_x][from_y-2]==empty && from_y-1>=0){
		to_y=from_y-1;
		horizontal_capture(board,from_x,from_y,to_x,to_y,black,captured);
	} 

	
 return captured;
		

}
/*Captures for kings*/
int capture_for_king(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p,int captured){
	if(from_x>to_x && p==white){
		if((board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king) && board[from_x-2][from_y]!=black_man && board[from_x-2][from_y]!=black_king){
				board[from_x][from_y]=empty;
				board[from_x-1][from_y]=empty;
				board[from_x-2][from_y]=white_king;
				captured++;
				from_x=from_x-2;
			}
			else if(board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=white_king;
				to_x=from_x;
			}
			else if(from_x==to_x){
				board[from_x][from_y]=white_king;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x-1;
				board[from_x][from_y]=white_king;

			}
		if(from_x>=to_x && from_x<8 && from_x>=0){
			capture_for_king(board,from_x,from_y,to_x,to_y,white,captured);
		}
	}
	if(from_x<to_x && p==white){
		if((board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king) && board[from_x+2][from_y]!=black_man && board[from_x+2][from_y]!=black_king){
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				board[from_x+2][from_y]=white_king;
				captured++;
				from_x=from_x+2;
			}
			else if(board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=white_king;
				to_x=from_x;

			}
			else if(from_x==to_x){
				board[from_x][from_y]=white_king;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x+1;
				board[from_x][from_y]=white_king;
			}
		if(from_x<to_x && from_x<8 && from_x>=0){
			capture_for_king(board,from_x,from_y,to_x,to_y,white,captured);
		}
		
	}
	if(from_x>to_x && p==black){
		if((board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king) && board[from_x-2][from_y]!=white_man && board[from_x-2][from_y]!=white_king){
				board[from_x][from_y]=empty;
				board[from_x-1][from_y]=empty;
				board[from_x-2][from_y]=black_king;
				captured++;
				from_x=from_x-2;
			}
			else if(board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=black_king;
				to_x=from_x;
			}
			else if(from_x==to_x){
				board[from_x][from_y]=black_king;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x-1;
				board[from_x][from_y]=black_king;
			}
		if(from_x>=to_x && from_x<8 && from_x>=0){
			capture_for_king(board,from_x,from_y,to_x,to_y,black,captured);
		}
	}
	if(from_x<to_x && p==black){
		if((board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king) && board[from_x+2][from_y]!=white_man && board[from_x+2][from_y]!=white_king){
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				board[from_x+2][from_y]=black_king;
				captured++;
				from_x=from_x+2;
			}
			else if(board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=black_king;
				to_x=from_x;

			}
			else if(from_x==to_x){
				board[from_x][from_y]=black_king;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x+1;
				board[from_x][from_y]=black_king;
			}
		if(from_x<to_x && from_x<8 && from_x>=0){
			capture_for_king(board,from_x,from_y,to_x,to_y,black,captured);
		}
	}
	if(from_y<to_y && p==black){
		horizontal_capture(board,from_x,from_y,to_x,to_y,black,captured);
	}
}
/*-1 if player is trying to move opponent's piece
  -2 if the move is not allowed
  n>=0 move is allowed and it is executed with n of opponents pieces captured
	return values for capturing is working incorrectly*/
int move(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p){
	int result,captured=0;
	result=control_move(board,from_x,from_y,to_x,to_y,p);
	if(result==0){
		if(board[from_x][from_y]==white_man ||board[from_x][from_y]==black_man){
			if(board[from_x][from_y]==white_man){
				result=capture_for_man(board,from_x,from_y,to_x,to_y,white,captured);
			}
			if(board[from_x][from_y]==black_man){

				result=capture_for_man(board,from_x,from_y,to_x,to_y,black,captured);
			}
		}
		else if(board[from_x][from_y]==white_king ||board[from_x][from_y]==black_king){
			if(board[from_x][from_y]==white_king){
				result=capture_for_king(board,from_x,from_y,to_x,to_y,white,captured);
			}
			if(board[from_x][from_y]==black_king){
				result=capture_for_king(board,from_x,from_y,to_x,to_y,black,captured);

			}
		}
		
	}
	
}
/*-1 game continues
  white if white wins
  black if black wins*/
int check_end_of_game(piece board[][8]){
	int black=0;
	int white=0;
	int res;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j]==black_man || board[i][j]==black_king){
				black++;
			}
			if(board[i][j]==white_man || board[i][j]==white_king){
				white++;
			}
		}
	}
	if(white>0 && black>0){
			res=-1;	
	}
	if(black==0)
		res=1;
	if(white==0)
		res=2;
	
	return res;
}
/*Some functions are currently not working properly so instead of writing an end-to-end game I provided the moves that the program can do in sample_game2 function*/
void sample_game1(){
}
/*Some functions are currently not working properly so instead of writing the giving program I provided the moves that the program can actually do*/
void sample_game2(){
	piece board[8][8];
	init_board(board);
	display_board(board);
	printf("\n");
	move(board,5,0,4,0,white);
	display_board(board);
	printf("\n");
	move(board,2,0,3,0,black);
	display_board(board);
	printf("\n");
	move(board,5,5,4,5,white);
	display_board(board);
	printf("\n");
	move(board,2,2,3,2,black);
	display_board(board);
	printf("\n");
	move(board,4,0,3,0,white);
	display_board(board);
	printf("\n");
	move(board,2,1,2,0,black);
	display_board(board);
	printf("\n");	
	move(board,0,0,7,0,white);
	display_board(board);
	printf("\n");
	move(board,2,6,3,6,black);
	display_board(board);
	printf("\n");
	move(board,5,7,4,7,white);
	display_board(board);
	printf("\n");
	move(board,3,6,3,5,black);
	display_board(board);
	printf("\n");
	move(board,5,6,4,6,white);
	display_board(board);
	printf("\n");
	move(board,3,5,4,5,black);
	display_board(board);
	printf("\n");
	move(board,4,6,4,5,white);
	display_board(board);
	printf("\n");
	move(board,7,5,3,5,black);
	display_board(board);
}

int main(){
	sample_game2();
	return 0;
}

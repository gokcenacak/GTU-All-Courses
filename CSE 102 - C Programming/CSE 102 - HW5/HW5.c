/*CSE 102 - C Programming Homework 5*/
/*HW05_Gokce_Nur_Erer_171044079.c   */

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
/*Controls moves of white_man and black_man pieces*/
int man_moves(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p){
	int white_captured=0;
	int black_captured=0;
	/*Move is not allowed because player is trying to play more than 1 square*/
	if((p==white && (to_x-from_x>1 || (to_y-from_y>1 || from_y-to_y>1))&&board[from_x][from_y]==white_man)||(p==black && (from_x-to_x>1 || (to_y-from_y>1 || from_y-to_y>1))&&board[from_x][from_y]==black_man)){
		return -2;
	}
	/*Move is not allowed because player is trying to go backwards*/
	else if ((p==white && from_x<to_x) || (p==black && from_x>to_x)){
		return -2;
	}
	/*Move when the target square is empty for white*/
	else if((p==white && board[to_x][to_y]==empty)){
		board[from_x][from_y]=empty;
			if(to_x==0){
				board[to_x][to_y]=white_king;
			}
			else{
				board[to_x][to_y]=white_man;
			}
		return 0;
	}
	/*Move when the target square is empty for black*/
	else if(p==black && board[to_x][to_y]==empty){
		board[from_x][from_y]=empty;
			if(to_x==7){
				board[to_x][to_y]=black_king;
			}
			else{
				board[to_x][to_y]=black_man;
			}
		return 0;
	}
	/*White player capturing in the upwards direction*/
	else if((p==white && (board[to_x][from_y]==black_man || board[to_x][from_y]==black_king))){
		while((board[to_x][from_y]==black_man || board[to_x][from_y]==black_king)&& from_x>=0 && to_x>=0){
			board[from_x][from_y]=empty;
			board[to_x-1][from_y]=white_man;
			board[to_x][from_y]=empty;

			if(to_x-1==0){		
				board[to_x-1][from_y]=white_king;
			}
			from_x=to_x-1;
			to_x=from_x-1;

			black_captured++;

		}
		return black_captured;
	}
	/*Black player capturing in the upwards direction*/
	else if((p==black && (board[to_x][from_y]==white_man || board[to_x][from_y]==white_king))){
		while((board[to_x][from_y]==white_man || board[to_x][from_y]==white_king)&& from_x<=7 && to_x<=7){
			board[from_x][from_y]=empty;
			board[to_x+1][from_y]=black_man;
			board[to_x][from_y]=empty;

			if(to_x+1==7){		
				board[to_x+1][from_y]=black_king;
			}
			white_captured++;
			from_x=to_x+1;
			to_x=from_x+1;
		}
		return white_captured;
	}
	/*White player capturing horizontally*/
	else if((p==white)&&(board[from_x][to_y]==black_man || board[from_x][to_y]==black_king)){
		while((board[from_x][to_y]==black_man || board[from_x][to_y]==black_king) && from_y<7 && from_y>0 && to_y<7 && to_y>0 && ((board[from_x][to_y+1]==empty || board[from_x][to_y+1]==empty) || (board[from_x][to_y-1]==empty || board[from_x][to_y-1]==empty))){
			board[from_x][from_y]=empty;
			board[from_x][to_y]=empty;

			if(from_y<to_y){
				board[from_x][to_y+1]=white_man;
				from_y=to_y+1;
				to_y=from_y+1;
			}
			if(from_y>to_y){
				board[from_x][to_y-1]=white_man;
				from_y=to_y-1;
				to_y=from_y-1;
			}
			black_captured++;

	}
	return black_captured;
	}
	/*Black player capturing horizontally*/
	else if((p==black)&&(board[from_x][to_y]==white_man || board[from_x][to_y]==white_king)){
		while((board[from_x][to_y]==white_man || board[from_x][to_y]==white_king) && from_y<7 && from_y>0 && to_y<7 && to_y>0 && ((board[from_x][to_y+1]==empty || board[from_x][to_y+1]==empty) || (board[from_x][to_y-1]==empty || board[from_x][to_y-1]==empty))){
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
			white_captured++;

	}
	return white_captured;
	}
}
/*Kings move up and down but couldn't implement the left and right moves. */
int king_moves(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p){
	int black_captured=0;
	int white_captured=0;
	int i;
	/*White king moving up*/
	if(from_x>to_x && p==white){
		while(from_x!=to_x){
			if((board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king) && board[from_x-2][from_y]!=black_man && board[from_x-2][from_y]!=black_king){
				board[from_x][from_y]=empty;
				board[from_x-1][from_y]=empty;
				board[from_x-2][from_y]=white_king;
				black_captured++;
				from_x=from_x-2;
			}
			else if(board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=white_king;
				to_x=from_x;
			}
			else if(from_x==to_x){
				board[from_x][from_y]=white_king;
				break;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x-1;
			}
		}
	}
	/*White king moving down*/
	if(from_x<to_x && p==white){
		while(from_x<=to_x && to_x<8 && from_x>=0){
			if((board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king) && board[from_x+2][from_y]!=black_man && board[from_x+2][from_y]!=black_king){
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				board[from_x+2][from_y]=white_king;
				black_captured++;
				from_x=from_x+2;
			}
			else if(board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=white_king;
				to_x=from_x;

			}
			else if(from_x==to_x){
				board[from_x][from_y]=white_king;
				break;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x+1;
			}
		}
	}
	/*Black king moving up*/

	if(from_x>to_x && p==black){
		while(from_x!=to_x){
			if((board[from_x-1][from_y]==white_man || board[from_x-1][from_y]==white_king) && board[from_x-2][from_y]!=white_man && board[from_x-2][from_y]!=white_king){
				board[from_x][from_y]=empty;
				board[from_x-1][from_y]=empty;
				board[from_x-2][from_y]=black_king;
				white_captured++;
				from_x=from_x-2;
			}
			else if(board[from_x-1][from_y]==black_man || board[from_x-1][from_y]==black_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=black_king;
				to_x=from_x;
			}
			else if(from_x==to_x){
				board[from_x][from_y]=black_king;
				break;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x-1;
			}
		}
	}
	/*Black king moving down*/

	if(from_x<to_x && p==black){
		while(from_x<=to_x && to_x<8 && from_x>=0){
			if((board[from_x+1][from_y]==white_man || board[from_x+1][from_y]==white_king) && board[from_x+2][from_y]!=white_man && board[from_x+2][from_y]!=white_king){
				board[from_x][from_y]=empty;
				board[from_x+1][from_y]=empty;
				board[from_x+2][from_y]=black_king;
				white_captured++;
				from_x=from_x+2;
			}
			else if(board[from_x+1][from_y]==black_man || board[from_x+1][from_y]==black_king){
				board[from_x][from_y]=empty;
				board[from_x][from_y]=black_king;
				to_x=from_x;

			}
			else if(from_x==to_x){
				board[from_x][from_y]=black_king;
				break;
			}
			else{
				board[from_x][from_y]=empty;
				from_x=from_x+1;
			}
		}
	}
	return black_captured;


}
int move(piece board[][8],int from_x,int from_y,int to_x,int to_y,player p){
	int res;
	/*Player choosing opponent's piece.*/
	if((p==white && board[from_x][from_y]==black_man)||(p==black && board[from_x][from_y]==white_man)){
		res=-1;
	}
	/*Move is not allowed because there is a same colored piece.*/
	else if((p==white && (board[to_x][to_y]==white_man || board[to_x][to_y]==white_king))||(p==black && (board[to_x][to_y]==black_man|| board[to_x][to_y]==black_king))){
		res=-2;
	}
	/*Move is not allowed because it passes board borders*/
	else if((to_x>=8 || to_x<0)|| (to_y>=8 || to_y<0)){
		res=-2;
	}
	/*Move is not allowed because player is trying to move in more than one direction*/
	else if(((to_x-from_x==1 || from_x-to_x==1) && to_y!=from_y)||((to_y-from_y==1 || from_y-to_y ==1) && to_x!=from_x)){
		res=-2;
	}
	/*Controls moves for man*/
	else if(board[from_x][from_y]==white_man || board[from_x][from_y]==black_man){
		res=man_moves(board,from_x,from_y,to_x,to_y,p);
	}
	else if(board[from_x][from_y]==white_king || board[from_x][from_y]==black_king){

		res=king_moves(board,from_x,from_y,to_x,to_y,p);
	}
	return res;
}
/*1 for white winning,2 for black winning, only controls if there is a side which has 0 pieces left. */
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
void display_board(piece board[][8]);
void sample_game1(){
	/*Since king's side movements are not implemented a full game works incorrectly*/
	piece board[8][8];
	init_board(board);
	display_board(board);
	

}
void sample_game2(){
	piece board[8][8];
	init_board(board);
	board[6][0]=empty;
	board[6][1]=empty;
	board[6][6]=empty;
	board[6][7]=empty;
	board[5][5]=empty;
	board[4][2]=white_man;
	board[4][3]=white_man;
	board[4][4]=white_man;
	board[4][5]=black_man;
	board[4][6]=white_man;
	board[4][7]=white_man;
	board[3][0]=black_man;
	board[3][1]=black_man;
	board[3][2]=black_man;
	board[3][5]=black_man;
	board[3][7]=black_man;
	board[2][0]=empty;
	board[2][5]=empty;
	board[1][0]=empty;
	board[1][1]=empty;
	board[1][6]=empty;
	board[1][7]=empty;
	display_board(board);
	move(board,5,1,4,1,white);
	display_board(board);
	move(board,3,1,4,1,black);
	display_board(board);
	move(board,4,3,3,3,white);
	display_board(board);
	move(board,4,5,4,4,black);
	display_board(board);
	move(board,3,3,3,2,white);
	display_board(board);
	move(board,3,1,2,1,white);
	display_board(board);
	move(board,1,2,1,1,black);
	display_board(board);
	move(board,5,3,4,3,white);
	display_board(board);
	move(board,5,1,5,2,black);
	display_board(board);
	move(board,5,5,6,5,black);
	display_board(board);
	move(board,4,3,3,3,white);
	display_board(board);
	move(board,2,3,3,3,black);
	display_board(board);
	move(board,5,6,5,5,white);
	display_board(board);
	move(board,7,5,4,5,black);
	display_board(board);
	move(board,4,6,4,5,white);
	display_board(board);
	move(board,4,0,3,0,white);
	display_board(board);
}

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
int main()
{
	sample_game1();
	sample_game2();
	
	return 0;
}	
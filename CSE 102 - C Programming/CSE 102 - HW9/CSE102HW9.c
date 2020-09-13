/*									HOMEWORK 9 

							171044079.c by Gokce Nur Erer						
This program aims to play a game which there is a botanist and botanist has to
find a rare flower in a maze. Program reads water bottle value,map's dimentions,
and map from a CSV file.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/*Enumaration for map values*/
typedef enum{
	tree,botanists,rare_flower,empty
}types;

/*Structure for botanist*/
typedef struct{
	int coord_x;
	int coord_y;
	int water_bottle_size;
}Botanist;

/*Structure for forest*/
typedef struct{
	int **map; 
	int width;
	int height;
	int flower_x;
	int flower_y;
}Forest;

void print_map(Forest forest);
void init_game(Forest *forest, Botanist *botanist);
void search(int bot_x,int bot_y,int flo_x,int flo_y,int water,int **map,Forest *forest);

/*Initializes the forest and the botanist structures, reads the components from
the file and writes them the structure, for map used calloc to do a dynamic
memory allocation.*/

void init_game(Forest *forest, Botanist *botanist){
	FILE *file;
	int k;
	char water_bottle_size[1024];
	char dimentions[1024],line[1024];
	char *widthstr,*heightstr,*element;
	file=fopen("init.csv","r");
	fgets(water_bottle_size,1024,file);
	sscanf(water_bottle_size,"%d",&botanist->water_bottle_size);

	fgets(dimentions,1024,file);
	heightstr=strtok(dimentions,",");
	widthstr=strtok(NULL,",");
	sscanf(heightstr,"%d",&forest->height);
	sscanf(widthstr,"%d",&forest->width);
	
	forest->map=(int **)calloc(forest->height,sizeof(int*));

		for(int i=0;i<(forest->height);i++){
			(forest->map)[i]=(int *)calloc(forest->width,sizeof(int));
		}
		while(fgets(line,1024,file)){
			element=strtok(line,",");
				for(int j=0;j<(forest->width);j++){
					if(strcmp(element,"#")==0){
						(forest->map)[k][j]=tree;
					}
					else if(strcmp(element,"B")==0){
						(forest->map)[k][j]=botanists;
						botanist->coord_x=k;
						botanist->coord_y=j;
					}
					else if(strcmp(element,"F")==0){
						(forest->map)[k][j]=rare_flower;
						forest->flower_x=k;
						forest->flower_y=j;
					}
					else if(strcmp(element," ")==0){
						(forest->map)[k][j]=empty;
					}
					element=strtok(NULL,",");
				}
			k++;
		}
	fclose(file);
}

/*Printing the map.*/
void print_map(Forest forest){
	int i,j;
	for(i=0;i<forest.height;i++){
		for(j=0;j<forest.width;j++){
			if(forest.map[i][j]==tree){
				printf("# ");
			}
			else if(forest.map[i][j]==botanists){
				printf("B ");
			}
			else if(forest.map[i][j]==rare_flower){
				printf("F ");
		 	}
			else if(forest.map[i][j]==empty){
				printf("  ");
			}
		}
		printf("\n");
	}
}
/*This function uses recursion to find the rare flower. It checks if the locations
(x,y) are valid, it checks the water bottle size being equal or bigger than 0,
and checks if the botanist found the flower*/
void search(int bot_x,int bot_y,int flo_x,int flo_y,int water,int **map,Forest *forest){
	int num;
	num=1+rand()%4;
	if(map[bot_x][bot_y]==rare_flower){
		print_map(*forest);
		printf("\nI have found it on (%d,%d)!\n\n",flo_x,flo_y);
		return;
	}
	else if(water==0){
		map[bot_x][bot_y]=botanists;
		print_map(*forest);
		printf("\nHelp! I am on (%d,%d)\n\n",bot_x,bot_y);
		return;
	}
	else if(bot_x<0 && bot_x>9 && bot_y<0 && bot_y>9){
		printf("Outside forest boundries\n");
		return;
	}
	else{
	
		if(num ==1 && bot_y+1<=9 && map[bot_x][bot_y+1]!=tree){
			water--;
			map[bot_x][bot_y]=empty;
			bot_y=bot_y+1;
		}
		else if(num == 2 && bot_x+1<=9 && map[bot_x+1][bot_y]!=tree){
			water--;
			map[bot_x][bot_y]=empty;
			bot_x=bot_x+1;
		}
		else if(num == 3 && bot_y-1>=0 && map[bot_x][bot_y-1]!=tree){
			water--;
			map[bot_x][bot_y]=empty;
			bot_y=bot_y-1;
		}	
		else if(num==4 && bot_x-1>=0 && map[bot_x-1][bot_y]!=tree){
			water--;
			map[bot_x][bot_y]=empty;
			bot_x=bot_x-1;
		}
		if(water>=0){
			search(bot_x,bot_y,flo_x,flo_y,water,map,forest);
		}
	}		
}
int main(){
	srand(time(NULL));
	Botanist *botanist;
	botanist=(Botanist *)malloc(sizeof(Botanist));
	Forest *forest;
	forest=(Forest *)malloc(sizeof(Forest));
	init_game(forest,botanist);
	print_map(*forest);	
	printf("\nSearching...\n\n");
	search(botanist->coord_x,botanist->coord_y,forest->flower_x,forest->flower_y,botanist->water_bottle_size,forest->map,forest);

	for(int i=0;i<(forest->height);i++){
		free(forest->map[i]);
	}

	free(forest->map);
	free(botanist);
	free(forest);

	return 0;
}


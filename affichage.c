#include "affichage.h"

void display(Cell** p, int sizeX, int sizeY){
	/*
	A procedure that displays the game's array with colors, and according to the different conditions (hidden cell or not, etc.)
	Args :
	- sizeX : integer between 10 and 50 included
	- sizeY : integer between 10 and 50 included
	- **p : double pointer that points on an array of sizeX columns and sizeY rows

	Returns :
	None
	*/

	if((sizeX>50)||(sizeX<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	if((sizeY>50)||(sizeY<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	for (int i=0 ; i<sizeX+1 ; i++){															//Displays the first row of the table (column's number)
		if (i>9 && i%2==0){
			printf(ANSI_COLOR_CYAN "| %d |" ANSI_COLOR_RESET, i);
		}
		//We differentiate between the case where there is only one digit that appears and the case where there are two in order to to avoid gaps
		else {
			if(i%2==0){
				printf(ANSI_COLOR_CYAN"| %d |"ANSI_COLOR_RESET, i);	
			}
			else {
				printf("| %d |", i);
			}
		}
	}

	printf("\n");
	for (int j=0 ; j<sizeY; j++){																//Displays the rest of the array
		if (j<9){
			if(j%2==1){
				printf(ANSI_COLOR_CYAN"\n| %d |"ANSI_COLOR_RESET, j+1);
			}
			else {
				printf("\n| %d |", j+1);
			}
		}																						//Displays the rows number first
		//We make the same difference as before to avoid gaps
		else {
			if(j%2==1){
				printf(ANSI_COLOR_CYAN"\n|%d |"ANSI_COLOR_RESET, j+1);
			}
			else {
				printf("\n|%d |", j+1);
			}
		}
	
		for (int k=0 ; k<sizeX; k++){															//Displays the "game" part of the array
			if (k>8){
				if(p[j][k].cache == 1){	
				//Case where Cell is hidden
					if(p[j][k].flag == 1){
						//Case where a flag is on a Cell
						printf(ANSI_COLOR_RED"| F  |"ANSI_COLOR_RESET);
					}
					else{
						printf("|    |");
					}
				}
				else{
				//Case where Cell is revealed
					if(p[j][k].num!=0){
					//Case where Cell has a number on it
						printf(ANSI_COLOR_BACKRDOUD_CYAN"| %d  |"ANSI_COLOR_RESET,p[j][k].num);
					}
					else{
					//Case where there are no bombs arround the Cell
						printf(ANSI_COLOR_BACKRDOUD_BLUE "| ~  |"ANSI_COLOR_RESET);
					}
				}
			}
			//Avoiding gaps
			else {
				if(p[j][k].cache == 1){
				//Case where Cell is hidden
					if(p[j][k].flag == 1){
					//Case where a flag is on a Cell
						printf(ANSI_COLOR_RED"| F |"ANSI_COLOR_RESET);
					}
					else{
						printf("|   |");
					}
				}				
				else{
				//Case where Cell is revealed
					if(p[j][k].num!=0){
					//Case where Cell has a number on it
						printf(ANSI_COLOR_BACKRDOUD_CYAN"| %d |"ANSI_COLOR_RESET,p[j][k].num);
					}
					else{
					//Case where there are no bombs arround the Cell
						printf(ANSI_COLOR_BACKRDOUD_BLUE"| ~ |"ANSI_COLOR_RESET);
					}
				}
			}
		}
		printf("\n");
	}
}

void displayEND(Cell** p, int sizeX, int sizeY){
	/*
	A procedure that displays the game's array with colors and without hidden Cells (same operation as display())
	Args :
	- sizeX : integer between 10 and 50 included
	- sizeY : integer between 10 and 50 included
	- **p : double pointer that pointq on an array of sizeX columns and sizeY rows

	Returns :
	None
	*/

	if((sizeX>50)||(sizeX<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	if((sizeY>50)||(sizeY<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	for (int i=0 ; i<sizeX+1 ; i++){													//Displays the first line (column number)
		if (i>9){
			printf("| %d |", i);
		}
		//Avoiding the gaps
		else {
			printf("| %d |", i);
		}
	}

	printf("\n");
	for (int j=0 ; j<sizeY; j++){
		if (j>8){
			printf("\n|%d |", j+1);
		}																				//Displays the first column (row number)
		//Avoiding the gaps
		else {
			printf("\n| %d |", j+1);
		}
		for (int k=0 ; k<sizeX; k++){													//"Game" part of the array
			if (k>8){
				if(p[j][k].bomb == 1){
					printf(ANSI_COLOR_BACKRDOUD_RED"| X  |"ANSI_COLOR_RESET);			//Shows the bomb symbolized by a red X
				}
				else if(p[j][k].num!=0){
					printf("| %d  |",p[j][k].num);
				}
				//Avoiding the gaps
				else{
					printf("|    |");
				}
			}
			//Avoiding the gaps
			else {
				if(p[j][k].bomb == 1){													//Same operation as before
					printf(ANSI_COLOR_BACKRDOUD_RED"| X |"ANSI_COLOR_RESET);
				}
				else if(p[j][k].num!=0){
					printf("| %d |",p[j][k].num);
				}
				else{
					printf("|   |");
				}

			}
		}
		printf("\n");
	}
}

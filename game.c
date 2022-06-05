#include "game.h"

void show(Cell** p, int sizeX, int sizeY, int posX,int posY){
	/*
	A function that changes the status of a hidden Cell to a revealed Cell, and that also changes the status of the cells around it if it has no bombs around it

	Args :
	- posX : integer which symbolizes the row chosen by the player (no condition)
	- posY : integer qui which symbolizes the line chosen by the player (no condition)
	- sizeX : integer between 10 and 50 included
	- sizeY : integer between 10 and 50 included
	- **p : double pointer that points on an array of sizeX columns and sizeY rows

	Returns :
	None
	*/

	if ((posX<0) || (posX>sizeX-1) || (posY<0) || (posY>sizeY-1)){				//Does nothing if the location of the chosen Cell is outside the array
	}

	else if (p[posX][posY].cache==0){											//Does nothing if the cell is already revealed
	}

	else if (p[posX][posY].num!=0){												//Change the status of hidden Cell to revealed Cell if its number is non-zero
		p[posX][posY].cache=0;
	}

	else{
		p[posX][posY].cache=0;													//Changes the status of hidden Cell to revealed Cell if its number is null
		show(p, sizeX, sizeY, posX-1, posY-1);
		show(p, sizeX, sizeY, posX-1, posY);
		show(p, sizeX, sizeY, posX-1, posY+1);
		show(p, sizeX, sizeY, posX, posY-1);									//We call the function itself for the Cells around it if the cell has no bomb around it
		show(p, sizeX, sizeY, posX, posY+1);
		show(p, sizeX, sizeY, posX+1, posY-1);
		show(p, sizeX, sizeY, posX+1, posY);
		show(p, sizeX, sizeY, posX+1, posY+1);

	}
}


int menu(){
	/*
	A function that asks the player to choose what they want to do (play, view scores, or quit)
	Args :
	None

	Returns :
	- integer between 1 and 3 included
	*/
	int ch;
	printf("Que voulez-faire ? \n1.Faire une partie\n2.Voir les highscores\n3.Quitter le jeu\n\nVotre choix : ");		//Asks the player for his choice and calls the demanded program
	scanf("%d",&ch);
	return ch;
}


void game(){
	/*
	A procedure that launches the game and manages interactions with the player
	Args :
	None

	Returns :
	None
	*/
	int duck=1;
	int choice;
	int l,c;
	int dif;
  	int TIMEend,TIMEbeg;
	int cdt=0;
	int sizeX, sizeY, nbbomb;													//Initializes all the variables necessary for the game
	int i,j;
	int sortie=0;
	int ch=menu();																//Player's choice according to the menu
	if(ch==2){																	//If the player wants to see the highscores, it calls the corresponding function
		printf("Quelle difficulté voulez-vous faire apparaître ?\n(1 pour facile, 2 pour moyen, 3 pour difficile (pas de score pour custom) : ");

		scanf("%d",&dif);
		printf("\n");
		highscores(0,0,dif);
		printf("\n\n");
		game();
	}
	else if(ch==3){																	//If the player wants to quit the game, it displays a goodbye message and end the program
		printf("A bientôt !");
		exit(1);
	}
	else if(ch==1){																	//If the player chooses to start a game, it starts a game
		Cell** p=tabdifficultychoice(&sizeX,&sizeY,&nbbomb);	
		if(sizeX==9){
			dif=1;
			printf("%d",dif);
		}
		else if(sizeX==16){
			dif=2;
		}
		else if(sizeX==36){
			dif=3;
		}
		else{
			dif=0;
		}				//Initilizes the game board by calling difficultychoice()
		TIMEbeg=time(NULL);
		while (duck==1){														//Loop that continues until the game reaches a stopping condition
		
			display(p,sizeX,sizeY);												//Displays the array by calling display()
	    		
			do{
				printf("Voulez-vous révéler une cellule (1), poser/retirer un marqueur de bombe (2), ou retourner au menu (3) ?\nVotre choix : ");
				scanf("%d",&choice);
			}while ((choice>3) || (choice <1));									////Suggests to the player three game options at each turn
		
			if (choice == 1){													//In the case where the player wants to reveal a cell:
				cdt=1;
				do{
					printf("Indiquez la ligne de la cellule : ");
					scanf("%d",&l);												//Asks the player the row of the cell to reveal
					l-=1;	//Matches the player's choice with the Cell in the array (row 1 for the player is the actual row 0)
				}while ((l>sizeX) || (l <0));
	
				do{
					printf("Indiquez la colonne de la cellule : ");
					scanf("%d",&c);												//Demande au joueur la colonne de la cell à révéler
					c-=1;	//Matches the player's choice with the Cell in the array (row 1 for the player is the actual row 0)
				}while ((c>sizeY) || (c <0));
	
				if (p[l][c].flag ==1){											//Prevents the player from revealing the Cell if there is a marker on it
					printf("Impossible : il y a un marqueur sur cette cellule : retirez-le avant de dévoiler la cellule.\n");
				}
		
				else if (p[l][c].bomb ==1){										//Indicates defeat to the player and stops the loop (stopping condition)
					printf("Vous avez perdu !");
					sortie =1;
					break;
				}
				
				else{															//otherwise, reveals the Cell with the show procedure otherwise
					show(p,sizeX,sizeY,l,c);
				}
			}
		
			else if(choice==2){													//Case where the player wants to put a marker on a cell
				do{
				printf("Indiquez la ligne de la cellule : ");
				scanf("%d",&l);													//Asks the player the line of the Cell to interact with
				l-=1;	//Matches the player's choice with the Cell in the array (row 1 for the player is the actual row 0)
				}while ((l>sizeX) || (l <0));
	
				do{
				printf("Indiquez la colonne de la cellule : ");
				scanf("%d",&c);													//Asks the player the column of the Cell to interact with
				c-=1;	//Matches the player's choice with the Cell in the array (row 1 for the player is the actual row 0)
				}while ((c>sizeY) || (c <0));
	
				if (p[l][c].flag ==1){
					p[l][c].flag = 0;
				}
																				//Changes the status of the flag (1 if 0, and 0 if 1)
				else{
					p[l][c].flag =1;
				}
			}

			else{
				game();															//If the player has chosen to return to the menu, it calls the game function to restart from the menu
			}
	
			duck=0;
			for(i=0;i<sizeX;i++){
				for(j=0;j<sizeY;j++){
					if (p[i][j].cache != p[i][j].bomb || cdt==0){				//Checks at each turn of the loop if the victory condition is not met (all cells with no bombs have been revealed, and the player has revealed at least one cell)
						duck=1;													//If the condition is not verified, the duck variable remains 1 and the game continues
					}
				}
			}
      //system("clear");
					
		}
    		TIMEend=time(NULL);
		printf("\n\nVoici le tableau dévoilé : \n\n");
		displayEND(p,sizeX,sizeY);												//Displays the revealed array (call of displayEND())
		if(sortie==0){
          		int sec,min;
          		timer(&min,&sec,TIMEend-TIMEbeg);
      			printf("\nBravo ! Voici votre temps : \n%d minutes et %d secondes\n\n",min,sec);					//In a winning case, it congratulates the player and displays his time 
          		highscores(TIMEend-TIMEbeg,1,dif);
    		}
		printf("\nFin de partie.\nMerci d'avoir joué.\n");
	}

	//Verifies the choice of the menu
	else{
		printf("Erreur dans la sélection\n");
		exit(1);
	}
}

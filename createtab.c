#include "createtab.h"

Cell** tabdifficultychoice(int *sizeX,int *sizeY, int *nbbomb){
	/*
	Function that creates the part's array by using function createtab according to difficulty level chosed.

	Args :
	- *sizeX: pointer on the number of rows in the array
	- *sizeY: pointer on the number of columns in the array
	- *nbbomb: pointer on the number of bombs in the array

	Returns :
	- p : double pointeur that point on a tab of sizeX lines and sizeY columns with nbbombs (chosen by user) if difficulty is 0, 
	and a 9*9 array with 10 bombs if difficulty is 1, 
	a 20*20 array with 60 bombs if difficulty is 2,
	or a 36*36 array with 260 bombs if difficulty is 3,
	*/

	int difficulty;
	printf("\n");			//Choice of the level of difficulty
	do{
		printf("Sélectionner la difficulté avec le nombre : \nFacile : 1\nMoyen : 2\nDifficile : 3\nCustom : 0\n\nVotre choix : ");
		scanf("%d",&difficulty);
	}while ((difficulty<0) || (difficulty>3));

	printf("\n");
	int bombsmax;

	if (difficulty == 0){						//Cell for a custom array
		int lines=0, columns=0,nbbombs=0;
		printf("\n");
		printf("Rentrer les données suivantes :\n");
		while ((lines<10) || (lines>50)){								//Rows chosen between 10 and 50
			printf("\nNombre de lignes (entre 10 et 50) : ");
			scanf("%d",&lines);
			fflush(stdin);
		}
		while ((columns<10) || (columns>50)){							//Columns chosen between 10 and 50
			printf("\nNombre de colonnes (entre 10 et 50) : ");
			scanf("%d",&columns);
			fflush(stdin);
		}
		bombsmax= lines*columns;
		while ((nbbombs<1) || (nbbombs>bombsmax)){						//Bombs chosen between 1 and the total size of the array
			printf("\nNombre de bombes (entre 1 et %d) : ", bombsmax);
			scanf("%d",&nbbombs);
			fflush(stdin);
		}
		printf("\n");
		*sizeX = lines;
		*sizeY = columns;
		*nbbomb = nbbombs;
		return createtab(lines,columns,nbbombs);						//Call of createtab to build the array according to the parameters chosen by the player
	}

	else if (difficulty == 1){
		printf("\n");
		*sizeX = 9;
		*sizeY = 9; 9;														//Call of createtab with an easy difficulty level
		*nbbomb = 10;
		return createtab(9,9,10);
	}
	
	else if (difficulty == 2){
		printf("\n");
		*sizeX = 16;
		*sizeY = 16; 20;													//Call of createtab with a medium difficulty level
		*nbbomb = 40;
		return createtab(20,20,60);
	}
	
	else if (difficulty == 3){
		printf("\n");
		*sizeX = 36;
		*sizeY = 36; 36;													//Call of createtab with a hard difficulty level
		*nbbomb = 220;
		return createtab(36,36,260);
	}
	else{
		printf("Error in difficulty choice");							//Error showing up in cell there is a  problem in difficulty choice
		exit(1);
	}
}

Cell** createtab(int sizeX,int sizeY, int nbbomb){
	/*
	Function that creates the part's array with sizeX rows and sizeY columns, and randomly puts nbbomb bombs in it.

	Args :
	- sizeX : integer between 10 and 50 included
	- sizeY : integer between 10 and 50 included
	- nbbomb : integer between 1 and sizeX*sizeY included

	Returns :
	- p : double pointer that points on an array of sizeX rows and sizeY columns with nbbombs
	*/
	
	if((sizeX>50)||(sizeX<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	if((sizeY>50)||(sizeY<10)){
		printf("Erreur de taille du tableau");
		exit(1);
	}
	if((nbbomb>sizeX*sizeY)||(nbbomb<1)){
		printf("Erreur de nombre de bombes");
		exit(1);
	}
	int i,j;
	int taille=sizeX*sizeY;
	Cell **p=NULL;

	p=malloc(sizeX*sizeof(Cell*));									//Allocation of memory space for an array of sizeX arrays of Cell structures (corresponds to rows)
	if (p==NULL){
		exit(1);
	}
	
	for(i=0;i<sizeX;i++){											//Allocation of sizeY memory space for each array (corresponds to the number of columns)
		*(p+i)=malloc(sizeY*sizeof(Cell));
		if (*(p+i)==NULL){
			exit(1);
		}
	}
	
	
	int al1,al2;
	srand(time(NULL));												//Randomly fills the Cells with the number of bombs passed as a parameter
	while (nbbomb>0){
		al1 = rand()%sizeX;
		al2 = rand()%sizeY;
		if (p[al1][al2].bomb!=1){
			//We check that this Cell does not already have a bomb
			p[al1][al2].bomb=1;
			nbbomb-=1;
		}
	}
		
	for(i=0;i<sizeX;i++){											// Inititialize all caches to 1 and flags to 0
		for(j=0;j<sizeY;j++){
			p[i][j].cache=1;
			p[i][j].flag=0;
		}
	}

	putnumb(p, sizeX-1, sizeY-1);									//Calls putnomb to fill the num attribute of each cell (counts the number of bombs around)

	return p;														//Returns the double pointer to the array
}

void putnumb(Cell **p, int sizeX, int sizeY){
	/*
	Function that fills the array with the numbers (count how many bombs are around each cell).

	Args :
	- sizeX : integer between 10 and 50 included
	- sizeY : integer between 10 and 50 included
	- **p : double pointer that points on a tab of sizeX columns and sizeY rows

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
	
	int taille = sizeX * sizeY;
	int i,j;
	int b1,b2;
	
	//We fill the corners of the table by counting the number of bombs of the three Cells around
	p[0][0].num=p[1][0].bomb + p[1][1].bomb + p[0][1].bomb;																							
	p[0][sizeY].num = p[1][sizeY].bomb + p[1][sizeY-1].bomb + p[0][sizeY-1].bomb;
	p[sizeX][0].num = p[sizeX][1].bomb + p[sizeX-1][1].bomb + p[sizeX-1][0].bomb;
	p[sizeX][sizeY].num = p[sizeX-1][sizeY].bomb + p[sizeX-1][sizeY-1].bomb + p[sizeX][sizeY-1].bomb;


	//We fill the borders of the array by counting the number of bombs of the five Cells around
	for(i=1;i<sizeX;i++){
		p[0][i].num = p[0][i-1].bomb + p[0][i+1].bomb + p[1][i-1].bomb + p[1][i].bomb + p[1][i+1].bomb;
	}

	for(i=1;i<sizeY;i++){
		p[i][0].num = p[i][1].bomb + p[i-1][0].bomb + p[i-1][1].bomb + p[i+1][0].bomb + p[i+1][1].bomb;
	}

	for(i=1;i<sizeX;i++){
		p[sizeX][i].num = p[sizeX][i-1].bomb + p[sizeX][i+1].bomb + p[sizeX-1][i-1].bomb + p[sizeX-1][i].bomb + p[sizeX-1][i+1].bomb;
	}

	for(i=1;i<sizeX;i++){
		p[i][sizeY].num = p[i-1][sizeY].bomb + p[i+1][sizeY].bomb + p[i-1][sizeY-1].bomb + p[i][sizeY-1].bomb + p[i+1][sizeY-1].bomb;
	}
	
	//We fill the center of the array by counting the bombs of the eight Cells around
	for(i=1;i<sizeX;i++){
		for(j=1;j<sizeY;j++){
			p[i][j].num = p[i-1][j-1].bomb + p[i-1][j].bomb + p[i-1][j+1].bomb + p[i][j-1].bomb + p[i][j+1].bomb + p[i+1][j-1].bomb + p[i+1][j].bomb + p[i+1][j+1].bomb;
		}
	}
}

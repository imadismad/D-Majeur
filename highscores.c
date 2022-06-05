#include "highscores.h"

void highscores(int score,int use,int difficulty){
	/*
	A function that saves a new highscore by calling regScore, then displays the five highest scores

	Args :
	- score : integer superior to 0
	- use : integer between 0 and 1
	- difficulty : integer between 1 and 3 included

	Returns :
	None
	*/
	if(score<0){
		printf("Erreur de variable");
		exit(1);
	}
	if((difficulty<=0)||(difficulty>3)){
		printf("Erreur de variable");
		exit(1);
	}
	if((use>1)||(use<0)){
		printf("Erreur de variable");
		exit(1);
	}
	if(use==1){						//Calls regScore if use is 1 in order to save a score
		User user;
		printf("Entrez votre pseudo :");
		scanf("%s",user.username);
		user.score = score;
		regScore(user,difficulty);
	}
	FILE* p=NULL;
	User user;


					//Opens the file corresponding to the difficulty


	if(difficulty==1){
		p=fopen("score1.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score1.bin", "ab+");
		if(p==p2){
			//Verifies that the file isn't blank
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			//Verification
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}		
	}
	
	//Same functioning
	else if(difficulty==2){
		p=fopen("score2.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score2.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}
	}
	
	//Same functioning
	else if(difficulty==3){
		p=fopen("score3.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score3.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}
	}
		
			//Displays the file that contains the top 5 highest scores
	
	while(fread(&user, sizeof(User), 1, p)!=0){
		printf("\n%s: %d\n", user.username,user.score);
	}
	fclose(p);

}

void regScore(User user,int difficulty){
	/*
	A function that saves a new highscore by calling regScore, then displays the five highest scores

	Args :
	- user : a user from the type User with its score user.score and its username user.username
	- difficulty : integer between 1 and 3 included

	Returns :
	None
	*/
	
	if((difficulty<=0)||(difficulty>3)){
		printf("Erreur de variable");
		exit(1);
	}
	
	FILE* p=NULL;
	int position=1;
	User cow;
	int i=0, verif=0;		//Initilizes the variables that will serve the function
	int j=0;
	int scorecopy = user.score;

			//We open the binary file (to write in it) corresponding to the difficulty of the game 

	if(difficulty==1){
		p=fopen("score1.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score1.bin", "ab+");
		//Verifies that the file isn't blank, and filss it if it is
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		//Vérif
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}		
	}
	
	//Same functioning
	else if(difficulty==2){
		p=fopen("score2.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score2.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}
	}
	//Same functioning
	else if(difficulty==3){
		p=fopen("score3.bin", "rb+");
		//rewind(p);
		FILE* p2=fopen("score3.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}
	}
	
			//In custom mode, we cannot save the score as a fair comparaison isn't possible between players
	else{
		printf("Pas de high scores pour custom.\n");
		exit(1);
	}
	
	rewind(p);  //We put the stream at the beginning of the file

	while(fread(&cow, sizeof(User), 1, p)!=0){
		if(cow.score>scorecopy){		//Each time that we progress by a line, we verify if the score written is bigger than the one we want to save (the best one is the smallest) and we keep the biggest number between the 5.
			scorecopy=cow.score;
			i=j;
			verif=1;
		}
		j++;
	}

	if(verif==0){		//If none of the scores is the biggest than the one in the game, then we don't save this last one and we leave
		return ;
	}
	printf("\n");
	rewind(p);
	printf("%d",i);
	for(int k=0;k<i; k++){
		fread(&cow, sizeof(User),1, p);	//We put the stream at the beginning and we write the new score instead of the biggest one that was writen before.
	}
	fwrite(&user, sizeof(User),1, p);
	printf("\n\n");
	fclose(p);
}


#include "highscores.h"

void highscores(int score,int use,int difficulty){
	if(use==1){
		User user;
		printf("Entrez votre pseudo :");
		scanf("%s",user.username);
		user.score = score;
		regScore(user,difficulty);
	}
	FILE* p=NULL;
	User user;

	if(difficulty==1){
		p=fopen("score1.bin", "ab+");
		rewind(p);
		FILE* p2=fopen("score1.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}		
	}
	else if(difficulty==2){
		p=fopen("score2.bin", "ab+");
		rewind(p);
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
	else if(difficulty==3){
		p=fopen("score3.bin", "ab+");
		rewind(p);
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
		
	while(fread(&user, sizeof(User), 1, p)!=0){
		printf("\n%s: %d\n", user.username,user.score);
	}
	fclose(p);

}

void regScore(User user,int difficulty){
	FILE* p=NULL;
	int position=1;
	User cow;
	int i=0, verif=0;
	int j=0;
	int scorecopy = user.score;

	if(difficulty==1){
		p=fopen("score1.bin", "ab+");
		rewind(p);
		FILE* p2=fopen("score1.bin", "ab+");
		if(p==p2){
			fclose(p2);
			createfc(difficulty);
		}
		if(p==NULL){
			printf("Erreur dans l'enregistrement.\n");
			exit(1);
		}		
	}
	else if(difficulty==2){
		p=fopen("score2.bin", "ab+");
		rewind(p);
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
	else if(difficulty==3){
		p=fopen("score3.bin", "ab+");
		rewind(p);
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
	
	else{
		printf("Pas de high scores pour custom.\n");
		exit(1);
	}
	
	rewind(p);

	while(fread(&cow, sizeof(User), 1, p)!=0){
		if(cow.score>scorecopy){
			scorecopy=cow.score;
			i=j;
			verif=1;
		}
		j++;
	}

	if(verif==0){
		return ;
	}
	printf("\n");
	rewind(p);
	printf("%d",i);
	for(int k=0;k<i; k++){
		fread(&cow, sizeof(User),1, p);
	}
	fwrite(&user, sizeof(User),1, p);
	printf("\n\n");
	fclose(p);
}


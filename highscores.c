#include "highscores.h"

void highscores(int score,int use){
	if(use==1){
		User user;
		printf("Entrez votre pseudo :");
		scanf("%s",user.username);
		user.score = score;
		regScore(user);
	}
	FILE* p=NULL;
	User user;

	p=fopen("score.bin", "rb+");
		
	while(fread(&user, sizeof(User), 1, p)!=0){
		printf("\n%s: %d\n", user.username,user.score);
	}
	fclose(p);

}

void regScore(User user){
	FILE* p=NULL;
	int position=1;
	User cow;
	int i=0, verif=0;
	int j=0;
	int scorecopy = user.score;

	p=fopen("score.bin", "wb+");
	char ch =fgetc(p);
	printf("%d",ch);
	if(ch==EOF){
	createfc();
	
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

	if(verif=0){
		return ;
	}
	rewind(p);

	for(int k=0;k<i-1; k++){
		fread(&cow, sizeof(User),1, p);
	}
	fwrite(&user, sizeof(User),1, p);

	fclose(p);
}


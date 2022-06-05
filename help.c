#include <stdio.h>
#include "highscores.h"

int fc(){
	FILE* p=NULL;
	User user;

	p=fopen("score.bin", "wb+");
	user.username[0]='o';	
	user.username[1]='\0';
	user.score=1000000;
	
	fwrite(&user, sizeof(User), 1, p);
	fwrite(&user, sizeof(User), 1, p);
	fwrite(&user, sizeof(User), 1, p);
	fwrite(&user, sizeof(User), 1, p);
	fwrite(&user, sizeof(User), 1, p);

	fclose(p);
	return 0;
}

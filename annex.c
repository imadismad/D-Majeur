#include "annex.h"

void timer(int* min, int* sec, int ortime){
  *min=0;
  *sec=0;
  while(ortime>59){
    *min+=1;
    ortime-=60;
  }
  *sec=ortime;
}

void createfc(int difficulty){
    FILE* p=NULL;
    User user;

	if(difficulty==1){
		p=fopen("score1.bin", "wb+");
	}
	else if(difficulty==2){
		p=fopen("score2.bin", "wb+");	
	}
	else if(difficulty==3){
		p=fopen("score3.bin", "wb+");
	}
	else{
		("Erreur dans la création de sauvegarde");
	}
    user.username[0]='o';
    user.username[1]='\0';
    user.score=1000000;

    fwrite(&user, sizeof(User), 1, p);
    fwrite(&user, sizeof(User), 1, p);
    fwrite(&user, sizeof(User), 1, p);
    fwrite(&user, sizeof(User), 1, p);
    fwrite(&user, sizeof(User), 1, p);

    fclose(p);
    
}


/*
int flush(){
	int r,v = 0,c;
 
    	do {
        	r = scanf("%d",&v);
        	do {
        	    c = getchar();
        	}
        	while (!isspace(c) && c != EOF);
    	}
    	while (r != 1 && c != EOF);
 
    	printf("%d\n",v);
 
    	return 0;
}
*/

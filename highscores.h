#ifndef _HIGHSCORE_
#define _HIGHSCORE_
#include "doc.h"
#include "annex.h"


typedef struct{

    char username[50];

    int score;

}User;

void highscores(int use,int score);
void regScore(User user);

#endif

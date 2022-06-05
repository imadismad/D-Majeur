#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef _DOC_
#define _DOC_

typedef struct{										//Definition of the Cell's structure (bomb or not, hidden or not, the number of bombs around, a marker placed or not)
	int cache;
	int bomb;
	int num;
	int flag;
}Cell;

#endif

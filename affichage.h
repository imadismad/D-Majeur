#include "doc.h"

#ifndef _AFFICHAGE_
#define _AFFICHAGE_

#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_BLUE    "\x1b[34m"         		//Definition of "color" constants
#define ANSI_COLOR_RED     "\x1b[31m"

#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"


#define ANSI_COLOR_RESET   "\x1b[0m"

#define ANSI_COLOR_BACKRDOUD_WHITE "\e[47m"
#define ANSI_COLOR_BACKRDOUD_BLUE "\e[44m"         	//Definition of "backround color" constants
#define ANSI_COLOR_BACKRDOUD_CYAN "\e[46m"
#define ANSI_COLOR_BACKRDOUD_RED "\e[41m"
void display(Cell** p, int sizeX, int sizeY);
void displayEND(Cell** p, int sizeX, int sizeY);

#endif

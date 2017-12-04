#include "move.h"

void move(int x, int y)
{
    printf("\033[%dd\033[%dG",y,x);
}

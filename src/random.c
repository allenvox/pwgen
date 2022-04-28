#include "random.h"
#include <stdlib.h>
#include <time.h>

int getRandom(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}
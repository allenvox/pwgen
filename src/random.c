#include "random.h"
#include <stdlib.h>
#include <time.h>

int getRandom(int lower, int upper, int iteration) {
    struct timeval tv;
    timespec_get(&tv, TIME_UTC);
    unsigned long microseconds = 1000000 * tv.tv_sec + tv.tv_usec;
    srand(time(NULL) + microseconds + iteration);
    return (rand() % (upper - lower + 1)) + lower;
}
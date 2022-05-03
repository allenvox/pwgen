#include <ctest.h>
#include "random.h"

CTEST(check_random, valid)
{   
    int value = getRandom(0, 100);
    int result = value > 0 && value < 100;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
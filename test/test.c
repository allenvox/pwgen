#include "random.h"
#include <ctest.h>
#include "input.h"

CTEST(check_random, valid)
{
    int value = getRandom(0, 100);
    int result = value > 0 && value < 100;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_random, invalid)
{
    int value = getRandom(0, 100);
    int result = value < 0 || value > 100;
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_isnumber, valid)
{
    int result = isNumber("1000");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_isnumber, invalid)
{
    int result = isNumber("AVC");
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_initoptions, valid)
{
    struct Option option = initOptions();
    int result = option.size == 8 && option.capitalized == 0 && option.numeric == 0 && option.special == 0 && option.column == 0 && option.character_options == 0 && option.hash == 0;
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_initoptions, invalid)
{
    struct Option option = initOptions();
    int result = option.size != 8 || option.capitalized != 0  || option.numeric != 0 || option.special != 0 || option.column != 0 || option.character_options != 0 || option.hash != 0;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}
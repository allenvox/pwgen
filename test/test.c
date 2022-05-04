#include "random.h"
#include <ctest.h>
#include "input.h"
#include "hash.h"
#include "alphabetic.h"

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

CTEST(check_getoptions, valid)
{
    struct Option option = initOptions();
    char *argv[3];
    argv[0] = "pawg";
    argv[1] = "-sha1";
    argv[2] = "a";  
    option = getOptions(option,2,argv);
    int result = option.hash;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getoptions, invalid)
{
    struct Option option = initOptions();
    char *argv[2];
    argv[0] = "pawg";
    argv[1] = "-sha1";
    option = getOptions(option,2,argv);
    int result = option.size == 0;
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

// CTEST(check_sha1, valid)
// {
//     int result = strcmp("aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",getHashFromSeed("hello"));
//     int expected = 0; 
//     ASSERT_EQUAL(expected, result);
// }

// CTEST(check_sha1, invalid)
// {
//     int result = strcmp("aaf4c61ddcc5e8a2dabede0f3b482cdea9434d",getHashFromSeed("hello"));
//     int expected = 0; 
//     ASSERT_NOT_EQUAL(expected, result);
// }

CTEST(check_getlowercase, valid)
{
    int result = (int)getLowercase() <= 122 && (int)getLowercase() >= 97; 
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getlowercase, invalid)
{
    int result = (int)getLowercase() > 122 || (int)getLowercase() < 97; 
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getcapital, valid)
{
    int result = (int)getCapital() <= 90 && (int)getCapital() >= 65; 
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getcapital, invalid)
{
    int result = (int)getCapital() > 90 || (int)getCapital() < 65; 
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getspecial, valid)
{
    int result = (int)getSpecial() <= 47 && (int)getSpecial() >= 33; 
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getspecial, invalid)
{
    int result = (int)getSpecial() > 47 || (int)getSpecial() < 33; 
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}
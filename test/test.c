#include "random.h"
#include <ctest.h>
#include "input.h"
#include "hash.h"
#include "alphabetic.h"
#include <string.h>
#include "password.h"

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

CTEST(check_sha1, valid)
{
    int result = strcmp("aaf4c61ddcc5e8a2dabede0f3b482cd9aea9434d",getHashFromSeed("hello"));
    int expected = 0; 
    ASSERT_EQUAL(expected, result);
}

CTEST(check_sha1, invalid)
{
    int result = strcmp("aaf4c61ddcc5e8a2dabede0f3b482cdea9434d",getHashFromSeed("hello"));
    int expected = 0; 
    ASSERT_NOT_EQUAL(expected, result);
}

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

CTEST(check_getnumber, valid)
{
    int result = (int)getNumber() <= 57 && (int)getNumber() >= 48; 
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getnumber, invalid)
{
    int result = (int)getNumber() > 57 || (int)getNumber() < 48; 
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getfromalphabet, valid1)
{
    struct Option option = initOptions();
    int result = getFromAlphabet(option) >= 97 && getFromAlphabet(option) <= 122;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getfromalphabet, valid2)
{
    struct Option option = initOptions();
    option.capitalized = 1;
    option.special = 1;
    option.numeric = 1;
    char s = getFromAlphabet(option);
    int cap = s >= 65 && s <= 90;
    int low = s >= 97 && s <= 122;
    int num = s >= 48 && s <= 57;
    int spec = s >= 33 && s <= 47;
    int result = cap || low || num || spec;
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getfromalphabet, invalid1)
{
    struct Option option = initOptions();
    int result = getFromAlphabet(option) < 97 || getFromAlphabet(option) > 122;
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getfromalphabet, invalid2)
{
    struct Option option = initOptions();
    option.capitalized = 1;
    option.special = 1;
    option.numeric = 1;
    char s = getFromAlphabet(option);
    int cap = s < 65 && s > 90;
    int low = s < 97 && s > 122;
    int num = s < 48 && s > 57;
    int spec = s < 33 && s > 47;
    int result = cap && low && num && spec;
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(check_getguaranteedindex, valid)
{
    int cells[5];
    cells[0] = 1;
    cells[1] = 1;
    cells[2] = 1;
    cells[3] = 0;
    cells[4] = 1;
    int result = getGuaranteedIndex(cells,5);
    int expected = 3;
    ASSERT_EQUAL(expected,result);
}

CTEST(check_getguaranteedindex, invalid)
{
    int cells[5];
    cells[0] = 0;
    cells[1] = 0;
    cells[2] = 0;
    cells[3] = 1;
    cells[4] = 0;
    int result = getGuaranteedIndex(cells,5);
    int expected = 3;
    ASSERT_NOT_EQUAL(expected,result);
}

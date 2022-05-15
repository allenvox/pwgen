#include "alphabetic.h"
#include "input.h"
#include "random.h"
#include <stdio.h>
#include <string.h>

char getLowercase()
{
    return (char)getRandom('a', 'z');
}

char getCapital()
{
    return (char)getRandom('A', 'Z');
}

char getNumber()
{
    return (char)getRandom('0', '9');
}

char getSpecial()
{
    return (char)getRandom('!', '/');
}

char getFromAlphabet(struct Option option)
{
    char letter = '~';
    for (int i = 0; letter == '~'; i++) {
        int characterType = getRandom(1, 4);
        switch (characterType) {
        case 1:
            letter = getLowercase();
            break;
        case 2:
            if (option.capitalized == 1) {
                letter = getCapital();
            }
            break;
        case 3:
            if (option.numeric == 1) {
                letter = getNumber();
            }
            break;
        case 4:
            if (option.special == 1) {
                letter = getSpecial();
            }
            break;
        }
    }
    return letter;
}
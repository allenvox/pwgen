#include "password.h"
#include "alphabetic.h"
#include "input.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>

int getGuaranteedIndex(int* cells, int size)
{
    int guaranteed = getRandom(0, size - 1);
    if (cells[guaranteed] == 1) {
        while (cells[guaranteed] != 0) {
            int i = 1;
            guaranteed = getRandom(0, size - 1);
            i++;
        }
    }
    return guaranteed;
}

char* generatePassword(struct Option option)
{
    int size = option.size;
    char* password = malloc(sizeof(char) * size);
    int* cells = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        cells[i] = 0;
    }

    if (option.capitalized == 1) {
        int index = getGuaranteedIndex(cells, size);
        password[index] = getCapital();
    }

    if (option.numeric == 1) {
        int index = getGuaranteedIndex(cells, size);
        password[index] = getNumber();
    }

    if (option.special == 1) {
        int index = getGuaranteedIndex(cells, size);
        password[index] = getSpecial();
    }

    for (int i = 0; i < size; i++) {
        if (cells[i] == 0) {
            password[i] = getFromAlphabet(option);
        }
    }

    free(cells);
    return password;
}
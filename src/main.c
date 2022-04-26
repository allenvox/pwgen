#include "alphabetic.h"
#include "input.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* generatePassword(struct Option option)
{
    int size = option.size;
    char* password = malloc(sizeof(char) * size);
    int* cells = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        cells[i] = 0;
    }

    if (option.numeric == 0 && option.capitalized == 0 && option.special == 0) {
        for (int i = 0; i < size; i++) {
            password[i] = getLowercase(i);
        }

    } else if (option.capitalized == 1) {
        int guaranteed = getRandom(0, size - 1, 0);
        if (password[guaranteed] == 1) {
            while (password[guaranteed] != 0) {
                int i = 1;
                guaranteed = getRandom(0, size - 1, i);
                i++;
            }
        }
        password[guaranteed] = getCapital(0);
        cells[guaranteed] = 1;

        for (int i = 0; i < size; i++) {
            if (cells[i] == 0) {
                password[i] = getFromAlphabet(0, 1, 0, i);
            }
        }
    }
    free(cells);
    return password;
}

int main(int argc, char** argv)
{
    struct Option option = initOptions();
    option = getOptions(option, argc, argv);
    char* result;
    for(int i = 0; i < option.count; i++) {
        result = generatePassword(option);
        printf("%s ", result);
        if(option.column == 1 || i == option.count - 1) {
            printf("\n");
        }
    }
    free(result);
    return 0;
}
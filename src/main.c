#include "alphabetic.h"
#include "hash.h"
#include "input.h"
#include "password.h"
#include "random.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));
    struct Option option = initOptions();
    option = getOptions(option, argc, argv);
    if (option.size == 0) {
        printHelp();
        return 0;
    }
    char* result;
    if (option.hash == 1 && option.size > 40) {
        printf("\e[4mmax hash password length equals to 40 : letters after "
               "40'th won't generate\e[0m\n");
    }
    for (int i = 0; i < option.count; i++) {
        if (option.hash == 1) {
            char* hash = getHashFromSeed(option.seed);
            option.seed = hash;
            result = malloc(sizeof(char) * option.size);
            for (int j = 0; j < option.size; j++) {
                result[j] = hash[j];
            }
        } else {
            result = generatePassword(option);
        }
        printf("%s ", result);
        if (option.column == 1 || i == option.count - 1) {
            printf("\n");
        }
    }
    free(result);
    return 0;
}
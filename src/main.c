#include "alphabetic.h"
#include "input.h"
#include "random.h"
#include "password.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));
    struct Option option = initOptions();
    option = getOptions(option, argc, argv);
    char* result;
    for (int i = 0; i < option.count; i++) {
        result = generatePassword(option);
        printf("%s ", result);
        if (option.column == 1 || i == option.count - 1) {
            printf("\n");
        }
    }
    free(result);
    return 0;
}
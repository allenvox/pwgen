#include "alphabetic.h"
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
    if (option.size == -1) {
        return 0;
    }
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
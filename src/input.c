#include "input.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char* input)
{
    for (int i = 0; input[i]; i++) {
        if (isdigit(input[i]) != 1) {
            return 1;
        }
    }
    return 0;
}

struct Option initOptions()
{
    struct Option option;
    option.size = 8;
    option.count = 1;
    option.numeric = 0;
    option.capitalized = 0;
    option.special = 0;
    option.column = 0;
    return option;
}

struct Option getOptions(struct Option option, int argc, char** argv)
{
    int numargs = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-c") == 0) {
                option.capitalized = 1;
            } else if (strcmp(argv[i], "-n") == 0) {
                option.numeric = 1;
            } else if (strcmp(argv[i], "-y") == 0) {
                option.special = 1;
            } else if (strcmp(argv[i], "-s") == 0) {
                option.capitalized = 1;
                option.numeric = 1;
                option.special = 1;
            } else if (strcmp(argv[i], "-1") == 0) {
                option.column = 1;
            } else if (isNumber(argv[i]) == 0) {
                if (numargs == 0) {
                    option.count = atoi(argv[i]);
                    numargs++;
                } else {
                    option.size = atoi(argv[i]);
                }
            }
        }
    }
    return option;
}
#include "input.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHelp()
{
    printf("\n Usage: pawg [N] [L] [args...]\n");
    printf("\t(to generate N passwords with L-digit length and specific "
           "options included in args)\n\n");
    printf(" Arguments:\n");
    printf("\t-h\t  : display help\n");
    printf("\t-c\t  : include at least one uppercase letter\n");
    printf("\t-n\t  : include at least one number\n");
    printf("\t-y\t  : include at least one special character\n");
    printf("\t-s\t  : generate a secure password including all characters "
           "(alias for -c -n -y)\n");
    printf("\t-H <seed> : generate password based on sha1-hash of seed\n\n");
}

int isNumber(char* input)
{
    for (int i = 0; input[i]; i++) {
        if (!isdigit(input[i])) {
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
    option.character_options = 0;
    option.seed = malloc(sizeof(char));
    return option;
}

struct Option getOptions(struct Option option, int argc, char** argv)
{
    int numargs = 0;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-c") == 0) {
                option.capitalized = 1;
                if (option.character_options != 3) {
                    option.character_options++;
                }
            } else if (strcmp(argv[i], "-n") == 0) {
                option.numeric = 1;
                if (option.character_options != 3) {
                    option.character_options++;
                }
            } else if (strcmp(argv[i], "-y") == 0) {
                option.special = 1;
                if (option.character_options != 3) {
                    option.character_options++;
                }
            } else if (strcmp(argv[i], "-s") == 0) {
                option.capitalized = 1;
                option.numeric = 1;
                option.special = 1;
                option.character_options = 3;
            } else if (strcmp(argv[i], "-1") == 0) {
                option.column = 1;
            } else if (
                    strcmp(argv[i], "-H") == 0
                    || strcmp(argv[i], "-sha1") == 0) {
                if (argc - 1 == i) {
                    option.size = 0;
                } else if (argv[i + 1] != NULL) {
                    option.hash = 1;
                    strcpy(option.seed, argv[i + 1]);
                }
            } else if (strcmp(argv[i], "-h") == 0) {
                option.size = 0;
            } else if (isNumber(argv[i]) == 0) {
                int number = atoi(argv[i]);
                if (numargs == 0) {
                    option.count = number;
                    numargs++;
                } else {
                    option.size = number;
                }
            } else if (
                    strcmp(argv[i - 1], "-H") == 0
                    || strcmp(argv[i - 1], "-sha1") == 0) {
            } else {
                printf("\e[4mcan't recognise parameter %s : skipping it\e[0m\n",
                       argv[i]);
            }
        }
    }
    if (option.character_options > option.size) {
        printf("\e[4msize of password is less than character options you've "
               "specified\e[0m\n");
        option.size = 0;
    }
    return option;
}
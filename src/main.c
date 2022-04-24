#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STD_PASSWORD_SIZE 8

struct Option {
    int numeric;
    int capitalized;
    int special;
};

char* generatePassword(int size, struct Option option) {
    srand(time(0));
    char *password = malloc(sizeof(char) * size);
    if(option.numeric != 0 && option.capitalized != 0 && option.special != 0) {
        for(int i = 0; i < size; i++) {
            int letter = (rand()%(97-122))+97;
            password[i] = (char)letter;
        }
    }
    return password;
}

int main(int argc, char **argv)
{
    char *result = NULL;
    struct Option option;
    
    if(argc == 1) {
        option.numeric = 1;
        option.capitalized = 1;
        option.special = 1;
        result = generatePassword(STD_PASSWORD_SIZE, option);
    }

    printf("%s\n", result);
    return 0;
}
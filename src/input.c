#include "input.h"
#include <ctype.h>

int isNumber(char *input) {
    for(int i = 0; input[i]; i++) {
        if(!isdigit(input[i])) {
            return 1;
        }
    }
    return 0;
}
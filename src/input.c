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

struct Option initOptions() {
    struct Option option;
    option.size = 8;
    option.count = 1;
    option.numeric = 0;
    option.capitalized = 0;
    option.special = 0;
}
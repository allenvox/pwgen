#pragma once

struct Option {
    int numeric;
    int capitalized;
    int special;
    int size;
    int count;
};

int isNumber(char* input);
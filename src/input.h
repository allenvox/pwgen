#pragma once

struct Option {
    int numeric;
    int capitalized;
    int special;
    int size;
    int count;
    int column;
    int vowels;
    int hash;
};

int isNumber(char* input);
struct Option initOptions();
struct Option getOptions(struct Option option, int argc, char** argv);
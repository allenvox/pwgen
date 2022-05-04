#pragma once

struct Option {
    int character_options;
    int numeric;
    int capitalized;
    int special;
    int size;
    int count;
    int column;
    int hash;
    char* seed;
};

void printHelp();
int isNumber(char* input);
struct Option initOptions();
struct Option getOptions(struct Option option, int argc, char** argv);
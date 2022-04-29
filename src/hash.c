#include "hash.h"
#include "sha1.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getHashFromSeed(char* seed)
{
    unsigned char* input = (unsigned char*)seed;
    SHA1Context sha;
    uint8_t Message_Digest[20];
    int err = SHA1Reset(&sha);
    if (err) {
        printf("hash reset error\n");
    }
    err = SHA1Input(&sha, input, strlen((const char*)input));
    if (err) {
        printf("hash input error\n");
    }
    err = SHA1Result(&sha, Message_Digest);
    if (err) {
        printf("hash result error\n");
    }
    char* output = malloc(sizeof(char) * 40);
    for (int i = 0; i < 20; i++) {
        char segment[3];
        sprintf(segment, "%02x", Message_Digest[i]);
        output[i * 2] = segment[0];
        output[i * 2 + 1] = segment[1];
    }
    return output;
}
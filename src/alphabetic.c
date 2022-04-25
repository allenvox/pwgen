#include "alphabetic.h"
#include "random.h"

char getLowercase(int iteration) {
    return (char)getRandom(97,122,iteration);
}

char getCapital(int iteration) {
    return (char)getRandom(65,90,iteration);
}

char getFromAlphabet(int numeric, int capitalized, int special, int iteration) {
    if(numeric == 1 && capitalized == 1 && special == 1) {
        
    } else if(numeric == 0 && capitalized == 1 && special == 0) {
        if(getRandom(0,1,iteration) == 0) {
            return getLowercase(iteration+1);
        } else {
            return getCapital(iteration+1);
        }
    }
}
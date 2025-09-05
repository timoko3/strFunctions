#include "strFunctions.h"
#include <stdlib.h>

const char* TEST_PHRASE      = "hello";
const char* TEST_PHRASE2     = "world!";
const char CHARACTER_TO_FIND = 'l';

int main(void){
    char* copyTest;
    size_t n = 3;
    char result[20] = "hello ";
    myPuts(TEST_PHRASE);
    printf("%s\n", myStrChr(TEST_PHRASE, CHARACTER_TO_FIND));
    printf("%d\n", myStrLen(TEST_PHRASE));
    printf("%s\n", myStrCpy(copyTest, TEST_PHRASE));
    printf("%s\n", myStrNCpy(copyTest, TEST_PHRASE, n));
    printf("%s\n", myStrCat(result, TEST_PHRASE2));
    printf("%s\n", myStrNCat(result, TEST_PHRASE2, 2));
    printf("%s\n", myFGets(result, 10, stdin));
}
#include "strFunctions.h"

//#include <stdlib.h>

const char* TEST_PHRASE      = "hello";
const char* TEST_PHRASE2     = "world!";
const char CHARACTER_TO_FIND = 'l';

int main(void){
    char copyTest[50] = "window aaaaaaaaaaaaaaaa";
    char result[20]   = "hello ";
    size_t n = 3;

    // myPuts(TEST_PHRASE);

    // printf("%s\n", myStrChr(TEST_PHRASE, CHARACTER_TO_FIND));

    // printf("%d\n", myStrLen(TEST_PHRASE));

    // printf("%s\n", myStrCpy(copyTest, TEST_PHRASE));
    // printf("%s\n", myStrNCpy(copyTest, TEST_PHRASE, n));

    // printf("%s\n", myStrCat(result, TEST_PHRASE2));
    // printf("%s\n", myStrNCat(result, TEST_PHRASE2, 2));

    //printf("%s\n", myFGets(result, 10, stdin));

    // char* duplicate = myStrDup(TEST_PHRASE2);
    // printf("%s\n", duplicate);
    // free(duplicate);
    // duplicate = NULL;

    // char* line;
    // size_t bufSize = 0;
    // line = (char*) calloc(1, sizeof(char));
    // printf("%d\n", myGetLine(&line, &bufSize, stdin));
    // free(line);
    // line = NULL;
    printf("%d\n", myAtoi("vssfsf54632.1035s fs24 4546") + 5);
}
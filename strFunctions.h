#ifndef STR_FUNC
#define STR_FUNC

#include <stdio.h>

int myPuts(const char* str);

const char* myStrChr(const char* str, int ch);

size_t myStrLen(const char* start);

char* myStrCpy(char* dest, const char* src);
char* myStrNCpy(char* dest, const char* src, size_t n);

char* myStrCat(char* dest, const char* src);
char* myStrNCat(char* dest, const char* src, size_t n);

char* myFGets(char* str, int count, FILE* stream);

char* myStrDup(const char* str);

size_t myGetLine(char** lineptr, size_t* n, FILE* stream);

int mysStrCmpBeta(const char* lhs, const char* rhs);
const char* myStrStr(const char* str, const char* substr);

#endif /*STR_FUNC*/
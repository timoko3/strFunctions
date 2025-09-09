#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "strFunctions.h"

static void skipNotN(const char* str, int* curSym);
static int convertSymToInt(const char* str, int i);

int myPuts(const char* str){
    assert(str);

    int i = 0;
    while(str[i] != 0){
        putchar(str[i]);
        i++;
    }
    putchar('\n');

    return i;
}

const char* myStrChr(const char* str, int ch){
    assert(str);
    
    int i = 0;
    while(str[i] != (char)ch){
        if(str[i] == '\0'){
            return NULL;
        }
        i++;
    }

    return str + i;
}

size_t myStrLen(const char* start){
    assert(start);

    int i = 0;
    while(start[i] != '\0') i++;

    return i;
}

char* myStrCpy(char* dest, const char* src){
    assert(dest);
    assert(src);

    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    return dest;
}

char* myStrNCpy(char* dest, const char* src, size_t n){
    assert(dest);
    assert(src);

    size_t i = 0;
    while(i < n || src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char* myStrCat(char* dest, const char* src){
    assert(dest);
    assert(src);

    char* endDest = (char*) myStrChr((const char*) dest, '\0'); 
    myStrCpy(endDest, src);

    return dest;
}

char* myStrNCat(char* dest, const char* src, size_t n){
    assert(dest);
    assert(src);

    char* endDest = (char*) myStrChr((const char*) dest, '\0');
    myStrNCpy(endDest, src, n);
    
    return dest;
}

char* myFGets(char* str, int count, FILE* stream){
    assert(str);
    assert(stream);
    if(count < 1)return NULL;

    int i = 0;
    while(i < count){
        str[i] = (char)fgetc(stream);
        i++;
    }
    str[i] = '\0';

    return str;
}

char* myStrDup(const char *str){
    assert(str);

    char* newStr = (char*)calloc(myStrLen(str) + 1, sizeof(char)); 
    assert(newStr);
    
    myStrCpy(newStr, str);

    return newStr;
}

size_t myGetLine(char** lineptr, size_t* n, FILE* stream){
    assert(lineptr);
    assert(n);
    assert(stream);
    
    char ch = '\0';
    while((ch = (char)fgetc(stream)) != '\n'){
        /// +1 резерв для '\0'
        char* newPtr = (char*) realloc(*lineptr, sizeof(char) * (*n + 1));
        assert(newPtr);
        *lineptr = newPtr;

        (*lineptr)[*n] = ch;
        (*n)++;
    }
    lineptr[*n] = '\0';
    (*n)++;

    return *n;
}

int mysStrCmpBeta(const char* lhs, const char* rhs){
    size_t i = 0;
    while(rhs[i] != '\0' || lhs[i] != '\0'){ // O(min(n, m))
        if(rhs[i] == lhs[i]);
        else{
            return 0;
        }
        i++;
    }
    return 1;
}

const char* myStrStr(const char* str, const char* substr){ // O(n*m) O(n^2)
    size_t i = 0;
    const char* curStr = str;
    while(str[i] != '\0'){ // len(str)
        if(mysStrCmpBeta(curStr, substr)){ // O(len(substr))
            return curStr;
        }
        curStr++;
    }
    return NULL;
}

int myAtoi(const char* str){
    assert(str);

    int curSym = 0;
    skipNotN(str, &curSym);
    return convertSymToInt(str, curSym);
}

static void skipNotN(const char* str, int* curSym){
    assert(str);
    assert(curSym);

    while((!isdigit(str[*curSym])) && (str[*curSym] != '\0')){
        (*curSym)++;
        continue;
    }
}

static int convertSymToInt(const char* str, int i){
    assert(str);

    int result = 0;
    while(isdigit(str[i])){
        result *= 10;
        /// -'0' для перехода от символа '0' к int 0
        result += (str[i] - '0');
        i++;
    }

    return result;
}






















// atoi
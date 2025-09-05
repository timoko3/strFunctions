#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "strFunctions.h"

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
    while(start[i] != '\0')i++;

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

    if(i == n){
        dest[i] = '\0';
    }

    return dest;
}

char* myStrCat(char* dest, const char* src){
    char* endDest = (char*) myStrChr((const char*) dest, '\0'); 
    myStrCpy(endDest, src);

    return dest;
}

char* myStrNCat(char* dest, const char* src, size_t n){
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
    size_t size = sizeof(char) * (myStrLen(str)); // 

    char* newStr = (char*) malloc(size); ////////////////////
    // assert / if
    int unsigned i = 0;
    for(; i < size; i++){
        newStr[i] = str[i];
    }
    newStr[i] = '\0';
    // copy

    return newStr;
}

size_t myGetLine(char** lineptr, size_t* n, FILE* stream){
    int i = 0;
    for(; i < *n; i++){
        (*lineptr)[i] = fgetc(stream);
        if((*lineptr)[i] == '\n'){
            i++;
            (*lineptr)[i] = '\0';
            return i;
        }
    } // myFGets

    char ch;
    while((ch = fgetc(stream)) != '\n'){
        i++;
        char* newPtr = (char*) realloc(*lineptr, sizeof(char) * (i));
        // assert
        // *lineptr = (char*) realloc(*lineptr, sizeof(char) * (i));
        newPtr[i] = ch;
        *lineptr = newPtr;
    }
    i++;
    lineptr[i] = '\0';

    return i + 1;
}

// atoi
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
























// atoi
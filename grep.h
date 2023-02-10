#ifndef GREP_H_INCLUDED
#define GREP_H_INCLUDED
#include <stdio.h>
void findPattern(FILE *f, char* pattern, char* result);
void findPatternIgnoreCase(FILE *f, char* pattern, char* result);
int isSubstring(char* source,char* pattern);
#endif // GREP_H_INCLUDED
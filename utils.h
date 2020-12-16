#ifndef utils_H
#define utils_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void mutableToUpper(char* str);
char* immutableToUpper(const char* str);

void mutableToLower(char* str);
char* immutableToLower(const char* str);

void muttableEndStrip(char* str);
char* immuttableEndStrip(const char* str);

void muttableAllStrip(char* str);
char* immuttableAllStrip(const char* str);

void mutableFilter(char* str);
char* immutableFilter(const char* str);

int number(const char* str);
int word(const char* str); 

int methodEncodings(const char* type, const char* ciph);

#endif
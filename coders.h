#ifndef CODERS_H
#define CODERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Мутируемые функции
void muttableCaesarEncoder(char* str, int key);
void muttableCaesarDecoder(char* str, int key);
void muttableXorCoder(char* str, const char* pass);


// Немутируемые функции
char* immuttableCaesarEncoder(const char* str, int key);
char* immuttableCaesarDecoder(const char* str, int key);
char* immuttableXorCoder(const char* str, const char* pass);

#endif
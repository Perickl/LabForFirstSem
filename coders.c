#include "coders.h"

void muttableCaesarEncoder(char* str, int key) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = (str[i] + (key % 26));
    }
}
void muttableCaesarDecoder(char* str, int key) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = (str[i] - (key % 26));
    }
}

void muttableXorCoder(char* str, const char* pass) {
    for (int i = 0; i < strlen(str); ++i) {
	    str[i] = str[i] ^ pass[i % strlen(pass)];
    }

}

char* immuttableCaesarEncoder(const char* str, int key) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res,str);
    muttableCaesarEncoder(res,key);

    return res;
}

char* immuttableCaesarDecoder(const char* str, int key) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res,str);
    muttableCaesarDecoder(res,key);

    return res;
}

char* immuttableXorCoder(const char* str, const char* pass) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res,str);
    muttableXorCoder(res,pass);

    return res;
}
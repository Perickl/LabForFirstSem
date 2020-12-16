#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

void muttableCaesarEncoder(char* str, int key) {
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = (str[i] + (key % 26));
    }
}

char* immuttableCaesarEncoder(const char* str, int key) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res,str);
    muttableCaesarEncoder(res,key);

    return res;
}

void muttableXorCoder(char* str, const char* pass) {
    for (int i = 0; i < strlen(str); ++i) {
	    str[i] = str[i] ^ pass[i % strlen(pass)];
    }

}

char* immuttableXorCoder(const char* str, const char* pass) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res,str);
    muttableXorCoder(res,pass);

    return res;
}

int main() {
    char method[6];
    printf("Enter method (Caesar or XOR): "); 
    scanf("%s", method);
    char str[200];
    printf("Enter text: ");
    scanf("%s", str);

    if (strcmp(method, "Caesar") == 0) {
	    int key;
	    printf("Enter key: ");
	    scanf("%d", &key);
        muttableEndStrip(str);
        mutableToLower(str);
        muttableCaesarEncoder(str, key);
	    printf("%s\n", str);
    }
    if (strcmp(method, "XOR") == 0) {
	    char pass[200];
	    printf("Enter pass: ");
       	scanf("%s", pass);
        muttableEndStrip(str);
        mutableToLower(str);
        muttableXorCoder(str, pass);
        printf("%s\n", str);
    }
        
    else {
	    printf("Incorrect data");
    }

    return 0;
}
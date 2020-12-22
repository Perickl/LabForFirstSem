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

char*   argPars(int argc,char* argv[]) {
    int len = 0;

    for (int i = 2; i < argc - 1; ++i) {
        len += strlen(argv[i]) + 1;
    }
    char* str = malloc((len + 1) * (sizeof(char)));
    
    for (int i = 2; i < argc - 1; ++i) {
    strcat(str, argv[i]);
    strcat(str, " ");
    }
    return str;
}

int main(int argc, char* argv[]) {
    char* command = argv[0];
    char* method = argv[1];
    char* str = argvPars(argc, argv);
    char* key = argv[argc - 1];

    if (strcmp(method, "--caesar") == 0) {
        muttableEndStrip(str);
        mutableToLower(str);
        muttableCaesarEncoder(str,atoi(key));
	    printf("%s\n", str);
    }

    if (strcmp(method, "--xor") == 0) {
        muttableEndStrip(str);
        mutableToLower(str);
        muttableXorCoder(str, key);
        printf("%s\n", str);
    }
        
    else {
	    printf("Incorrect data");
    }
    

    return 0;
}
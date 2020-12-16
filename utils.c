#include "utils.h"

void mutableToUpper(char* str) {
    for (int i = 0; str[i]; ++i) {
        str[i] = toupper(str[i]);
    }
}

char* immutableToUpper(const char* str) {
    char* strOut = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(strOut, str);
    mutableToUpper(strOut);
    
    return strOut;
}

void mutableToLower(char* str) {
   for (int i = 0; str[i]; ++i) {
        str[i] = tolower(str[i]);
    }
}

char* immutableToLower(const char* str) {
    char* res = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(res, str);
    mutableToLower(res);

    return res;
}

void muttableEndStrip(char* str) {
    int i = 0;
    int j = strlen(str) - 1;
    while (str[i] == ' ') {
        ++i;
    }
    while (str[j] == ' ') {
        ++j;
    }
    for (int k = 0; k < j; ++k, ++i) {
        str[k] = str[i];
    }
    str[j - 1] = '\0';
}

char* immuttableEndStrip(const char* str) {
    char* strOut = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(strOut, str);
    muttableEndStrip(strOut);

    return strOut;
}

void muttableAllStrip(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	if (str[i] != ' ') {
            str[j] = str[i];
            ++j;
	    }
    }
    str[j] = '\0';
}

char* immuttableAllStrip(const char* str) {
    char* strOut = malloc((strlen(str) + 1) * sizeof(char));
    strcpy(strOut, str);
    muttableAllStrip(strOut);

    return strOut;
}

void mutableFilter(char* str) {
    int size = strlen(str);
    int j = 0;
    for (int i = 0; i < size; ++i) {
	    if (((str[i] >= 'a') && (str[i] <= 'z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))
 	        || ((str[i] >= '0') && (str[i] <= '9')) || (str[i] == ' '))
            {
	        str[j] = str[i];
	        ++j;
	    }
    }
    str[j] = '\0';
}

char* immutableFilter(const char* str) {
    char* strOut = malloc((sizeof(char) * (strlen(str) + 1)));
    strcpy(strOut, str);
    mutableFilter(strOut);
    return strOut;
}

int number(const char* str) {
    int size = strlen(str);
    int itsNumber = 0;
    while ((str[itsNumber] >= '0') && (str[itsNumber] <= '9')) {
	    ++itsNumber;
    }
    if (itsNumber == size) {
	    return 1;
    }
    else {
        return 0;
    }
}

int word(const char* str) {
    int size = strlen(str);
    int itsLetter = 0;
    while (((str[itsLetter] >= 'a') && (str[itsLetter] <= 'z'))
        || ((str[itsLetter] >= 'A') && (str[itsLetter] <= 'Z')))
    {
	    ++itsLetter;
    }
    if (itsLetter == size) {
	    return 1;
    }
    else {
	    return 0;
    }
}

int methodEncodings(const char* type, const char* ciph) {
    if (strlen(type) == strlen(ciph)) {
        return 1;
    }
    for (int i = 0; i < strlen(ciph); ++i) {
        if (type[i] == ciph[i]) {
            return 1;
        }
    }
    return 0;
}
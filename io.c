/*
IJC-DU2, příklad b)
Soubor: io.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "io.h"

int read_word(char *s, int max, FILE *f){
    char a = fgetc(f);
    if(a == EOF){
        return EOF;
    }
    ungetc(a, f);
    int len1 = 0;
    int len2 = 0;
    while((a = fgetc(f)) != EOF && !(isspace(a))){
        s[len1] = a;
        len1++;
        len2++;
        if(len1 == max){
            char tmp;
            while((tmp = fgetc(f)) != EOF){
                len2++;
                if(isspace(tmp)){
                    break;
                }
            }
            ungetc(tmp, f);
        }
    }
    s[len1] = '\0';
    return len2;
}
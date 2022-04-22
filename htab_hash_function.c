/*
IJC-DU2, příklad b)
Soubor: htab_hash_function.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include "htab_private.h"
#include <stdint.h>

size_t htab_hash_function(htab_key_t str){
    uint32_t h=0;     // musí mít 32 bitů
    const unsigned char *p;
    for(p=(const unsigned char*)str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}
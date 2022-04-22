/*
IJC-DU2, příklad b)
Soubor: htab_size.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include "htab_private.h"

size_t htab_size(const htab_t *t){
    return t->size;
}
/*
IJC-DU2, příklad b)
Soubor: htab_free.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "htab_private.h"
#include <stdlib.h>

void htab_free(htab_t *t){
    htab_clear(t);
    free(t);
}
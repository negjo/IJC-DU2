/*
IJC-DU2, příklad b)
Soubor: htab_init.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include "htab_private.h"
#include <stdlib.h>
#include <stdio.h>

htab_t *htab_init(size_t n){
    htab_t *tab;
    tab = malloc(sizeof(htab_t*) + sizeof(htab_item_t)*n);
    if(tab == NULL){
        return NULL;
    }
    tab->size = 0;
    tab->arr_size = n;
    for(size_t i = 0; i < n; i++){
        tab->data[i] = NULL;
    }
    return tab;
}
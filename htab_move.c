/*
IJC-DU2, příklad b)
Soubor: htab_move.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include "htab_private.h"

htab_t *htab_move(size_t n, htab_t *from){
    htab_t *new_tab = htab_init(n);
    if(new_tab == NULL){
        return NULL;
    }
    new_tab->size = from->size;
    for(size_t i = 0; i < n; i++){
        new_tab->data[i] = from->data[i];
        from->data[i] = NULL;
    }
    return new_tab;
}
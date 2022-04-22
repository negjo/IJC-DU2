/*
IJC-DU2, příklad b)
Soubor: htab_for_each.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "htab_private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    for(size_t i = 0; i < t->arr_size; i++){
        htab_item_t *tmp = t->data[i];
        while(tmp != NULL){
            f(&tmp->item);
            tmp = tmp->next;
        }
    }
} 
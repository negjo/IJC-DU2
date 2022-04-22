/*
IJC-DU2, příklad b)
Soubor: htab_find.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "htab_private.h"

htab_pair_t *htab_find(htab_t *t, htab_key_t key){
    size_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *tmp = t->data[index];
    htab_pair_t *result = NULL;
    while(tmp != NULL){
        if(!strcmp(tmp->item.key, key)){
            result = &tmp->item;
            break;
        }
    }
    return result;
}
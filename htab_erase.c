/*
IJC-DU2, příklad b)
Soubor: htab_erase.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "htab_private.h"
#include <stdlib.h>

bool htab_erase(htab_t *t, htab_key_t key){
    size_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *tmp = t->data[index];
    bool found = false;
    while(tmp != NULL){
        if(tmp == t->data[index]){
            if(!strcmp(tmp->item.key, key)){
                free(t->data[index]);
                free((char*)t->data[index]->item.key);
                t->data[index] = t->data[index]->next;
                found = true;
                break;
            }
        }
        if(tmp->next != NULL){
            if(!strcmp(tmp->next->item.key, key)){
                free(tmp->next);
                free((char*)tmp->next->item.key);
                tmp->next = tmp->next->next;
                found = true;
                break;
            }
        }
        tmp = tmp->next;
    }

    return found;
}
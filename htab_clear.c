/*
IJC-DU2, příklad b)
Soubor: htab_clear.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/

#include "htab_private.h"
#include <stdlib.h>

void htab_clear(htab_t *t){
    for(size_t i = 0; i < t->arr_size; i++){
        while(t->data[i] != NULL){
            if(t->data[i]->next == NULL){
                free((void*)t->data[i]->item.key);
                free(t->data[i]);
                t->data[i] = NULL;
                t->size--;
                continue;
            }
            
            htab_item_t *tmp = t->data[i];
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            free((void*)tmp->next->item.key);
            free(tmp->next);
            tmp->next = NULL;
            t->size--;
        }
    }
}
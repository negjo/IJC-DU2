/*
IJC-DU2, příklad b)
Soubor: htab_lookup_add.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include "htab_private.h"
#include <stdlib.h>


htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key){

    size_t index = (htab_hash_function(key) % t->arr_size);
    htab_item_t *tmp = t->data[index];;
    htab_pair_t *result = NULL;
    
    while(tmp != NULL){
        if(!strcmp(tmp->item.key, key)){
            result = &tmp->item;
            return result;
        }
        tmp = tmp->next;
    }

    if(t->data[index] == NULL){
        t->data[index] = malloc(sizeof(htab_item_t));
        if(t->data[index] == NULL){
            return NULL;
        }
        t->data[index]->item.key = malloc(strlen(key)*8+8);
        if(t->data[index]->item.key == NULL){
            free(t->data[index]);
            t->data[index] = NULL;
            return NULL;
        }
        strcpy((char*)t->data[index]->item.key, key);
        t->data[index]->item.value = 0;
        t->data[index]->next = NULL;
        result = &t->data[index]->item;
    }
    else{
        htab_item_t *tmp2 = t->data[index];
        while(tmp2->next != NULL){
            tmp2 = tmp2->next;
        }        
        tmp2->next = malloc(sizeof(htab_item_t));
        if(tmp2 == NULL){
            return NULL;
        }
        tmp2->next->item.key = malloc(strlen(key)*8+8);
        if(tmp2->next->item.key == NULL){
            free(tmp2->next);
            tmp2->next = NULL;
            return NULL;
        }
        strcpy((char*)tmp2->next->item.key, key);
        tmp2->next->item.value = 0;
        tmp2->next->next = NULL;
        result = &tmp2->next->item;
        
    }
    t->size++;

    return result;
}
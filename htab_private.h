/*
IJC-DU2, příklad b)
Soubor: htab_private.h
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#ifndef __HTAB_PRIVATE_H__
#define __HTAB_PRIVATE_H__

#include "htab.h"

typedef struct htab_item{
    struct htab_item *next;
    htab_pair_t item;
} htab_item_t;

struct htab{
    size_t size;
    size_t arr_size;
    htab_item_t *data[];
};
#endif
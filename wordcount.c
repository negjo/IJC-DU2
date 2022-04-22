/*
IJC-DU2, příklad b)
Soubor: wordcount.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "htab_private.h"
#include "io.h"

#define MAX_WORD_LENGTH 128

//Tuto velikost jsem zvolil protože je dostatečně velká, aby se nehromadili hodnoty a je to prvočíslo
#define HTAB_ARRAY_SIZE 25253

#ifdef HASHTEST
size_t htab_hash_function(htab_key_t str){
    int abc = 0;
    for(int i = 0; str[i] != '\0'; i++){
        abc += ((int)str[i])&((int)str[1]*666-strlen(str));
    }
    return abc;
}
#endif

void print_table(htab_pair_t *data){
    printf("%s\t%d\n", data->key, data->value);
}

int main(){
    char str[MAX_WORD_LENGTH];

    htab_t *table = htab_init(HTAB_ARRAY_SIZE);
    if(table == NULL){
        fprintf(stderr, "Nepodařilo se naalokovat paměť!\n");
        return 1;
    }
    bool warning = false;
    int len = 0;
    while((len = read_word(str, MAX_WORD_LENGTH, stdin)) != EOF){
        if(len > MAX_WORD_LENGTH && !warning){
            fprintf(stderr, "Alespoň 1 slovo překročilo maximální délku a bylo zkráceno!\n");
            warning = true;
        }
        if(str[0] != '\0'){
            htab_pair_t *pair = htab_lookup_add(table, str);
            if(pair == NULL){
                fprintf(stderr, "Nepodařilo se naalokovat paměť0!\n");
                htab_free(table);
                return 1;
            }
            pair->value++;
        }
    }

#ifdef MOVETEST
    htab_t *table2 = htab_move(HTAB_ARRAY_SIZE, table);
    htab_for_each(table2, &print_table);
    htab_free(table2);
    htab_free(table);
    return 0;
#endif

    htab_for_each(table, &print_table);
    htab_free(table);
    return 0;
}

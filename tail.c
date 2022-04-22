/*
IJC-DU2, příklad a)
Soubor: tail.c
Datum: 26.4.2021
Autor: Roman Vintoňak, xvinto00
Fakulta: FIT
Přeloženo: gcc 9.3.0
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv){
    int line_count = 10;
    FILE *file;
    bool plus = false;
    if(argc == 1){
        file = stdin;
    }
    else if(argc == 2){
        file = fopen(argv[1], "r");
        if(file == NULL){
            fprintf(stderr, "Nepodařilo se otevřít soubor %s!\n", argv[1]);
            exit(1);
        }
    }
    else if((argc == 3) && !(strcmp(argv[1], "-n"))){
        if(argv[2][0] == '+'){
            plus = true;
        }
        char *check;
        line_count = strtol(argv[2], &check, 10);
        if(strcmp(check, "")){
            fprintf(stderr, "Byly zadané nevalidní argumenty!\n");
            exit(1);
        }
        file = stdin;
    }
    else if(argc == 4){
        if(!strcmp(argv[1], "-n")){
            if(argv[2][0] == '+'){
                plus = true;
            }
            char *check;
            line_count = strtol(argv[2], &check, 10);
            if(strcmp(check, "")){
                fprintf(stderr, "Byly zadané nevalidní argumenty!\n");
                exit(1);
            }
            file = fopen(argv[3], "r");
            if(file == NULL){
                fprintf(stderr, "Nepodařilo se otevřít soubor %s!\n", argv[3]);
                exit(1);
            }
        }
        if(!strcmp(argv[2], "-n")){
            if(argv[3][0] == '+'){
                plus = true;
            }
            char *check;
            line_count = strtol(argv[3], &check, 10);
            if(strcmp(check, "")){
                fprintf(stderr, "Byly zadané nevalidní argumenty!\n");
                exit(1);
            }
            file = fopen(argv[1], "r");
            if(file == NULL){
                fprintf(stderr, "Nepodařilo se otevřít soubor %s!\n", argv[1]);
                exit(1);
            }
        }
    }
    else{
        fprintf(stderr, "Byly zadané nevalidní argumenty!\n");
        exit(1);
    }

    char current_line[512];

    if(plus){
        for(int i = 1; i < line_count; i++){
            if(fgets(current_line, 512, file) == NULL){
                return 0;
            }
            if(strchr(current_line, '\n') == NULL){
                i--;
            }
        }
        while(fgets(current_line, 512, file) != NULL){
            printf("%s", current_line);
        }
        if(file != stdin){
            fclose(file);
        }
        return 0;
    }



    char *line[line_count];

    for(int i = 0; i < line_count+1; i++){
        line[i] = calloc(512, 1);
    }
    
    bool warning = false;
    while(fgets(current_line, 512, file) != NULL){
        if(strchr(current_line, '\n') == NULL){
            if(!warning){
                fprintf(stderr, "Alespoň 1 z řádků je delší než 511 znaků a byl zkrácen!\n");
                warning = true;
            }
            current_line[510] = '\n';
            int tmp;
            while((tmp = fgetc(file)) != EOF){
                if(tmp == '\n'){
                    break;
                }
            }
        }
        for(int i = 0; i < line_count; i++){
            memmove(line[i], line[i+1], 511);
        }
        memmove(line[line_count], &current_line, 511);
    }

    for(int i = 1; i <= line_count; i++){
        printf("%s", line[i]);
        free(line[i]);
    }
    free(line[0]);
    if(file != stdin){
        fclose(file);
    }
    return 0;
}
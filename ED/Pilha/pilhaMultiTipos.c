#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INT 1
#define FLOAT 2
#define STRING 3

typedef struct tipo_de_dado{
    int tdd;
    /*tdd pode valer INT, FLOAT ou STRING dependendo do valor recebido */

    union{
        int valorInteiro;
        float valorFloat;
        char* string;
    } item;

}TDD;

typedef struct pilha{
    int top;
    TDD elementos[MAX];

}Pilha;


int main(void){

Pilha lista1;


    return 0;
}

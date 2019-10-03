#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

TAB* copia(TAB* original){
    if(!original) return NULL;
    TAB* aux = (TAB*) malloc(sizeof(TAB));
    aux->info = original->info;
    aux->dir = copia(original->dir);
    aux->esq = copia(original->esq);
    return aux;
}



int main(int argc, char const *argv[]){
    TAB* original = cria_ab(3,cria_ab(5,NULL,NULL),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    imprime_ab(original);
    TAB* copiada = copia(original);
    imprime_ab(copiada); 
    return 0;
}


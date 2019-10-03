#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

int maiorElemABB(TAB* original){
   TAB* aux = original;
   while (aux->dir) aux = aux->dir;
   return aux->info;
   
};

int menorElemABB(TAB* original){
   TAB* aux = original;
   while (aux->esq) aux = aux->esq;
   return aux->info;
   
};

int main(int argc, char const *argv[]){
    TAB* original = insere_abb(0,original);
     original = insere_abb(12,original);
     original = insere_abb(-123,original);
     original = insere_abb(400,original);
     original = insere_abb(807,original);
     
    printf("%d\n",maiorElemABB(original));
    printf("%d",menorElemABB(original));
    return 0;
}


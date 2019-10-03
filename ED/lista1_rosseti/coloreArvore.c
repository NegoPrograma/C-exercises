#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

void coloreArvore(TAB* a){
    if(!a) return;
    if(a->cor != 0 && a->cor != 1)
            a->cor = 0;
    else if(a->cor == 0){
        if(a->dir)
            a->dir->cor = 1;
        if(a->esq)
            a->esq->cor = 1;            
    } else {
        if(a->dir)
            a->dir->cor = 0;
        if(a->esq)
            a->esq->cor = 0; 
    }            
    coloreArvore(a->esq);
    coloreArvore(a->dir);            
};



int main(int argc, char const *argv[]){
    TAB* original = cria_ab(3,cria_ab(5,NULL,cria_ab(547,NULL,cria_ab(999,NULL,NULL))),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    original->cor = 0;
    coloreArvore(original);
    imprime_ab_cor(original);
    return 0;
}


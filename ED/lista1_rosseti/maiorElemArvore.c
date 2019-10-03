#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

int maiorElem(TAB* original){
    if(!original) return -1;
    int elemDir = maiorElem(original->dir);
    int elemEsq = maiorElem(original->esq);
    int atual = original->info;
    if(atual > elemDir && atual > elemEsq){
        return atual;
    } else if( elemDir > elemEsq){
        return elemDir;
    } return elemEsq;
};



int main(int argc, char const *argv[]){
    TAB* original = cria_ab(3,cria_ab(5,NULL,NULL),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    printf("%d",maiorElem(original));
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

int comparaArvores(TAB* a1,TAB* a2){
    if(!a1 && !a2) return 1;
    if(!a1) return 0;
    if(!a2) return 0;
    int atual = 0;
    if(a1->info == a2->info)
        atual = 1;
  
    return ((atual == comparaArvores(a1->esq,a2->esq)) && (atual == comparaArvores(a1->dir,a2->dir)));

};



int main(int argc, char const *argv[]){
    TAB* original = cria_ab(3,cria_ab(5,NULL,NULL),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    TAB* copia = cria_ab(3,cria_ab(5,NULL,NULL),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    printf("%d",comparaArvores(original,copia));
    return 0;
}


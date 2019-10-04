#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

TAB* retiraImpares(TAB* a){
    if(!a) return a;
    if(a->info%2 != 0)
        return retira_abb(a->info,a);
    
    a->esq = retiraImpares(a->esq);
    a->dir = retiraImpares(a->dir);
    return a;
}

int main(int argc, char const *argv[]){
    TAB* original = cria_ab(0,cria_ab(-2,cria_ab(-3,NULL,NULL),cria_ab(-1,NULL,NULL)),cria_ab(2,cria_ab(1,NULL,NULL),cria_ab(3,NULL,NULL)));
    imprime_ab(original);
    original = retiraImpares(original);
    printf("\nApós remoção de números ímpares:\n");
    imprime_ab(original);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

int contaNos(TAB* a){
    if(!a) return 0;
    return 1 + contaNos(a->esq) + contaNos(a->dir);
};



int main(int argc, char const *argv[]){
    TAB* original = cria_ab(3,cria_ab(5,NULL,NULL),cria_ab(17,cria_ab(29,NULL,NULL),NULL));
    printf("%d",contaNos(original));
    return 0;
}


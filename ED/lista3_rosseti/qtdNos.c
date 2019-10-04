#include <stdio.h>
#include <stdlib.h>
#include "TG.h"

int qtdNos(TG* g){
    int qtd = 0;
    while(g){
        qtd++;
        g = g->prox_no;
    }
    return qtd;
}

int main(){
    int i;
    TG* g;
    for(i = 0;i<10;i++){
        g = ins_no(g,i);
    }
    printf("%d",qtdNos(g));
    imprime(g);
    return 0;
}

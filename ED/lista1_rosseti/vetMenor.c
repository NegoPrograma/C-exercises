#include <stdio.h>
#include <stdlib.h>
#include "TAB_TABB.h"

int contaNos(TAB* a){
    if(!a) return 0;
    return 1 + contaNos(a->esq) + contaNos(a->dir);
};

int* vetorMenores(TAB* a,int n){
    if(a){
        int* vet;
        int tam,i,pos = 0;
        if(a->info < n){
            tam = contaNos(a);
            vet = (int*) malloc(sizeof(int)*tam);
            for(i = 0;i < tam;i++){
                vet[pos] = a->info;
                pos +=sizeof(int);
            }
        }
        return vet;
    } else
        return -1;
    
}

int main(int argc, char const *argv[]){
    TAB* original = cria_ab(0,cria_ab(-2,cria_ab(-3,NULL,NULL),cria_ab(-1,NULL,NULL)),cria_ab(2,cria_ab(1,NULL,NULL),cria_ab(3,NULL,NULL)));
    imprime_ab(original);
    int*m = vetorMenores(original,54);
    for (int*i = m; i != NULL ; i++){
        printf("%d",*i);
    }
    
    return 0;
}

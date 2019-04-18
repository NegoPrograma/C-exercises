#include <stdio.h>
#include <stdlib.h>

int main(void){

    //gerando vetor dinâmico:
    int tamanho;
    scanf("%d",&tamanho);
    int* vetor_dinamico = malloc(sizeof(int)*tamanho);
                        //malloc(bytes) => retorna void*;

    for(int i = 0; i < tamanho; i++){
        printf("%d",vetor_dinamico[i]);
    }

    free(vetor_dinamico);                     
}
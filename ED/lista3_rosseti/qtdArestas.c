#include <stdio.h>
#include <stdlib.h>
#include "TG.h"
#include "TLSE.h"

int arestaDupla(TLSE* lista,int grafo, int viz){
    TLSE*aux = lista;
    while(aux){
        if(aux->grafo == grafo && aux->viz == viz)
            return 1;
        aux = aux->prox;            
    }
    return 0;
}

int qtdArestas(TG* g){
    int qtd = 0;
    TG* aux = g;
    TVIZ* vaux;
    TLSE* adjacentes = NULL;
    for (; aux != NULL;aux = aux->prox_no){
        vaux = aux->prim_viz;
        for(; vaux != NULL; vaux = vaux->prox_viz){
            adjacentes = inserel(adjacentes,aux->id_no,vaux->id_viz);
            if(!arestaDupla(adjacentes,vaux->id_viz,aux->id_no))
                qtd++;
        }
    }
    
    return qtd;
}
  

int main(){
    int i;
    TG* g;
    for(i = 1;i<5;i++){
        g = ins_no(g,i);
    }
    ins_aresta(g,1,2);
    ins_um_sentido(g,4,1);
    ins_um_sentido(g,2,3);
    ins_um_sentido(g,2,4);
    ins_um_sentido(g,3,4);
    ins_um_sentido(g,4,3);
    printf("%d\n",qtdArestas(g));
    imprime(g);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct  lista* prox;
}Lista;

int busca(Lista* L, int elem, Lista** pre){
	Lista* aux = L->prox;
    Lista* preL = L;
	while(aux != NULL && elem > aux->info){
		preL = aux;
		aux = aux->prox;
	};
    (*pre) = preL;
	if(aux != NULL){
		if(elem == aux->info)
			return 1;
        else
		    return 0;
	};
	return 0;
};

Lista* insereElem(Lista* L, int elem){
	Lista *pre,*el;
    if(busca(L,elem,&pre))
        printf("Elemento já existe.");
    else{
        el = (Lista*)malloc(sizeof(Lista));
        el->info = elem;
        el->prox = pre->prox;
        pre->prox = el;
    }
    return L;
};


void printLista(Lista* L){
	Lista* aux = L->prox;
	while(aux != NULL){
		printf("Elemento atual:%d  Próximo endereço: %d\n",aux->info, aux->prox);
		aux = aux->prox;
	}
};



int main(int argc, char const *argv[]){
	int i = 0;
	Lista* L = (Lista*) malloc(sizeof(Lista));
	L->prox = NULL;
	for (i = 1; i < 10; i++)
		L = insereElem(L,i);

    L = insereElem(L,16);
    L = insereElem(L,0);
	printLista(L);


	
	return 0;
}
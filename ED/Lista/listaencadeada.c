#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct  lista* prox;
}Lista;

Lista* insereInicioLista(int elem, Lista* L){
	Lista* aux = (Lista*) malloc(sizeof(Lista));
	aux->info = elem;
	aux->prox = L;
	return aux;
};

int busca(Lista* L, int elem, Lista** pre){
	Lista* aux = L;
	while(aux != NULL && elem > aux->info){
		*pre = aux;
		aux = aux->prox;
	};
	printf("%d\n",aux->info);
	if(aux != NULL)
		return 1;
	return 0;
};


void printLista(Lista* L){
	Lista* aux = L;
	while(aux != NULL){
		printf("%d\n",aux->info );
		aux = aux->prox;
	}
};

Lista* insereElem(int elem, Lista* L){
	Lista* aux = L;
	Lista* pre;
	if(busca(aux,elem,&pre)){
	Lista* proximoProximo = pre->prox;
	Lista* novoElem = (Lista*) malloc(sizeof(Lista));
	novoElem->info = elem;
	pre->prox = novoElem;
	printf("%d\n",pre->info);
	novoElem->prox = proximoProximo;
	return L;
	}else{
		Lista* novoElem = (Lista*) malloc(sizeof(Lista));
		novoElem->info = elem;
		novoElem->prox = NULL;
		pre->prox = novoElem;
	}
};


int main(int argc, char const *argv[]){
	int i = 10;
	Lista* L = (Lista*) malloc(sizeof(Lista));
	L = NULL;
	for (; i > 0; i--){
		L = insereInicioLista(i,L);
	}

	L = insereElem(8,L);
	L = insereElem(11,L);
	printf("---------------------------------\n");
	printLista(L);
	return 0;
}
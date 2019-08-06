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
	*pre = NULL;
	while(aux != NULL && elem > aux->info){
		*pre = aux;
		aux = aux->prox;
	};
	if(aux != NULL){
		if(aux->info == elem)
			return 1;
		return 0;			
	}
	return 0;
};

Lista* insereElem(Lista* L, int elem){
	Lista* aux, *pre;
	aux = L;
	if(busca(aux,elem,&pre)){
		printf("Elemento não adicionado pois já está presente na lista.");
	}
	else{
		if(pre == NULL){
			Lista* novoElem = (Lista*) malloc(sizeof(Lista));
			novoElem->info = elem;
			novoElem->prox = L;
			L = novoElem;
		}else{
			printf("pre: %d\n", pre->info);
			Lista* novoElem = (Lista*) malloc(sizeof(Lista));
			novoElem->info = elem;
			novoElem->prox = pre->prox;
			pre->prox = novoElem;
		};
	return L;
	};
};


void printLista(Lista* L){
	Lista* aux = L;
	while(aux != NULL){
		printf("Elemento atual:%d  Próximo endereço: %d\n",aux->info, aux->prox);
		aux = aux->prox;
	}
};

Lista* removeElem(Lista*L,int elem){
	Lista *lixo,*pre;
	if(busca(L,elem,&pre)){
		if(pre != NULL){
			lixo = pre->prox;
			pre->prox = lixo->prox;
			}
		else{
			lixo = L;
			L = L->prox;
		}
	}
	free(lixo);
	return L;
};



int main(int argc, char const *argv[]){
	int i = 10;
	Lista* L = (Lista*) malloc(sizeof(Lista));
	L = NULL;
	for (; i > 0; i--){
		L = insereInicioLista(i,L);
	}

printf("---------------------------------\n");
	L = insereElem(L,0);
    L = insereElem(L, 16);
	printLista(L);
	printf("%d",L->info);
	L = removeElem(L,0);
	printLista(L);


	
	return 0;
}
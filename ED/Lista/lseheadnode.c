#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct  lista* prox;
}Lista;

int busca(Lista* L, int elem, Lista** pre){
	Lista* aux = L->prox;
	(*pre) = L;
	while(aux != NULL && elem > aux->info){
		(*pre) = aux;
		aux = aux->prox;
	};
	if(aux != NULL){
		if(aux->info == elem){
			return 1;
        }
        else{
		    return 0;
        };			
	};
	return 0;
};

Lista* insereElem(Lista* L, int elem){
	Lista *aux, *pre;
    aux = L;
	if(busca(aux,elem,&pre)){
		printf("Elemento não adicionado pois já está presente na lista.");
	}
	else{
			Lista* novoElem = (Lista*) malloc(sizeof(Lista));
			novoElem->info = elem;
			novoElem->prox = pre->prox;
			pre->prox = novoElem;
	};
    return L;

};


void printLista(Lista* L){
	Lista* aux = L->prox;
	while(aux != NULL){
		printf("Elemento atual:%d  Próximo endereço: %d\n",aux->info, aux->prox);
		aux = aux->prox;
	}
};

Lista* removeElem(Lista* L, int elem){
    Lista* pre, *lixo;
    if(busca(L,elem,&pre)){
        lixo = pre->prox;
        pre->prox = lixo->prox;
    }else{
        printf("elemento não existe!");
    }
    free(lixo);
    return L;
}




int main(int argc, char const *argv[]){
	int i = 0;
	Lista* L = (Lista*) malloc(sizeof(Lista));
	L->prox = NULL;
	for (i = 1; i < 10; i++)
		L = insereElem(L,i);

    L = insereElem(L,16);
    L = insereElem(L,0);
	printLista(L);
    printf("----------------------------");
    printf("----------------------------");
    printf("----------------------------");
    L = removeElem(L, 16);
    printLista(L);

//ARGH, FINALMENTE TA COMPLETA, MEU DEUS!


	
	return 0;
}
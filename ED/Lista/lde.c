#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista* prox;
	struct lista* anterior;
}Lista;

Lista* insereElem(Lista* L1, int elem){
	Lista* aux = L1;
	Lista* novoElem = (Lista*)malloc(sizeof(Lista));
	novoElem->info = elem;
    novoElem->prox = aux->prox;
    aux->prox->anterior = novoElem;
    aux->prox = novoElem;
    novoElem->anterior = aux;
	return L1;
};

int busca(Lista* L1, int elem,Lista** pre){
	Lista* aux = L1;
	*pre = NULL;
	while(aux != NULL && elem != aux->info){
		*pre = aux;
		aux = aux->prox;
	};
	if(elem == aux->info)
		return 1;
	return 0;


};


Lista* removeElem(Lista* L1,Lista* L2,int elem){
	Lista* aux = L1;
	Lista* lixo,*pre;
	if(busca(aux,elem,&pre)){
        if(pre != NULL){
            Lista *proxProx = pre->prox;
            proxProx = proxProx->prox;
            lixo = pre->prox;
            pre->prox = proxProx;
            proxProx->anterior = pre;
        }
        else{
            if(pre->anterior->prox == L2){
            L2 = L2->anterior;
            L2->prox = NULL;
                }
            else{
            L1 = L1->prox;
            L1->anterior = NULL;
                };
        }
	}else{
		printf("Elemento não está presente na Lista.\n");
	};
	free(lixo);
	return L1;
};

void imprimeLista(Lista* L1,Lista* L2){
	Lista* aux = L1;
    printf("Do inicio pro fim(esquerda até direita):\n");
	while(aux != L2){
		printf("%d ",aux->info);
		aux = aux->prox;
	};
	printf("\n");
};

void imprimeListaOposto(Lista* L2,Lista* L1){
	Lista* aux = L2;
    printf("Do fim pro começo:\n");
	while(aux != L1){
		printf("%d ",aux->info);
		aux = aux->anterior;
	};
	printf("\n");

}


int main(int argc, char const *argv[]){
	
//inicializando meus pontos iniciais:
	Lista* L1 = (Lista*) malloc(sizeof(Lista));
	Lista* L2 = (Lista*) malloc(sizeof(Lista));
	L1->prox = L2;
	L1->anterior = NULL;
	L2->prox = NULL;
	L2->anterior = L1;
    int i = 0;

	for (i = 0; i < 10; i++){
		L1 = insereElem(L1,i);
	};
	imprimeLista(L1,L2);
    imprimeListaOposto(L2,L1);
    printf("Após remover o elemento 0:\n");
    L1 = removeElem(L1,0);
    imprimeLista(L1,L2);
    imprimeListaOposto(L2,L1);

	;

	return 0;																								
}				
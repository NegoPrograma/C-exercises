#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista* prox;
	struct lista* anterior;
}Lista;

Lista* insereElem(Lista* inicio, int elem){
	Lista* aux = inicio;
	Lista *proxProx = inicio->prox;
	Lista* novoElem = (Lista*)malloc(sizeof(Lista));
	novoElem->info = elem;
	novoElem->prox = aux->prox;
	novoElem->anterior = aux;
	aux->prox = novoElem;
	proxProx->anterior = novoElem;
	return inicio;
};

int busca(Lista* inicio, int elem,Lista** pre){
	Lista* aux = inicio->prox;
	*pre = inicio;
	while(aux != inicio->anterior && elem != aux->info){
		*pre = aux;
		aux = aux->prox;
	};
	if(elem == aux->info)
		return 1;
	return 0;


};


Lista* removeElem(Lista* inicio, int elem){
	Lista* aux = inicio;
	Lista* lixo,*pre;
	if(busca(aux,elem,&pre)){
		Lista *proxProx = pre->prox;
		proxProx = proxProx->prox;
		lixo = pre->prox;
		pre->prox = proxProx;
		proxProx->anterior = pre;
	}else{
		printf("Elemento não está presente na Lista.\n");
	};
	free(lixo);
	return inicio;
};

void imprimeLista(Lista* inicio){
	Lista* aux = inicio->prox;
	while(aux != inicio->anterior){
		printf("%d ",aux->info);
		aux = aux->prox;
	};
	printf("\n");
};

void imprimeListaOposto(Lista* final){
	Lista* aux = final->anterior;
	while(aux != final->prox){
		printf("%d ",aux->info);
		aux = aux->anterior;
	};
	printf("\n");

}


int main(int argc, char const *argv[]){
	
//inicializando meus pontos iniciais:
	Lista* inicio = (Lista*) malloc(sizeof(Lista));
	Lista* final = (Lista*) malloc(sizeof(Lista));
	inicio->prox = final;
	inicio->anterior = final;
	final->prox = inicio;
	final->anterior = inicio;


	for (int i = 0; i < 11; ++i){
		inicio = insereElem(inicio,i);
	};
	imprimeLista(inicio);
	inicio = removeElem(inicio,6);
	printf("Após remoção:\n");
	imprimeLista(inicio);
	printf("Impressão oposta:\n");
	imprimeListaOposto(final);

	return 0;																								
}				
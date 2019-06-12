#include <stdlib.h>
#include <stdio.h>

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;


int pertence(Lista* L, int elem){
	Lista* aux = L->prox;
	while(aux != NULL){
		if(aux->info == elem)
			return 1;
		aux = aux->prox;
	};
	return 0;
};

Lista* insere(Lista* L,int elem){
	if(!pertence(L,elem)){
		Lista* aux = L;
		Lista* novoElem = (Lista*) malloc(sizeof(Lista));
		novoElem->info = elem;
		novoElem->prox = aux->prox;
		aux->prox = novoElem;
	};
	return L;
};

Lista* uniao(Lista* L1,Lista* L2){
	Lista* L3 =(Lista*) malloc(sizeof(Lista));
	L3->prox = NULL;
	Lista* aux1 = L1->prox,*aux2 = L2->prox;
	while(aux1 != NULL){
		L3 = insere(L3,aux1->info);
		aux1 = aux1->prox;
	};
	while(aux2 != NULL){
		if(!pertence(L3,aux2->info))
			L3 = insere(L3,aux2->info);
		aux2 = aux2->prox;
	};
	return L3;
}

Lista* intersecao(Lista* L1,Lista* L2){
	Lista* L3 =(Lista*) malloc(sizeof(Lista));
	Lista* aux1 = L1->prox,*aux2 = L2->prox;
	while(aux1 != NULL){
		if(pertence(L2,aux1->info))
			L3 = insere(L3,aux1->info);
		aux1 = aux1->prox;
	};
	while(aux2 != NULL){
		if(pertence(L1,aux2->info))
			L3 = insere(L3,aux2->info);
		aux2 = aux2->prox;
	};
	return L3;
}

void imprimeLista(Lista* L){
	Lista* aux = L->prox;
	while(aux != NULL){
		printf("%d ",aux->info);
		aux = aux->prox;
	};
	printf("\n");
};

void *apagaLista(Lista* L){
	Lista*aux = L->prox;
	Lista* lixo;
	while(aux != NULL){
		lixo = aux;
		aux = aux->prox;
		free(lixo);
	};
};


int main(int argc, char const *argv[]){
Lista* L2 =(Lista*) malloc(sizeof(Lista));
Lista* L1 =(Lista*) malloc(sizeof(Lista));
Lista* Uniao = (Lista*) malloc(sizeof(Lista));
Lista* Intersecao = (Lista*) malloc(sizeof(Lista));
L2->prox = NULL;
L1->prox = NULL;
Uniao->prox = NULL;
Intersecao->prox = NULL;
int i,opcao,elem;

for(i = 0;i< 5; i++){
	printf("Digite um elemento para L1:\n");
	scanf("%d",&elem);
	L1 = insere(L1,elem);
	printf("Digite um elemento para L2:\n");
	scanf("%d",&elem);
	L2 = insere(L2,elem);
};

printf("1: Uniao de L1 e L2\n 2: Intersecão de L1 e L2\n 3: Checar se seu elemento pertence aos conjuntos\n 4: Terminar");
	scanf("%d",&opcao);


while(opcao != 4){

switch(opcao){
	case 1:
		Uniao = uniao(L1,L2);
		printf("União: \n");
		imprimeLista(Uniao);
		break;
	case 2:
		Intersecao = intersecao(L1,L2);
		printf("Intersecão: \n");
		imprimeLista(Intersecao);
		break;
	case 3:
		printf("digite seu elemento.\n");
		scanf("%d",&elem);
		if(pertence(L1,elem))
			printf("Seu elemento pertence a L1\n");		
		if(pertence(L2,elem))
			printf("Seu elemento pertence a L2\n");
		if(!pertence(L1,elem) && !pertence(L2,elem))
			printf("elemento não está em nenhum conjunto\n");
			break;					
	case 4:
		apagaLista(L1);
		apagaLista(L2);
		apagaLista(Uniao);
		apagaLista(Intersecao);


	};

	printf("1: Uniao de L1 e L2\n 2: Intersecão de L1 e L2\n 3: Checar se seu elemento pertence aos conjuntos\n 4: Terminar");
	scanf("%d",&opcao);

};


	return 0;
}
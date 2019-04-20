#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct pilha{
    int top; 
    char elementos[MAX];
}Pilha;

Pilha* criaPilha();
int empty(Pilha* pilha);
int full(Pilha* pilha);
char pop(Pilha* pilha);
void push(Pilha* pilha,char item);
char stacktop(Pilha* pilha);

/*     

TENENBAUM: DATA STRUCTURES IN C AND C++

Exercicio 2.1.4, página 85.

verificar se determinada string x C y corresponde aos parâmetros:

2°: Y DEVE SER ESPELHO DE X, ISTO É, X[i] == Y[-i]. se vc ler um do final até o começo, vc deve achar o outro


*/


void leitura(Pilha* pilha,int n){
    char letra;
    for(int i = 0; i < n; i++){
        printf("digite uma letra para a pilha.\n");
        letra = getchar();
        getchar();
        push(pilha,letra);
        stacktop(pilha);
        }
}


int main(){
    Pilha* palavra1;
    Pilha* palavra2;
    Pilha* resultado;
    palavra1 = criaPilha();
    palavra2 = criaPilha();
    resultado = criaPilha();
    char topoPalavra2,topoResultado;

    printf("insira a primeira palavra!\n");
    leitura(palavra1,6);
    printf("insira a segunda palavra!\n");
    leitura(palavra2,6);
    
    topoPalavra2 = stacktop(palavra2);
    topoResultado = stacktop(resultado);

    if(palavra1->top != palavra2->top){
        printf("essas palavras não cumprem o requerimento");
    }else{
       while(!empty(palavra1)){
            push(resultado,pop(palavra1));
            topoResultado = stacktop(resultado);
       }
       while(topoPalavra2 == topoResultado){
           topoResultado = pop(resultado);
           topoPalavra2 = pop(palavra2);
           if(empty(palavra2)){
            printf("SIM CARAI ESSAS PALAVRA AÍ É ESPELHADA BROOO");
            break;
            }
       }
       

    }

    
    return 0;
}

Pilha* criaPilha(){
    Pilha* pilha = malloc(sizeof(Pilha));
    pilha->top = -1;
    return pilha;
}


int empty(Pilha* pilha){
    if(pilha->top == -1)
        return 1;
    else 
        return 0;   
}

int full(Pilha* pilha){
    if(pilha->top == MAX-1)
        return 1;
    else
        return 0;
    
}

char pop(Pilha* pilha){
    if(empty(pilha)){
        printf("pilha vazia!\n");
        return -1;
    }
    else{
        char element = pilha->elementos[pilha->top];
        pilha->top--;
        return element;
    }
}

void push(Pilha* pilha, char item){
    if(full(pilha)){
        printf("pilha cheia!\n Item não adicionado.\n");
    }
    else{
        pilha->top++;
        pilha->elementos[pilha->top] = item;
    }
}

char stacktop(Pilha* pilha){
    if(empty(pilha)){
        printf("pilha vazia!\n");
        return -1;
    }
    else{
        printf("%c é o item no topo da lista atualmente\n", pilha->elementos[pilha->top]);
        return pilha->elementos[pilha->top];

    }
}
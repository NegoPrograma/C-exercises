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

Exercicio 2.1.3, página 85.

verificar se determinada string x C y corresponde aos parâmetros:

1°: composta somente de A e B
2°: se x[i] == A, y[i] deve ser igual a B, e vice-versa


*/


void leitura(Pilha* pilha){
    char palavra[100];
    scanf("%s",palavra);    
    for(int i = 0; palavra[i] != '\0' ;i++){
        push( pilha,palavra[i]);
    };

};


int main(){
    Pilha* palavra1;
    Pilha* palavra2;
    palavra1 = criaPilha();
    palavra2 = criaPilha();

    printf("insira a primeira palavra!");
    leitura(palavra1);
    printf("insira a segunda palavra!");
    leitura(palavra2);

    if(palavra1->top != palavra2->top){
        printf("essas palavras não cumprem o requerimento");
    }else{
        char topoX = stacktop(palavra1);
        char topoY = stacktop(palavra2);
        while(topoX != topoY){
            pop(palavra1);
            pop(palavra2);
            topoX = stacktop(palavra1);
            topoY = stacktop(palavra2);
        }
        if(empty(palavra1)){
            printf("palavras opostas!");
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
        int element = pilha->elementos[pilha->top];
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
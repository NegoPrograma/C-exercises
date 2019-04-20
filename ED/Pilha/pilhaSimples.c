#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//estrutura básica, consiste de uma variavel pra ficar de olho no topo e outra que é efetivamente a lista
typedef struct pilha{
    int top; 
    int elementos[MAX];
}Pilha;

Pilha* criaPilha(){
    Pilha* pilha;
    pilha->top = -1;
    return pilha;
}


//verificando se a lista está vazia
int empty(Pilha* pilha){
    //por questões de eficiência e regras de sintaxe, o ideal é sempre passar um ponteiro para a struct, e não a struct em si
    if(pilha->top == -1)
        return 1;
    else 
        return 0;   
}

//verificando se a lista está cheia
int full(Pilha* pilha){
    if(pilha->top == MAX-1)
        return 1;
    else
        return 0;
    
}

//removendo um elemento da pilha
int pop(Pilha* pilha){
    if(empty(pilha)){
        printf("pilha vazia!");
        return -1;
    }
    else{
        int element = pilha->elementos[pilha->top];
        pilha->top--;
        return element;
    }
}

//adicionando um elemento da pilha
void push(Pilha* pilha, int item){
    if(full(pilha)){
        //Só um adendo, uma pilha padrão normalmente é dinâmica, não existe "pilha cheia"
        // então em teoria nós poderíamos sempre por um elemento novo,
        // porém a gente ta usando aqui uma gambiarra de array estático, 
        //por isso é necessário a checagem de slot final antes de adicionar
        printf("pilha cheia! Item não adicionado.");
    }
    else{
        pilha->top++;
        pilha->elementos[pilha->top] = item;
    }
}

//pegando o topo da lista sem remover o mesmo dela.
int stacktop(Pilha* pilha){
    if(empty(pilha)){
        printf("pilha vazia!");
        return -1;
    }
    else{
        printf("%d é o item no topo da lista atualmente", pilha->elementos[pilha->top]);
        return pilha->elementos[pilha->top];

    }
}


int main(void){

    Pilha* stack = criaPilha();
    for(int i = -1; i < MAX; i++){
        push(stack,i);
    }
    stacktop(stack);
    pop(stack);
    stacktop(stack);



    return 0;
}

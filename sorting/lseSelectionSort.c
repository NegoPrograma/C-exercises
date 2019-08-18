#include <stdio.h>
#include <stdlib.h>
#include<time.h>


typedef struct list{
    int info;
    struct list* next;
}List;

List* createList(){
    List* newList = (List*) malloc(sizeof(List));
    newList->next = NULL;
    return newList;
};

List* insertElem(List* list,int elem){
    List* newElem = createList();
    newElem->info = elem;
    newElem->next = list;
    list = newElem;
    return list;
};      

void printList(List* list){
    while(list){
        printf("%d ", list->info);
        list = list->next;
    };
    printf("\n");
};

//agora sim man, hora do trabalho mesmo.

void selectionSort(List* l){
    List* i = l,*j;
    int aux;
    for (; i != NULL; i = i->next){
        for (j = i->next; j != NULL; j= j->next){
            if(j->info < i->info){
                aux = j->info;
                j->info = i->info;
                i->info = aux;
            };
        };
    };
};


//testando números aleatórios para o sorting


int main(){
    int i;
    List* l;
    for (i = 0; i < 10; i++)
        l = insertElem(l,rand() % 100);

    printList(l);
    printf("pós sorting:\n");
    selectionSort(l);
    printList(l);
    return 0;
};

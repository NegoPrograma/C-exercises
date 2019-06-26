#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node*next;
}List;

List* insertElem(List*L,int elem){
    List* newElem = (List*) malloc(sizeof(List));
    newElem->info = elem;
    newElem->next = L;
    return newElem;
};

void printList(List* L){
    while(L != NULL){
        printf("%d ",L->info);
        L = L->next;
    }
};

void recursiveCount(List* L,int n){
    if(L == NULL){
         printf("%d",n);
    }
    else{
        recursiveCount(L->next,n+1);
    };        
};


int main(void){
    int i;
    List* L =(List*) malloc(sizeof(List));
    L = NULL;
    
    for( i=0;i > 10; i++){
        L = insertElem(L,i);
        printf("%d",L->info);  
    }
    printList(L);
    recursiveCount(L,0);

return 0;

};

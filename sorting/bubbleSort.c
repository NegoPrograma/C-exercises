#include <stdio.h>
#include <stdlib.h>

#define N 6

void bubbleSort(int vet[],int n){
int i,j,aux;
for(i = 0; i < n;i++){
    for(j = 0; j < n; j++){
        if(vet[j] > vet[i] && i > j){
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
        };
    };
};


};

int main(void){
  int i;
  int vet[] = {1,5,4,2,3,3};
  bubbleSort(vet,N);

  for (i = 0; i < N; i++)
      printf("%d ",vet[i]);
    
    return 0;
}

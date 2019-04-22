#include <stdio.h>
#include <stdlib.h>

int buscaBinariaRecursiva(int a[], int x, int inicio, int fim);

int main(void){
 int x = 9;
 int a[] = {1,3,4,5,8,9,17,18,31};
 printf("%d", buscaBinariaRecursiva(a, x,0,9));

return 0;
};

int buscaBinariaRecursiva(int a[], int x,int inicio, int fim){
  int meio = (inicio+fim)/2;
  if(inicio > fim)
     return -1;
  else{
     if(x ==a[meio])
        return meio;
     else{ 
     if(x > a[meio])
          inicio = meio;
     else
         fim = meio;
      }
   }
   return buscaBinariaRecursiva(a,x,inicio,fim);
  }
  
    

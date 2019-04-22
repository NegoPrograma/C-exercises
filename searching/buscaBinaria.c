#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int a[], int x, int lenght);

int main(void){
 int x = 31;
 int a[] = {1,3,4,5,8,9,17,18,31};
 printf("%d", buscaBinaria(a, x,9));

return 0;
};

int buscaBinaria(int a[], int x,int lenght){
  int inicio = 0;
  int final = lenght;
  int meio = (inicio+final)/2;
  while(inicio < final){
     if(x == a[meio])
        return meio;
     else{
       if(x > a[meio])
         inicio = meio;
       else
         final = meio;
     }
     meio = (inicio+final)/2;

  } 
  
}


#include <stdio.h>
#include <stdlib.h>

int i=1, soma =1;


int fat(int v){
if(i == v){
  return soma;
   }
   i++;
   soma *= i;
   fatorial(v);
   return soma;
}

int main(void){
int n;
scanf("%d", &n);
fat= fatorial(n);
printf("%d",n);

return 0;
}; 
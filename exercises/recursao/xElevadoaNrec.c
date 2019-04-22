#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int n){
  if(n == 0)
     return 1;
  else
     return(potencia(x, n-1)*x);
}

int main(void){

printf("%d", potencia(2,4));



return 0;
}; 
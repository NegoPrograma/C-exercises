#include <stdio.h>
#include <stdlib.h>


int soma(a,b){
  if(a == b){
    return b;
  }
  else{
    return(soma(a, b-1) + b);
  }
};

int main(void){

  printf("%d", soma(5,7));
return 0;
}; 
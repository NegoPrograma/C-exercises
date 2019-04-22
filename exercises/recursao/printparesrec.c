#include <stdio.h>
#include <stdlib.h>

void printPares(int n){
  if(n != 0){
      printf("  %d", n);
      printPares(n-2);
      
  }
}

int main(void){
  printPares(10);

return 0;
}; 
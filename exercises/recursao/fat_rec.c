
#include <stdio.h>
#include <stdlib.h>

int fat(int n);

int main(void){
printf("%d", fat(3));

return 0;
}; 

int fat(int n){
   if(n == 0)
      return 1;
   else{
      return ( fat(n-1) * n);
   }
}



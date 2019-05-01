
#include <stdio.h>
#include <stdlib.h>

/*

-> leia int A,B; e calcule o quociente de A/B recursivamente. existe um porém, não se pode usar o operador de divisão.

*/

int divisaoRecursiva(int A,int B,int quo){
    if(B>A){
        return quo;
    }
    else
      return divisaoRecursiva(A-B,B,quo+1);
}

int main(){
    printf("%d",divisaoRecursiva(144,12,0));

return 0;
};
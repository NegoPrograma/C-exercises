#include <stdio.h>
#include <stdlib.h>

/*

-> escreva recursivamente todos os numeros inteiros compreendidos no intervalo [a,b], em k passos(1 a 1, 2 em 2, etc)

*/

void intervaloRecursivo(int x, int y, int k){
    if(x <= y){
        printf("%d ",x);
        intervaloRecursivo(x+k,y,k);       
    }


}

int main(){
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
intervaloRecursivo(a,b,c);
return 0;
};
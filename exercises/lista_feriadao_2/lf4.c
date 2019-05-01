#include <stdio.h>
#include <stdlib.h>

/*

calcule o MDC(máximo divisor comum) de 2 numeros, normal e recursivamente.

*/

int mdcRecursivo(int x, int y){
    if(x % y == 0)
        return y;
    if(y > x)
        mdcRecursivo(y,x);
    return mdcRecursivo(y, x%y);
}

int main(){
int a,b;
scanf("%d%d",&a,&b);
printf("%d",mdcRecursivo(a,b));

return 0;
};
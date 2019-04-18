#include <stdio.h>

/*
Alocação dinâmica: SIZEOF

sizeof() é uma função que retorna o valor de bytes que x tipo de dado consome


*/

typedef struct exemplo{
int a;
double x;
char m;
}ex;

int main(){
    printf("%d\n",3*sizeof(int));
    printf("%d\n",sizeof(ex));
    return 0;
}

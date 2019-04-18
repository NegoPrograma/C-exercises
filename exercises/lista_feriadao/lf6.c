#include <stdio.h>
#include <stdlib.h>
#define AZULEIJO 1.5;
int main(int argc, char const *argv[]){
    int comprimento,largura,altura;
    scanf("%d%d%d",&comprimento,&largura,&altura);
    int areaLateral = altura*comprimento*2/AZULEIJO;
    int areaBase = largura*comprimento*2/AZULEIJO;
    int areaFace = altura*largura*2/AZULEIJO;
    int totalAzuleijo = areaBase+ areaLateral+areaFace;
    printf("Total de azuleijos necessários: %d",totalAzuleijo);

    
    return 0;

}
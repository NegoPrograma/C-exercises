#include <stdio.h>
#include <stdlib.h>

/*
enunciado: 
-> a nota de ginástica é definida num painel de 6 juizes.
-> cada juiz atribui uma nota de 0~10
->a nota final é calculada usando apenas 4 das 6 notas, sendo descartadas a nota mais alta e a mais baixa, fazendo média das 4 restantes

*/

float calculaMedia(float notas[]);

int main(){

float notasIniciais[30][6];
float notasFinais[30];
int i,j;

for( i = 0; i < 30; i++){
    for(j = 0; j < 6; j++){
        scanf("%f",&notasIniciais[i][j]);
      
    }
    notasFinais[i] = calculaMedia(notasIniciais[i]);
}

for( i = 0; i < 30; i++){
    for(j = 0; j < 6; j++){
        printf("%f ",notasIniciais[i][j]);
    }
    printf("\n");
}
    printf("\n");
    printf("\n");
    printf("\n");

for( i = 0; i < 30; i++)
    printf("%f ", notasFinais[i]);



return 0;

}

float calculaMedia(float notas[]){
    float maior, menor,media = 0.0;
    int i;
    for(i = 0; i < 6; i++){
        if(i ==0 || notas[i] > maior)
            maior = notas[i];
        if(i ==0 || notas[i] < menor)
            menor = notas[i];            
    }
    for(i = 0; i < 6; i++){
        if(notas[i] != maior && notas[i] != menor){
            media+= notas[i];
        }
    }
    return media/4;
}
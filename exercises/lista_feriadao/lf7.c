#include <stdio.h>
#include <stdlib.h>
#define COMBUSTIVEL 0.90;

int main(int argc, char const *argv[]){
    int litrosGastos;
    float moneyDosPassageiros;
    scanf("%d%f",&litrosGastos,&moneyDosPassageiros);
    float lucro = moneyDosPassageiros-litrosGastos*COMBUSTIVEL;
    printf("%.2f",lucro);
    return 0;

}
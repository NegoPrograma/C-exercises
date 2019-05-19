#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que mostre o estado que possui mais carros,
 o estado com menor numero de acidentes e 
 o total de acidentes computado

*/

typedef struct states{
 char sigla[2];
 int vehicleQuantity;
 int accidentQuantity;
}States;


int main(int argc, char const *argv[]){
    int i = 0,StatesQuantity,highestCarQuantity,totalAccidentOcurrency = 0, leastAccidentNumber;
    States* states;
    scanf("%d",&StatesQuantity);
    states = (States*) malloc(sizeof(States)*StatesQuantity);
    for (; i < StatesQuantity; i++){
        printf("Digite o estado desejado:\n");
        scanf("%s",states[i].sigla);
        
        printf("Quantos carros?\n");
        scanf("%d",&states[i].vehicleQuantity);
        
        printf("Quantos acidentes?\n");
        scanf("%d",&states[i].accidentQuantity);
        
        if(i == 0 || states[i].vehicleQuantity > highestCarQuantity)
            highestCarQuantity = states[i].vehicleQuantity;
        
        if(i == 0 || states[i].accidentQuantity < leastAccidentNumber)
            leastAccidentNumber = states[i].accidentQuantity;

        totalAccidentOcurrency += states[i].accidentQuantity;      
    }
    for (i = 0; i < StatesQuantity; i++){
        if(states[i].accidentQuantity == leastAccidentNumber)
            printf("Este estado possui o menor número de acidentes:%s \n",states[i].sigla);
        if(states[i].vehicleQuantity == highestCarQuantity)
            printf("Este estado possui o maior número de carros: %s \n",states[i].sigla);
    }
    printf("Total de acidentes ocorridos: %d",totalAccidentOcurrency);
    free(states);

    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/*
A prefeitura de uma cidade fez uma pesquisa com seus habitantes, coletando dados sobre salário, idade e número de filhos.
Faça um programa que leia os dados de 20 pessoas, e que calcule e mostre:
-média de salário, numero de filhos e o maior salário

*/

typedef struct citzens{
    float salary;
    int age;
    int numberOfChildren;

}Citzens;


int main(int argc, char const *argv[]){
    float averageSalary = 0, highestSalary = 0;
    int averageNumberOfChildren = 0, i = 0, n;
    printf("Quantos cidadãos?\n");
    scanf("%d",&n);
    Citzens* citzens = (Citzens*) malloc(sizeof(citzens)*n);
    for(;i < n;i++){
        scanf("%f",&citzens->salary);
        scanf("%d",&citzens->numberOfChildren);
        averageSalary += citzens->salary;
        averageNumberOfChildren += citzens->numberOfChildren;
        if( i == 0 || citzens->salary > highestSalary)
            highestSalary = citzens->salary;
        citzens++;
    }
    printf("A média do salário é: %f\n A média do número de filhos é: %d\nO maior salário encontrado:%f\n", averageSalary/n, averageNumberOfChildren/n,highestSalary);
    free(citzens);


    
    return 0;
}

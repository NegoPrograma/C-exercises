    
#include <stdio.h>
#include <stdlib.h>

/*
Um funcionário recebe um salário fixo mais 6% da comissão sobre suas vendas.
faça um programa que leia o salário de um funcionário, o valor total de suas vendas e apresente o seu salário final.
considere fazer isso para N funcionários.
*/

typedef struct employee{
    float salary;
    float totalAmountOfSales;
}Employee;


int main(int argc, char const *argv[]){
    int i= 0,totalEmployees;
    printf("quantos funcionários?");
    scanf("%d",&totalEmployees);
    Employee* employees = (Employee*) malloc(sizeof(Employee)*totalEmployees);
    for (; i < totalEmployees; i++){
        printf("salário?");
        scanf("%f",&employees[i].salary);
        printf("valor total de suas vendas?");
        scanf("%f",&employees[i].totalAmountOfSales);
        printf("Seu salário final do mês: %f\n", employees[i].salary+(employees[i].totalAmountOfSales*6/100));
    }
    free(employees);
    
    
    return 0;
}

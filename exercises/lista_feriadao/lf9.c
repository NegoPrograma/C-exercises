#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
int qtdEmpregados;
float comissao,salario,vendas,total;
scanf("%d%f%f",&qtdEmpregados,&vendas,&salario);
comissao = 5*100/vendas;
total = salario+ comissao/qtdEmpregados;
printf("%.2f",total);


    return 0;

}
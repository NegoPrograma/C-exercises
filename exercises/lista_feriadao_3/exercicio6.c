#include <stdio.h>
#include <stdlib.h>

typedef struct dma{
    int dia;
    int mes;
    int ano;
}Dma;

void timeDiff(Dma a, Dma b);

int main(int argc, char const *argv[]){
    Dma day1,day2;
    scanf("%d%d%d",&day1.dia,&day1.mes,&day1.ano);
    scanf("%d%d%d",&day2.dia,&day2.mes,&day2.ano);
    timeDiff(day1,day2);

    return 0;
}

void timeDiff(Dma a, Dma b){
    int yearsInDays,monthsInDays;
    int totalYear,totalMonth,totalDay;
    totalYear= b.ano - a.ano;
    yearsInDays = totalYear*365;
    if(b.mes < a.mes){
        totalMonth = a.mes - b.mes;
        }
    else{
        totalMonth = b.mes - a.mes;
    }
    monthsInDays = totalMonth*30;

    if(b.dia < a.dia){
        totalDay = a.dia - b.dia;
    }
    else{
        totalDay = b.dia - a.dia;
    }
    printf("A diferença de tempo é: %d anos, %d meses e %d dias.\n",totalYear,totalMonth,totalDay);
    printf("Esse tempo em dias: %d",totalDay+monthsInDays+yearsInDays);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){

// camboinhas = mensalidade*20;
// piratininga = camboinhas;
// itaipu = piratininga + piratininga*10/100;
// itacoatiara = itaipu;
// total = camboinhas + piratininga + itacoatiara + itaipu;
// cobertura = total*1/100;
// //após calculo da cobertura, que necessitava do total
// camboinhas += 4* cobertura;
// piratininga = camboinhas;
// itacoatiara = piratininga + piratininga*10/100;
// itaipu = itacoatiara;
// total = camboinhas + piratininga + itacoatiara + itaipu;

float total,mensalidade;
scanf("%f",&mensalidade);
total = ( ((mensalidade*20)*2) + ((mensalidade*20)*2)+(mensalidade*10/100) ) + (((mensalidade*20)*2) + ((mensalidade*20)*2)+(mensalidade*10/100))*8/100;
printf("%.2f",total);


    return 0;

}
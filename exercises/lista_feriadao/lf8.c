
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int i = 1000, primeiraMetade,segundaMetade,resultante;
    for(i; i < 9999;i++){
        primeiraMetade = i/100;
        segundaMetade = i% 100;
        resultante = primeiraMetade + segundaMetade;
        if(resultante*resultante == i)
            printf("%d\n",resultante);
    };
    return 0;

}
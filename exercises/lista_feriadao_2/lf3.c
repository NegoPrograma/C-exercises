#include <stdio.h>
#include <stdlib.h>

/*
determine se a string A ocorre dentro de string B, sendo A sucessiva ou indireta, o importante é as letras aparecerem em ordem

vide exemplo abaixo:

A = lanterna
B = no dia mais cLAro, Na noiTE mais densa, o mal sucumbiRá aNte A minha presença

veja que as letras em maíusculo, quando juntadas na ordem que apareceram, equivalem a string A.

*/

void input(char palavra[]){
    char caractere;
    int i = 0;

    while(caractere != '\n'){
        caractere = getchar();
        palavra[i] = caractere;
        i++;
    }
}


int main(){
char palavra1[60], palavra2[120];
char* stringA, *stringB;

input(palavra1);
printf("palavra 1: %s",palavra1);
fflush(stdin);
input(palavra2);
stringA = palavra1;
stringB = palavra2;

int i = 0;

for(; *stringB != '\0'; stringB++){
    if(*stringB == *stringA){
        stringA++;
        if(*stringA == '\0'){
            printf("Sim, a primeira palavra ocorre na segunda.");
            break;
        }
    }
}



return 0;
};
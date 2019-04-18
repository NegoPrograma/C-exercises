#include <stdio.h>
#include <string.h>

void concatena_str(char str1[], char str2[],int tam1,int tam2, char resultado[]);


int main(int argc, char const *argv[]){

    char palavra1[] = "meu deus ";
    char palavra2[] = "é memo é?";
    char palavrinha[50];
    concatena_str(palavra1,palavra2,strlen(palavra1),strlen(palavra2),palavrinha);

    return 0;
};


void concatena_str(char str1[], char str2[],int tam1,int tam2, char resultado[]){
    int i = 0;
    for(; i < tam1; i++){
        resultado[i] = str1[i];
    }
    
    for(int j = 0; j < tam2; j++){
        resultado[i+j] = str2[j];
    }
    printf("%s",resultado);
};

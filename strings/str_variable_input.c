#include <stdio.h>

void input(char palavra[]);

int main(){

    char palavra[100];
    char caractere;
    int i = 0;

    input(palavra);
    printf("%s",palavra);


    return 0;
}

void input(char palavra[]){
    char caractere;
    int i = 0;

    while(caractere != '\n'){
        caractere = getchar();
        palavra[i] = caractere;
        i++;
    }
}

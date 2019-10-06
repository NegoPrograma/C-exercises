#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    file = fopen("string.txt","r");
    if(file == NULL){
        printf("qual foi vacilao cade o arquivo");
        exit(0);
    }

    char frase[100];
    
    //fgets(variavel,tamanho,meio_de_entrada)
    //fgets lê toda a linha até encontrar o caracter '\n', por isso é necessario fazer um ciclo
    while(fgets(frase,100,file) != NULL){
        printf("%s\n",frase);
    }
    
    fclose(file);

    return 0;
}

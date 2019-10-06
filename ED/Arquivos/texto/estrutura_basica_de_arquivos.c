#include <stdio.h>

int main(void){

    FILE *file;
    /*fopen é o que inicia a criação/edição do arquivo
    Possíveis modos de abertura de arquivos, função fopen("caminho/arquivo.extensão",x) onde x pode ser:
    “r” Abre arquivo para leitura em modo texto. Retorna NULL caso o arquivo não exista.
    “w” Cria arquivo em modo texto para gravação. Caso o arquivo já exista, tal arquivo é sobrescrito. 
    “a” Abre arquivo em modo texto para gravação a partir de seu final. Caso o arquivo não exista, o arquivo é criado.
    “r+” Cria arquivo em modo texto para leitura ou gravação. Retorna NULL caso o arquivo não exista. 
    “w+” Cria arquivo em modo texto para atualização. Caso o arquivo já exista, tal arquivo é sobrescrito.
    “a+” Abre arquivo em modo texto para atualização a partir de seu final. Caso o arquivo não exista, o arquivo é criado. 
    
    “rb” Abre arquivo para leitura em modo binário. Retorna NULL caso o arquivo não exista. 
    “wb” Cria arquivo em modo binário para gravação. Caso o arquivo já exista, tal arquivo é sobrescrito.
    “ab” Abre arquivo em modo binário para gravação a partir de seu final. Caso o arquivo não exista, o arquivo é criado.
    “rb+” Cria arquivo em modo binário para leitura ou gravação. Retorna NULL caso o arquivo não exista.
    “wb+” Cria arquivo em modo binário para atualização. Caso o arquivo já exista, tal arquivo é sobrescrito.
    “ab+” Abre arquivo em modo binário para atualização a partir de seu final. Caso o arquivo não exista, o arquivo é criado. 
    */
    file = fopen("read.txt","w");

    //fprint(*ponteiro_de_arquivo,string);
    fprintf(file,"10 20 30");

    fclose(file);
}
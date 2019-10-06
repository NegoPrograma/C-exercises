#include <stdio.h>
#include <stdlib.h>


int main(void){
    FILE *file;
    file = fopen("string.txt","a");

    if(file != NULL){
        //fprintf escreve o texto no arquivo,não se esqueça de por o \n sempre, pois isso que define as iterações no arquivo
        fprintf(file,"Primeira linha\n");

        char frase[] = "Segunda linha\n";
        //outra função que serve para por conteúdo no arquivo, a diferença é que fputs serve somente para strings, já fprintf vc  pode por qualquer merda que vai virar string depois
        fputs(frase,file);
        //mesma coisa, só que com 1 caracter só
        fputc('a',file);
    }
    fclose(file);
}
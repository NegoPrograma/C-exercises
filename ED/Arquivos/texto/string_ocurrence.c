#include <stdio.h>
#include <stdlib.h>

int string_ocurrence(char* arq, char* word){
    FILE* file = fopen(arq,"r");
    char* aux = word;
    char actualChar;
    int count = 0,fileStatus;
    if(!arq || !word) exit(1);
    fileStatus = fscanf(file,"%c",&actualChar);
    while(fileStatus > 0){
        if(actualChar == *aux){
            aux++;
            if(*aux == '\0'){
                aux = word;
                count++;
            }
        }
        fileStatus = fscanf(file,"%c",&actualChar);
    }
    fclose(file);
    return count;
}

int main(int argc, char const *argv[]){
    printf("%d",string_ocurrence("merge.txt","9 9")); 

    return 0;
}

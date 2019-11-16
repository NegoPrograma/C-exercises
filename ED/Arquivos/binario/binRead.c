#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int i;
    int* vet = malloc(sizeof(int)*10);
    FILE* bin = fopen("binList.bin","rb");
    fread(vet,sizeof(int),3,bin);
    for(i=0; i < 3; i++){
        printf("%d",vet[i]);
    }

    return 0;
}

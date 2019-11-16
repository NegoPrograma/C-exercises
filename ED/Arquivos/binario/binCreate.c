#include <stdio.h>
#include <stdlib.h>






int main(int argc, char const *argv[]){
    int i;
    int* vet = malloc(sizeof(int)*10);
    FILE* bin = fopen("binList.bin","wb");
    for(i = 0; i < 10; i++){
        vet[i] = i;
    }
    fwrite(vet,sizeof(int),3,bin);

    return 0;
}

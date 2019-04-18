#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int eleitores, votosBrancos, votosNulos, votosValidos;
    scanf("%d%d%d%d",&eleitores,&votosBrancos,&votosNulos,&votosValidos);
    printf("Total de eleiores:\t %d\nVotos em branco:\t %d%%\nVotos Nulos:\t %d%%\nVotos Válidos:\t %d%%\n"
    ,eleitores,votosBrancos*100/eleitores,votosNulos*100/eleitores,votosValidos*100/eleitores);
    return 0;
}

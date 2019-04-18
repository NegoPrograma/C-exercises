#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
    int votosGancho, votosPan, votosWendy,votosNulos,votosBrancos;
    long int totalDeVotos = 0;
    scanf("%d%d%d%d%d",&votosGancho,&votosPan,&votosWendy,&votosBrancos,&votosNulos);
    totalDeVotos = votosGancho + votosPan + votosWendy + votosBrancos + votosNulos;
     printf("Votos Gancho:\t %ld%%\nVotos em branco:\t %ld%%\nVotos Nulos:\t %ld%%\nVotos Peter:\t %ld%%\nVotos Wendy:\t %ld%%\n"
    ,votosGancho*100/totalDeVotos,votosBrancos*100/totalDeVotos,votosNulos*100/totalDeVotos, votosPan*100/totalDeVotos,votosWendy*100/totalDeVotos);
    
    return 0;

}

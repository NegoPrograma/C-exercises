#include <stdio.h>
#include <stdlib.h>

//int fseek(FILE *stream, long int offset, int whence);
//long int ftell(FILE *stream);
//void rewind(FILE *stream);

int prox_mult(int elem, int pot){
  int resp = 0;
  while(resp <= elem) resp += pot;
  return resp;
}

int bb(FILE *fp, int elem, int tipo){
  int ini, fim, meio, elem_meio;

  rewind(fp);
  ini = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  fim = ftell(fp) - tipo;

  while(ini <= fim){
    meio = (fim + ini) / 2;
    if((meio % tipo) != 0) meio = prox_mult(meio, tipo);
    rewind(fp);
    fseek(fp, meio, SEEK_SET);
    fread(&elem_meio, tipo, 1, fp);
    printf("ini = %d\tfim = %d\tmeio = %d\telem = %d\n", ini, fim, meio, elem_meio);
    if(elem_meio == elem) return meio;
    if(elem_meio < elem) ini = meio + tipo;
    if(elem_meio > elem) fim = meio - tipo;
  }

  return -1;
}

int main (int argc, char** argv) {
    while(1){
        FILE *fp = fopen(argv[1], "wb");
        if(!fp) exit (1);
        int n;
        printf("Digite o tamanho do vetor.\n");
        scanf("%d", &n);
        if( n<= 0) exit (1); // se vetor não tem nenhuma posição sai do programa
        int i=1, vet[n];
        scanf("%d", &vet[0]); //criando a primeira posição do vetor ordenado, não entram numeros menores do que seu antecessor
        while(i < n){
            int aux;
            scanf("%d", &aux);
            if(aux > vet[i-1]) //se o valor for maior do o primeiro ele armazena, senão é descartado.
                vet[i++] = aux;
        }
        fwrite(vet, sizeof(int), n, fp); //escrevendo o vetor ordenado no arquivo que voce abriu
        fclose(fp);
        int elem;
        printf("Digite o valor a ser procurado.\n");
        scanf("%d", &elem);
        fp = fopen(argv[1], "rb");
        int pos = bb (fp, elem, sizeof(int)); //procurando o elemento na posição
        fclose(fp);
        if (pos >= 0)
            printf("%d\n", pos/4); //imprimindo a posição (/4) do vetor de inteiros em que o elemento foi encontrado
        else
            printf("Elemento nao encontrado.\n");
    }
}

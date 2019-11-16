#include <stdio.h>
#include <stdlib.h>

void qs_aux(char *nome, int tipo, int ini, int fim);

void qs(char *nome, int tipo){
  FILE *fp = fopen(nome, "rb");
  if(!fp) exit(1);
  int ini, fim;
  ini = ftell(fp);
  fseek(fp, 0L, SEEK_END);
  fim = ftell(fp);
  fclose(fp);
  qs_aux(nome, tipo, ini, fim);
}

void qs_aux(char *nome, int tipo, int ini, int fim){
  if((fim - ini) <= tipo) return;

  FILE *fp = fopen(nome, "rb+");
  if(!fp) exit(1);

  int a, b, r, x, elem, aux_a, aux_b;
  a = ini;
  fseek(fp, a, SEEK_SET);
  fread(&x, tipo, 1, fp);
  a = ftell(fp);
  b = fim - tipo;

  //printf("x = %d\ta = %d\tb = %d\n", x, a, b);
  int i, aux, aux_pos;
  do{

    fseek(fp, a, SEEK_SET);
    while(a < fim){
      r = fread(&elem, tipo, 1, fp);
      a = ftell(fp);
      if((elem > x) || (r != 1)) break;
    }
    if(elem > x){
      aux_a = elem; //armazeno o valor que esta no endereco a
      a = a - tipo;
      //printf("aux_a = %d ", aux_a);
    }
    else a = fim + tipo;
    //printf("a = %d\n", a);

    int acc = -tipo;
    rewind(fp);
    fseek(fp, fim, SEEK_SET);
    fseek(fp, acc, SEEK_CUR);
    while(1){
      r = fread(&elem, tipo, 1, fp);
      //printf("%d %d %d\n", b, elem, r);
      if((elem <= x) || (r != 1)) break;
      b = b - tipo;
      acc = acc - tipo;
      fseek(fp, fim, SEEK_SET);
      fseek(fp, acc, SEEK_CUR);
    }
    if(elem < x){
      aux_b = elem; //armazeno o valor que esta no endereco a
    }
    else{
      aux_b = x;
      b = ini;
    }
    //printf("aux_b = %d\tb = %d\n", aux_b, b);

    if(a < b){
      printf("Trocar %d(%d) por %d(%d)\n", aux_a, a, aux_b, b);
      fseek(fp, b, SEEK_SET);      //posiciono o arquivo na posicao a
      fwrite(&aux_a, tipo, 1, fp); //escrevo o valor de a na posicao b
      fseek(fp, a, SEEK_SET);      //posiciono o arquivo na posicao a
      fwrite(&aux_b, tipo, 1, fp); //escrevo o valor de b na posicao a
      a = ftell(fp);
      b = fim - tipo;
      //printf("a = %d\tb = %d\n", a, b);
    }

  }while (a <= b);

  printf("Trocar pivo = %d(%d) por %d(%d)\n", x, ini, aux_b, b);
  rewind(fp);
  a = ini;
  fseek(fp, a, SEEK_SET);
  fwrite(&aux_b, tipo, 1, fp);
  rewind(fp);
  fseek(fp, b, SEEK_SET);
  fwrite(&x, tipo, 1, fp);

  fclose(fp);

  //printf("(%d,%d)\t(%d,%d)\n", ini, b, (b + tipo), fim);
  qs_aux(nome, tipo, ini, b);
  qs_aux(nome, tipo, (b + tipo), fim);
}

int main(int argc, char** argv){
  //while(1){
    int n;
    scanf("%d", &n);
    if(n <= 0) return 0;
    int i, vet[n];
    scanf("%d", &vet[0]);
    i = 1;
    while (i < n){
      int j, aux;
      scanf("%d", &aux);
      for(j = 0; j < i; j++)
         if (vet[j] == aux) break;

      if(j == i) vet[i++] = aux;
    }

    char nome[31];
    scanf("%s", nome);
    FILE *fp = fopen(nome, "wb");
    if(!fp) exit(1);
    fwrite(vet, sizeof(int), n, fp);
    fclose(fp);

    for(i = 0; i < n; i++) printf("%d ", vet[i]);
    printf("\n");

    qs(nome, sizeof(int));

    int resp[n];
    fp = fopen(nome, "rb");
    if(!fp) exit(1);
    fread(resp, sizeof(int), n, fp);
    fclose(fp);

    for(i = 0; i < n; i++) printf("vet[%d] = %d -> resp[%d] = %d\n", i, vet[i], i, resp[i]);
  //}    
}

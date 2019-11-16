#include <stdio.h>
#include <stdlib.h>

//int fseek(FILE *stream, long int offset, int source);
//long int ftell(FILE *stream);
//void rewind(FILE *stream);

void selSortBin(FILE *fp){
  int i, j, r, s, elem_menor, menor, elem, aux;

  i = ftell(fp);
  r = fread(&elem_menor, sizeof(int), 1, fp);
  while(r == 1){
    menor = i;
    aux = elem_menor;
    j = ftell(fp);
    s = fread(&elem, sizeof(int), 1, fp);
    while(s == 1){
      if(elem < elem_menor){
        menor = j;
        elem_menor = elem;
      }
      j = ftell(fp);
      s = fread(&elem, sizeof(int), 1, fp); 
    }
    if(menor != i){
      printf("Trocar %d(%d) por %d(%d)\n", aux, i, elem_menor, menor);
      rewind(fp);
      fseek(fp, menor, SEEK_SET);
      fwrite(&aux, sizeof(int), 1, fp);
      rewind(fp);
      fseek(fp, i, SEEK_SET);
      fwrite(&elem_menor, sizeof(int), 1, fp);
    }
    else{
      rewind(fp);
      fseek(fp, (i + sizeof(int)), SEEK_SET);
    }

    i = ftell(fp);
    r = fread(&elem_menor, sizeof(int), 1, fp);
  } 
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

    fp = fopen(nome, "rb+");
    if(!fp) exit(1);
    selSortBin(fp);
    fclose(fp);

    int resp[n];
    fp = fopen(nome, "rb");
    if(!fp) exit(1);
    fread(resp, sizeof(int), n, fp);
    fclose(fp);

    for(i = 0; i < n; i++) printf("vet[%d] = %d -> resp[%d] = %d\n", i, vet[i], i, resp[i]);
  //}    
}

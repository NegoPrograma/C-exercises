#include <stdio.h>
#include <stdlib.h>
#include "avh.h"

int main(void) {
char* p = (char*) malloc(sizeof(char)*100);
 printf("digite o nome do arquivo de entrada.");
 scanf(" %[^\n]",p);
 leitura(p);


  return 0;
}

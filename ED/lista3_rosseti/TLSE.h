#include <stdio.h>
#include <stdlib.h>

typedef struct lse{
  int grafo;
  int viz;
  struct lse *prox;
} TLSE;

TLSE* inserel(TLSE *l, int grafo,int viz);
void imprimel(TLSE *l);
void liberal(TLSE *l);
TLSE* retiral(TLSE *l, int elem);
TLSE* buscal(TLSE *l, int elem);


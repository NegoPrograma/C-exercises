#include "TLSE.h"

TLSE* inserel(TLSE *l, int grafo,int viz){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->grafo = grafo;
  novo->viz = viz;
  return novo;
}

void imprimel(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("% d ", p->grafo
);
    p = p->prox;
  } 
}

void liberal(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLSE* retiral(TLSE *l, int grafo){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->grafo != grafo)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* buscal(TLSE *l, int grafo){
  TLSE *p = l;
  while((p) && (p->grafo != grafo)) p = p->prox; 
  return p;
}


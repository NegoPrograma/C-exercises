#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodear{
    char l;
    float f;
    int v;
    int c;
}NO;

typedef struct ArvB{
  NO** chave;
  int nchaves,folha;
  struct ArvB **filho;
}TAB;
void decodifica_TAB(TAB* a);
TAB* remover(TAB* arv, char ch, int t);
void Escreve_aux(int *e,char *nome);
void rastreia_cod(TAB* x, char ch);
TAB* retira(TAB* arv, char k, int t);
TAB *Inicia_arquivo(TAB *a,int t,FILE* fp);
void Imprime(TAB *a, int andar);
TAB *Insere(TAB *T, char k,float f,int c,int v, int t);
TAB* Insere_Nao_Completo(TAB *x, char k,float f,int c,int v, int t);
TAB* Cria(int t);
NO* CriaNo(char l,float f,int v, int c);
TAB* Divisao(TAB* a,int ind,TAB*f,int t);
void Libera(TAB* a);
TAB* Busca(TAB* x, char ch);
void Escreve_arqui(TAB*a);
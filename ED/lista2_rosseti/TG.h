#include <stdlib.h>
#include <stdio.h>

typedef struct viz {
	int id_viz;
	struct viz *prox_viz;
}TVIZ;

typedef struct grafo{
	int id_no;
	TVIZ *prim_viz;
	struct grafo *prox_no;
}TG;


TG *inicializa();
void imprime(TG *g);
void libera(TG *g);
TG* busca_no(TG* g, int x);
TVIZ* busca_aresta(TG *g, int no1, int no2);
TG *ins_no(TG *g, int x);
void ins_aresta(TG *g, int no1, int no2);
void retira_aresta(TG *g ,int no1, int no2);
TG *retira_no(TG *g, int no);

typedef struct node{
  char* l;
  float f;
  int v,c;
  struct node *dir, *esq;
}NODE;

typedef struct l{
  NODE* n;
  struct l *prox;
}Lista;


Lista* crialista(NODE* n);
NODE* criaNo(char* l, float f, int v,int c, NODE* d, NODE* e);
int eVogal(char* n);
int eCaixaAlta(char* n);
char* printaVogal(NODE* n);
char* printaCaixaAlta(NODE* n);
void imprimeLista(Lista* l);
Lista* insereOrdenado(Lista*l,NODE* n);
int contains(char* c, char* str);
void codifica(NODE* n,char* c);
void codificaAvh(char* str,NODE* raiz);
NODE* buscaNoArvore(char* c,NODE*raiz);
void imprime_aux(NODE *n, int andar);
void imprimeArvore(NODE *a);
NODE* buscaNoLista(Lista *v,char* letra);
Lista*retiraLista (Lista*v, Lista*retirado);
Lista* menor(Lista* v);
NODE* avh(Lista* v, NODE* raiz);
Lista* leituraArquivo(char* arquivo);
void decodificaAvh(char* codigo, NODE* atual,NODE* raiz);
void liberaLista(Lista* l);
void liberaArvore(NODE* raiz);
Lista* procuraVogais(NODE* n,Lista* l);
Lista* procuraConsoantes(NODE* n,Lista* l);
Lista* procuraCaixaAlta(NODE* n,Lista* l);
Lista* procuraCaixaBaixa(NODE* n,Lista* l);
Lista* filtro(Lista* l,int vouc);
void atualizaArquivo(Lista* l);
Lista* customQuery(char* palavra, Lista* list,NODE* raiz);
void opcaoCodifica(NODE* raiz,char* palavra);
void opcaoDecodifica(NODE* raiz);
NODE* opcaoRemove(NODE* raiz,char* p);
NODE* opcaoRemovePorChaves(NODE* raiz,int n);
void opcaoMostraArvore(NODE*raiz);
NODE* opcaoAlteraFrequencia(NODE* raiz,float f,char l);
void opcaoMostraNos(NODE* raiz,char* p);
void opcaoMostraNosPorChave(NODE* raiz,int op);
NODE* opcaoAdicionaLetra(NODE* raiz,float frequencia,char palavra);
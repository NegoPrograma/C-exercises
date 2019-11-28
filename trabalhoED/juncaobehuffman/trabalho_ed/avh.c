#include "menus.h"


Lista* crialista(NODE* n){
  Lista* l = (Lista*) malloc(sizeof(Lista));
  l->n = n;
  l->prox = NULL;
  return l;
}

NODE* criaNo(char* l, float f, int v,int c, NODE* d, NODE* e){
  NODE* novoNo = (NODE*) malloc(sizeof(NODE));
  novoNo->l = (char*) malloc(sizeof(char)*52);
  strcpy(novoNo->l,l);
  novoNo->f = f;
  novoNo->v = v;
  novoNo->c = c;
  novoNo->dir = d;
  novoNo->esq = e;
  return novoNo;
};

int eVogal(char* n){
  char m = (*n);
  if(m == 65 || m == 65+32 || m == 69 || m == 69+32 || m == 73 || m == 73+32 || m == 79 || m == 79+32 || m == 85 || m == 85+32)
    return 1;
  return 0;
}

int eCaixaAlta(char* n){
  char m = (*n);
  if(m > 64 && m < 91)
      return 1;
  return 0;
}

char* printaVogal(NODE* n){
  if(eVogal(n->l))
      return "vogal";
  return "consoante";
}

char* printaCaixaAlta(NODE* n){
  //if(m > 64 && m < 91)
  if(eCaixaAlta(n->l))
      return "maíuscula";
  return "minúscula";

}


void imprimeLista(Lista* l){
Lista* aux =l;
while(aux != NULL){
  if(!contains("?",aux->n->l)){
      printf("\n-----------------------------------------------------\n");
      printf("|   conteúdo: %s frequência: %f %s %s |",aux->n->l,aux->n->f,printaVogal(aux->n),printaCaixaAlta(aux->n));
      printf("\n-----------------------------------------------------\n");
      aux = aux->prox;
    }
  }
}

Lista* insereOrdenado(Lista*l,NODE* n){
  if(!l) return crialista(n);
  Lista*aux = l,*pre = NULL,*novo;
  while(aux && (aux->n->f < n->f)){
    pre = aux;
    aux = aux->prox;
  }
  novo = crialista(n);
  if(pre){
  pre->prox = novo;
  novo->prox = aux;
  } else{
      novo->prox = aux;
      return novo;
  }
  return l;
}

int contains(char* c, char* str){
  char*aux = str;
  if(!aux) return 0;
  while((*aux) != '\0'){
    if((*c) == (*aux))
      return 1;
    aux++;
  }
  return 0;
}


void codifica(NODE* n,char* c){
  if(!n) return;
  if(n->dir)
    if(contains(c,n->dir->l) ){
        printf("1");
        codifica(n->dir,c);
      }
  if(n->esq)
     if(contains(c,n->esq->l) ){
        printf("0");
        codifica(n->esq,c);
      } 
    return;
}


void codificaAvh(char* str,NODE* raiz){
for(; (*str) != '\0'; str++){
    if(contains(str,raiz->l)){
      if(raiz->dir || raiz->esq)
        codifica(raiz,str);
      else
        printf("0");
    }
    else
      printf("?");    
  }
}

NODE* buscaNoArvore(char* c,NODE*raiz){
  if(!raiz) return raiz;
  if(contains(c,raiz->l) && !raiz->dir && !raiz->esq)
        return raiz;
  else if(raiz->dir && contains(c,raiz->dir->l)){
     return buscaNoArvore(c,raiz->dir);
    }
  else if(raiz->esq && contains(c,raiz->esq->l)){
      return buscaNoArvore(c,raiz->esq);
    }
}


void imprime_aux(NODE *n, int andar){
  if(n){
      int j;
      imprime_aux(n->esq,andar+1);
      for(j=0; j<=andar; j++) printf("     ");
        if(strlen(n->l) >1)
          printf("%s \n",n->l);
        else
          printf("%c \n",n->l[0]);
      imprime_aux(n->dir,andar+1);
  }
}


void imprimeArvore(NODE *a){
  imprime_aux(a, 1);
}

NODE* buscaNoLista(Lista *v,char* letra){
  if(!v) return NULL;
  Lista* aux = v;
  while(aux){
    if(contains(letra,aux->n->l))
      return aux->n;
    aux = aux->prox;
  }
  return NULL;
}


Lista*retiraLista (Lista*v, Lista*retirado){
  Lista*aux = v,*pre = NULL;
  if(!retirado) return v;
  while(aux && !contains(aux->n->l,retirado->n->l)){
    pre = aux;
    aux = aux->prox;
  };
  if(!aux) return v;
  if(pre)
  pre->prox = aux->prox;
  else{
    aux = aux->prox;
    return aux;
  }
  return v;
}

Lista* menor(Lista* v){
  Lista* lista = v,*menorLista = v;
  float menor = lista->n->f;
  for(;lista != NULL;lista = lista->prox){
          if(menor > lista->n->f){
            menor = lista->n->f;
            menorLista = lista;
        }
    }
  return menorLista;    
}

NODE* avh(Lista* v, NODE* raiz){
char m[52] = "";
  float f;
Lista* atual = v,*menor1 = v,*menor2 = v;
if(atual && !atual->prox){
  return criaNo(v->n->l,v->n->f,v->n->v,v->n->c,NULL,NULL);
}
    while(atual->prox){
        menor1 = menor(atual);
        atual = retiraLista(atual,menor1);
        menor2 = menor(atual);
        atual = retiraLista(atual,menor2);
        f = menor1->n->f + menor2->n->f;
        strcat(m,menor1->n->l);
        strcat(m,menor2->n->l);
       if(strlen(menor1->n->l) == 1 && strlen(menor2->n->l) != 1 )
          raiz = criaNo(m,f,0,0,menor1->n,menor2->n);
        else 
            raiz = criaNo(m,f,0,0,menor2->n,menor1->n);
        atual = insereOrdenado(atual,raiz);
        memset(m,0,sizeof(m));
  }
  return raiz;

}


Lista* leituraArquivo(char* arquivo){
  Lista* l = NULL;
  FILE* fp = fopen(arquivo,"r");
  int vogal,caixaAlta;
  float frequencia;
  char string[52];
  int readFile = fscanf(fp,"%s %f %d %d",string,&frequencia,&vogal,&caixaAlta);
  while(readFile != EOF){
    l = insereOrdenado(l,criaNo(string,frequencia,vogal,caixaAlta,NULL,NULL));
    readFile = fscanf(fp,"%s %f %d %d",string,&frequencia,&vogal,&caixaAlta);
  }
  fclose(fp);
  return l;
    
}


void decodificaAvh(char* codigo, NODE* atual,NODE* raiz){
  if(!atual) return;
  if((*codigo) != '1' && (*codigo) != '0') codigo++;
  if(!atual->dir && !atual->esq){
    printf("%c",atual->l[0]);
    decodificaAvh(codigo,raiz,raiz);
    } 
  if((*codigo) == '1')
    decodificaAvh(++codigo,atual->dir,raiz);
  else if((*codigo) == '0')
    decodificaAvh(++codigo,atual->esq,raiz);
}

void liberaLista(Lista* l){
  Lista* lixo;
  while(l){
    lixo = l;
    l = l->prox;
    free(lixo);
  }
}


void liberaArvore(NODE* raiz){
  if(!raiz) return;
  if(raiz){
  liberaArvore(raiz->dir);
  liberaArvore(raiz->esq);
  free(raiz);
  }
}



Lista* procuraVogais(NODE* n,Lista* l){
  if(!n) return l;
  if(!n->dir && !n->esq && n->v == 1){
        l = insereOrdenado(l,n);
      } else {
      l =  procuraVogais(n->dir,l);
      l =  procuraVogais(n->esq,l);  
      }
    return l;
}

Lista* procuraConsoantes(NODE* n,Lista* l){
  if(!n) return l;
  if(!n->dir && !n->esq && n->v == 0){
        l = insereOrdenado(l,n);
      } else {
      l =  procuraConsoantes(n->dir,l);
      l =  procuraConsoantes(n->esq,l);  
      }
    return l;
}

Lista* procuraCaixaAlta(NODE* n,Lista* l){
  if(!n) return l;
  if(!n->dir && !n->esq && n->c == 1){
        l = insereOrdenado(l,n);
      } else {
      l =  procuraCaixaAlta(n->dir,l);
      l =  procuraCaixaAlta(n->esq,l);  
      }
    return l;
}


Lista* procuraCaixaBaixa(NODE* n,Lista* l){
 if(!n) return l;
  if(!n->dir && !n->esq && n->c == 0){
        l = insereOrdenado(l,n);
      } else {
      l =  procuraCaixaBaixa(n->dir,l);
      l =  procuraCaixaBaixa(n->esq,l);  
      }
    return l;
}


Lista* customQuery(char* palavra, Lista* list,NODE* raiz){
      if(contains("1",palavra))
        list =  procuraVogais(raiz,list);
      if(contains("2",palavra))
        list = procuraConsoantes(raiz,list);
	  if(contains("3",palavra))
        list = procuraCaixaBaixa(raiz,list);
      if(contains("4",palavra))
        list = procuraCaixaAlta(raiz,list);

      return list;
}


Lista* filtro(Lista* l,int vouc){
  if(vouc == 0 || vouc == 1){
    Lista*aux = l;
    while(aux){
      if(aux->n->c != vouc)
          l = retiraLista(l,aux);
      aux = aux->prox;
    }
  }
  return l; 
}


 void atualizaArquivo(Lista* l){
  FILE* fp = fopen("temp.txt","w");
  Lista* aux = l;
  while(aux){
    fprintf(fp,"%s %f %d %d\n",aux->n->l,aux->n->f,eVogal(aux->n->l),eCaixaAlta(aux->n->l));
    aux = aux->prox;
  }
  fclose(fp);
}

void opcaoCodifica(NODE* raiz,char* palavra){
        codificaAvh(palavra,raiz);
        printf("\n");
}

char* filtraPalavra(char* palavra){
  char* novaPalavra = (char*) malloc(sizeof(char)*strlen(palavra));
  while((*palavra)!= '\0'){
    if((*palavra) == '0' || (*palavra) == '1')
      strncat(novaPalavra,palavra,1);
    palavra++;  
  }
  printf("palavra filtrada: %s",novaPalavra);
  return novaPalavra;
}

void opcaoDecodifica(NODE* raiz){
  char* palavra = (char*) malloc(sizeof(char)*100);
        printf("\nDigite o código a ser decodificado:\n");  
        scanf(" %[^\n]",palavra);
        printf("\n A palavra correspondente é:  ");
        decodificaAvh(palavra,raiz,raiz);
  free(palavra);
}


NODE* opcaoRemove(NODE* raiz,char* p){
  Lista*ldf= NULL,*lra=NULL;
  NODE* noAux = NULL;
      noAux = buscaNoArvore(p,raiz);
      if(noAux){
        printf("Nó encontrado!\n");
        ldf = leituraArquivo("temp.txt");
        lra = insereOrdenado(lra,noAux);
        while(lra){
        ldf = retiraLista(ldf,lra);
        lra = lra->prox;
        } 
        atualizaArquivo(ldf);
        ldf = leituraArquivo("temp.txt");
        raiz = avh(ldf,raiz);
      } else 
          printf("Essa letra não está presente na árvore.\n");
  liberaLista(ldf);
  liberaLista(lra);  
  return raiz;    
}

NODE* opcaoRemovePorChaves(NODE* raiz,int n){
  Lista*ldf= NULL,*lra=NULL;
  NODE* noAux = NULL;
        if(n == 2){
          lra = procuraVogais(raiz,lra);
        } else if(n == 3){
          lra = procuraConsoantes(raiz,lra);
        } else if(n == 4){
          lra = procuraCaixaAlta(raiz,lra);
        } else if(n == 5){
          lra = procuraCaixaBaixa(raiz,lra);
        } else
            return raiz;
        
      ldf = leituraArquivo("temp.txt");
      while(lra){
      ldf = retiraLista(ldf,lra);
      lra = lra->prox;
      }
      atualizaArquivo(ldf);
      raiz = avh(ldf,raiz);
      liberaLista(ldf);
      liberaLista(lra);
      return raiz;
}

void opcaoMostraArvore(NODE*raiz){
  int n;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
  printf("Deseja ver a árvore inteira ou a partir de um nó de sua escolha?\n1 - Árvore inteira.\n2 - Sub-árvore.\n");
  scanf("%d",&n);
  if(n == 1)
    imprimeArvore(raiz);
  else if(n == 2){
    printf("Digite o nó principal da sua sub-árvore.\n");
    scanf(" %[^\n]",palavra);
    noAux = buscaNoArvore(palavra,raiz);
    if(noAux)
      imprimeArvore(noAux);
    else
      printf("\nNão foi possível mostrar essa sub-árvore, o nó é inexistente.\n");
  }
  free(palavra);
  noAux = NULL;
  free(noAux);    
}

NODE* opcaoAlteraFrequencia(NODE* raiz,float f, char l){
  NODE* noAux = NULL;
  Lista* ldf = NULL, *lra = NULL;
      ldf = leituraArquivo("temp.txt");
      if(buscaNoArvore(&l,raiz)){
        noAux = buscaNoLista(ldf,&l);
        noAux->f = f;
        atualizaArquivo(ldf);
        raiz = avh(ldf,raiz);
        ldf = NULL;
        lra = NULL;
      } else {
        printf("Essa letra não está presente na árvore, portanto não foi possível alterar sua frequência.\n");
      }
    return raiz;      
}

void opcaoMostraNos(NODE* raiz,char* p){
    NODE* noAux = NULL;
    noAux = buscaNoArvore(p,raiz);
    if(noAux){
      printf("Árvore de Huffman: \n");
      printf("\n-----------------------------------------------------\n");
      printf("|   conteúdo: %s frequência: %.2f %s %s |",noAux->l,noAux->f,printaVogal(noAux),printaCaixaAlta(noAux));
      printf("\n-----------------------------------------------------\n");
    } else {
      printf("Não existe nenhum nó com esse conteúdo.\n");
    }
}

void opcaoMostraNosPorChave(NODE* raiz,int op){
  Lista* ldf= NULL;
  if(op == 2){
    ldf = procuraVogais(raiz,ldf);
    } 
  else if(op == 3){
      ldf = procuraConsoantes(raiz,ldf);
    } else if(op == 4){
      ldf = procuraCaixaAlta(raiz,ldf);
    } else if( op == 5){
      ldf = procuraCaixaBaixa(raiz,ldf);
    }
    imprimeLista(ldf);
    ldf = NULL;
}

NODE* opcaoAdicionaLetra(NODE* raiz,float frequencia,char palavra){
  NODE* noAux = NULL;
  Lista* ldf = NULL, *lra = NULL;
  ldf = leituraArquivo("temp.txt");
  char letra[1];
  letra[0] = palavra;
  lra = insereOrdenado(lra,criaNo(letra,frequencia,eVogal(&palavra),eCaixaAlta(&palavra),NULL,NULL));
  while(lra){
        ldf = insereOrdenado(ldf,lra->n);
        lra = lra->prox;
    };
    atualizaArquivo(ldf);
    raiz = avh(ldf,raiz);
    liberaLista(ldf);
    liberaLista(lra);
    return raiz;            
};


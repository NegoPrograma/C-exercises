#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char l[52];
  float f;
  int v,c;
  struct node *dir, *esq;
}NODE;

typedef struct l{
  NODE* n;
  struct l *prox;
}Lista;

Lista* crialista(NODE* n){
  Lista* l = (Lista*) malloc(sizeof(Lista));
  l->n = n;
  l->prox = NULL;
  return l;
}

Lista* insere(Lista* l, NODE* n){
  Lista* aux = l, *pre = NULL;
  if(!l) return crialista(n);
  while(aux->prox){
  pre = aux;
  aux = aux->prox;
  };
  aux->prox = crialista(n);

  return l;
}


NODE* criaString(char* l, float f, int v,int c, NODE* d, NODE* e){
  NODE* novoNo = (NODE*) malloc(sizeof(NODE));
  strcpy(novoNo->l,l);
  novoNo->f = f;
  novoNo->v = v;
  novoNo->c = c;
  novoNo->dir = d;
  novoNo->esq = e;
  return novoNo;
};

NODE* cria(char l[], float f, int v,int c, NODE* d, NODE* e){
  NODE* novoNo = (NODE*) malloc(sizeof(NODE));
  strcpy(novoNo->l,&l);
  novoNo->f = f;
  novoNo->v = v;
  novoNo->c = c;
  novoNo->dir = d;
  novoNo->esq = e;
  return novoNo;
};

/*NODE* geraHuffman(char* palavra){



}*/

int vogal(char m){
  if(m == 65 || m == 65+32)
      return 1;
  else if(m == 69 || m == 69+32)
    return 1;
  else if(m == 73 || m == 73+32)
  return 1;
  else if(m == 79 || m == 79+32)
  return 1;
  else if(m == 85 || m == 85+32)
  return 1;
  else
      return 0;
}

int caixaAlta(int m){
  if(m > 64 && m < 91)
      return 1;
  return 0;

}

Lista* retiraInicio(Lista* l,NODE** n){
  Lista* lixo = l;
  (*n) = criaString(l->n->l,l->n->f,l->n->v,l->n->c,l->n->dir,l->n->esq);
  l = l->prox;
  //free(lixo);
  return l;
}

void imprimeLista(Lista* l){
Lista* aux =l;
while(aux != NULL){
 if(strlen(aux->n->l) != 1)
  printf("%s %.2f %d %d \n", aux->n->l,aux->n->f,aux->n->v,aux->n->c);
  else
   printf("%c %.2f %d %d \n",aux->n->l[0],aux->n->f,aux->n->v,aux->n->c);
  aux = aux->prox;
  }
  printf("fim lista\n");
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

Lista* ultimoElem(Lista*l){
  while(l->prox) l = l->prox;
  return l;
}


int maior(Lista*l1, Lista*l2){
  while(l1){
    if(l1->prox == l2)
         return 1;
    l1 = l1->prox;
  }
  return 0;
}

Lista* sort(Lista* l){
  NODE* aux;
  Lista* l2, *l1 = l;
  for(; l1!= NULL; l1 = l1->prox){
        l2 = l->prox;
      for(; l2!=NULL; l2=l2->prox){
          if((l1->n->f > l2->n->f) && maior(l1, l2)){
              aux = l2->n;
              l2->n = l1->n;
              l1->n = aux;
        }
      }
    }
  return l;
}

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

int tamanho(Lista* l){
  int i = 0;
  Lista*v = l;
  while(v){
    i++;
    v =v->prox;
  }
  return i;
}

void imprime_aux(NODE *n, int andar){
  if(n){
      int j;
      imprime_aux(n->esq,andar+1);
      for(j=0; j<=andar; j++) printf("       ");
      if(strlen(n->l) >1)
        printf("%s %.0f\n",n->l,n->f);
      else
        printf("%c %.0f\n",n->l[0],n->f);
//printf("%.0f \n",n->f);  
      imprime_aux(n->dir,andar+1);
  }
}


void imprime(NODE *a){
  imprime_aux(a, 1);
}


void imprimeArvore(NODE* n){
  if(!n) return;
  if(strlen(n->l) >1)
    printf("%s \n",n->l);
  else
    printf("%c \n",n->l[0]);
  imprimeArvore(n->esq);
  imprimeArvore(n->dir);
}

Lista*retiraLista (Lista*v, Lista*retirado){
  Lista*aux = v,*pre = NULL;
  while(aux && aux->n != retirado->n){
    pre = aux;
    aux = aux->prox;
  };
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

NODE* avhdois(Lista* v, NODE* raiz){
char m[52] = "";
  float f;
Lista* atual = v,*menor1 = v,*menor2 = v;
    while(atual->prox){
        menor1 = menor(atual);
        atual = retiraLista(atual,menor1);
        menor2 = menor(atual);
        atual = retiraLista(atual,menor2);
        f = menor1->n->f + menor2->n->f;
        strcat(m,menor1->n->l);
        strcat(m,menor2->n->l);
       if(strlen(menor1->n->l) == 1 && strlen(menor2->n->l) != 1 )
          raiz = criaString(m,f,0,0,menor1->n,menor2->n);
        else 
            raiz = criaString(m,f,0,0,menor2->n,menor1->n);
        atual = insereOrdenado(atual,raiz);
        imprimeLista(atual);
        imprime(raiz);
        memset(m,0,sizeof(m));
  }
  return raiz;

}



NODE* avh(Lista* v,NODE* raiz){
  char m[52] = "";
  float f;
  Lista* atual = v;
  NODE* esq = NULL,*dir= NULL;
    while(atual->prox){
        atual = retiraInicio(atual,&esq);
        atual = retiraInicio(atual,&dir);
        f = esq->f + dir->f;
        strcat(m,esq->l);
        strcat(m,dir->l);
        //raiz = (dir->f >= esq->f)?criaString(m,f,0,0,dir,esq):criaString(m,f,0,0,esq,dir);
        if(strlen(esq->l) == 1 && strlen(dir->l) != 1 )
          raiz = criaString(m,f,0,0,esq,dir);
        else 
            raiz = criaString(m,f,0,0,dir,esq);
        atual = insereOrdenado(atual,raiz);
        imprimeLista(atual);
        imprime(raiz);
        memset(m,0,sizeof(m));
  }
  return raiz;
}

int main(void) {

Lista* ldf = NULL;
int i, n=52;

srand(__TIME__);
Lista* abc = NULL;
for(i = 0; i < 26; i++){
   ldf = insere(ldf, cria((char*)  65+i,(float) i,vogal(65+i),caixaAlta(65+i),NULL,NULL));

}
for(; i < 50; i++){
   ldf = insere(ldf, cria((char*) 72+i,(float) i,vogal(72+i),caixaAlta(72+i),NULL,NULL));
   if(i <33){
     abc = insere(abc, cria((char*) 72+i,(float) (rand() % 20),vogal(72+i),caixaAlta(72+i),NULL,NULL));
   }
};
ldf = sort(ldf);
NODE* raiz = NULL;
int tamanhoLista = tamanho(ldf);
//raiz = avh(ldf,raiz);
imprimeLista(abc);
abc = sort(abc);
imprimeLista(abc);
printf("------------------------------------------\n\n\n raiz: %s \n\n\n",raiz->l);
//imprime(raiz);
printf("-------------------------------ALGORITIMO 2-----------\n\n\n");
//teste a parte
 tamanhoLista = tamanho(abc);
raiz = avhdois(abc,raiz);
abc = retiraLista(abc,menor(abc));
//imprimeLista(retiraLista(abc,menor(abc)));
//imprimeLista(abc);



  return 0;
}

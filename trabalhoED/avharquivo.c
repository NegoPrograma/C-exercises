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

NODE* criaNo(char* l, float f, int v,int c, NODE* d, NODE* e){
  NODE* novoNo = (NODE*) malloc(sizeof(NODE));
  strcpy(novoNo->l,l);
  novoNo->f = f;
  novoNo->v = v;
  novoNo->c = c;
  novoNo->dir = d;
  novoNo->esq = e;
  return novoNo;
};


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

int maior(Lista*l1, Lista*l2){
  while(l1){
    if(l1->prox == l2)
         return 1;
    l1 = l1->prox;
  }
  return 0;
}

int contains(char c[], char* str){
  char*aux = str;
  if(!aux) return 0;
  while((*aux) != '\0'){
    if((*aux) == c[0]){
      return 1;
    }
    aux++;
  }
  return 0;
}


void buscaNo(NODE* n,char c[]){
  if(!n) return;
  if(n->dir)
    if(contains(c,n->dir->l)){
      printf("1");
      buscaNo(n->dir,c);
      buscaNo(n->esq,c);
    }
  if(n->esq)
      if(contains(c,n->esq->l)){
      printf("0");
      buscaNo(n->dir,c);
      buscaNo(n->esq,c);
    }
  if(!n->dir && !n->esq && !contains(c,n->l))
      printf("?");    
}


void imprime_aux(NODE *n, int andar){
  if(n){
      int j;
      imprime_aux(n->esq,andar+1);
      for(j=0; j<=andar; j++) printf("       ");
      if(strlen(n->l) >1)
        printf("%s %.1f\n",n->l,n->f);
      else
        printf("%c %.1f\n",n->l[0],n->f);
//printf("%.0f \n",n->f);  
      imprime_aux(n->dir,andar+1);
  }
}


void imprime(NODE *a){
  imprime_aux(a, 1);
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

NODE* avh(Lista* v, NODE* raiz){
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
          raiz = criaNo(m,f,0,0,menor1->n,menor2->n);
        else 
            raiz = criaNo(m,f,0,0,menor2->n,menor1->n);
        atual = insereOrdenado(atual,raiz);
        memset(m,0,sizeof(m));
  }
  imprime(raiz);
  return raiz;

}


Lista* leituraArquivo(char* nomeArq){
  Lista* l = NULL;
  FILE* fp = fopen(nomeArq,"r");
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

void codificaAvh(char* str,NODE* raiz){
char n[] = "";
for(; (*str) != '\0'; str++){
  strncpy(n,str,1);
  //printf("sim, a letra %c está em %s, visto o resultado de contains: %d\n\n\n",n[0],str,contains(n,str));
  buscaNo(raiz,n);
  }
}

void decodificaAvh(char* codigo, NODE* atual,NODE* raiz){
  if(atual){
  if(!atual->dir && !atual->esq){
    printf("%c",atual->l[0]);
    decodificaAvh(codigo,raiz,raiz);
  } 
  if( ((*codigo) == '1') || ((*codigo) == '0') )
      if((*codigo) == '1'){
        decodificaAvh(++codigo,atual->dir,raiz);
       } else {
        decodificaAvh(++codigo,atual->esq,raiz);
      }
  }
}


void leitura(NODE* raiz){
  int op;
  char palavra[100];
    int n;
  do{
    if(op == 1){
          do{
    printf("Digite a palavra a ser codificada:\n");  
    scanf(" %[^\n]",palavra);
    printf("\ncódigo da palavra: ");
    codificaAvh(palavra,raiz);
    printf("\ndeseja continuar codificando? Se sim, digite 1, caso contrário, qualquer outro número.\n");
    scanf("%d",&n);
    }while(n == 1);
    } else if(op == 2) {
      do{
      printf("\nDigite o código a ser decodificado:\n");  
      scanf(" %[^\n]",palavra);
      printf("\n A palavra correspondente é:  ");
      decodificaAvh(palavra,raiz,raiz);
      printf("\nDeseja continuar decodificando? Se sim, digite 2, caso contrário, qualquer outro número.\n");
      scanf("%d",&n);
      }while(n == 2);
    } 
    printf("\nMenu:\n1- codificar palavras \n2- decodificar códigos.\nPara sair, digite qualquer outro número.\n");
    scanf(" %d",&op);
  }while(op == 1 || op == 2);
    
  

}
int main(void) {
  //lendo a lista e criando a árvore  
  Lista* ldf = NULL;
  ldf = leituraArquivo("experimental.txt");
  NODE* raiz = NULL;
  raiz = avh(ldf,raiz);
  //interagindo com o usuário
  leitura(raiz);



  return 0;
}

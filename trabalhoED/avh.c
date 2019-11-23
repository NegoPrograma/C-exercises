#include "./avh.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


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
  //if(m == 65 || m == 65+32 || m == 69 || m == 69+32 || m == 73 || m == 73+32 || m == 79 || m == 79+32 || m == 85 || m == 85+32);
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
      for(j=0; j<=andar; j++) printf("         ");
        if(strlen(n->l) >1)
          printf("%s %.1f\n",n->l,n->f);
        else
          printf("%c %.1f\n",n->l[0],n->f);
      
//printf("%.0f \n",n->f);  
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


void decodificaAvh(char* codigo, NODE* atual,NODE* raiz){
  if(!atual) return;
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


 void atualizaArquivo(Lista* l, char* arquivo){
  FILE* fp = fopen(arquivo,"w");
  Lista* aux = l;
  while(aux){
    fprintf(fp,"%s %f %d %d\n",aux->n->l,aux->n->f,eVogal(aux->n->l),eCaixaAlta(aux->n->l));
    aux = aux->prox;
  }
  fclose(fp);
}

void opcaoCodifica(NODE* raiz){
  int n = 0;
  char* palavra = (char*) malloc(sizeof(char)*100);
  do{
        printf("Digite a palavra a ser codificada:\n");  
        scanf(" %[^\n]",palavra);
        printf("\ncódigo da palavra: ");
        codificaAvh(palavra,raiz);
        printf("\ndeseja continuar codificando? Se sim, digite 1, caso contrário, digite 0.\n");
        scanf(" %d",&n);
    }while(n != 0);
    free(palavra);
}

void opcaoDecodifica(NODE* raiz){
  int n = 0;
  char* palavra = (char*) malloc(sizeof(char)*100);
  do{
        printf("\nDigite o código a ser decodificado:\n");  
        scanf(" %[^\n]",palavra);
        printf("\n A palavra correspondente é:  ");
        decodificaAvh(palavra,raiz,raiz);
        printf("\nDeseja continuar decodificando? Se sim, digite 1, caso contrário, digite 0.\n");
        scanf("%d",&n);
      }while(n != 0);
  free(palavra);
}


NODE* opcaoRemove(NODE* raiz,char* arquivo){
  Lista*ldf= NULL,*lra=NULL;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
      printf("digite a letra ou palavra a ser retirada:\n");
      scanf(" %[^\n]",palavra);
      noAux = buscaNoArvore(palavra,raiz);
      if(noAux){
        ldf = leituraArquivo(arquivo);
        lra = insereOrdenado(lra,noAux);
        while(lra){
        ldf = retiraLista(ldf,lra);
        lra = lra->prox;
        }
       atualizaArquivo(ldf,arquivo);
        raiz = avh(ldf,raiz);
      }
  free(palavra);
  liberaLista(ldf);
  liberaLista(lra);  
  return raiz;    
}

NODE* opcaoRemovePorChaves(NODE* raiz,char* arquivo){
  Lista*ldf= NULL,*lra=NULL;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
  int n;
        printf("\nVocê decidiu remover elementos de acordo com características em comum.\n os elementos a serem retirados são:\n1 - Vogais\n2 - Consoantes\n3- Ambos");
        scanf("%d",&n);
        if(n == 1){
          lra = procuraVogais(raiz,lra);
          printf("\nVocê decidiu remover vogais.\n as letras a serem retiradas são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas \n");
          scanf("%d",&n);
        } else if(n == 2){
          lra = procuraConsoantes(raiz,lra);
          printf("\nVocê decidiu remover consoantes.\n as letras a serem retiradas são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas \n");
          scanf("%d",&n);
        } else if(n == 3){
          lra = procuraConsoantes(raiz,lra);
          lra = procuraVogais(raiz,lra);
          printf("\nVocê decidiu remover vogais e consoantes.\n as letras a serem retiradas são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas \n");
          scanf("%d",&n);
        }
      lra = filtro(lra,n);
      ldf = leituraArquivo(arquivo);
      while(lra){
      ldf = retiraLista(ldf,lra);
      lra = lra->prox;
      }
      atualizaArquivo(ldf,arquivo);
      raiz = avh(ldf,raiz);
      liberaLista(ldf);
      liberaLista(lra);
      return raiz;
}

void opcaoMostraArvore(NODE*raiz){
  int n;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
  printf("Deseja ver a árvore inteira ou a partir de um nó de sua escolha?\n1 - Árvore inteira\n2 - Sub-árvore.\n");
  scanf("%d",&n);
  if(n == 1)
    imprimeArvore(raiz);
  else if(n == 2){
    printf("Digite o nó principal da sua sub-árvore.");
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

NODE* opcaoAlteraFrequencia(NODE* raiz, char* arquivo){
  float frequencia;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
  Lista* ldf = NULL, *lra = NULL;
    printf("digite a letra cuja frequência será mudada:\n");
      scanf(" %[^\n]",palavra);
      ldf = leituraArquivo(arquivo);
      if(buscaNoArvore(palavra,raiz)){
        printf("Digite a nova frequência:\n");
        scanf("%f",&frequencia);
        noAux = buscaNoLista(ldf,palavra);
        noAux->f = frequencia;
        atualizaArquivo(ldf,arquivo);
        raiz = avh(ldf,raiz);
        ldf = NULL;
        lra = NULL;
      } else {
        printf("Essa letra não está presente na árvore, portanto não foi possível alterar sua frequência.\n");
      }
    return raiz;      
}

void opcaoMostraUmNo(NODE* raiz){
  int n;
  NODE* noAux = NULL;
  char* palavra = (char*) malloc(sizeof(char)*100);
   do{
    printf("Digite o conteúdo do nó desejado:\n");
    scanf(" %[^\n]",palavra);
    noAux = buscaNoArvore(palavra,raiz);
    if(noAux){
    printf("\n-----------------------------------------------------\n");
    printf("|   conteúdo: %s frequência: %.2f %s %s |",noAux->l,noAux->f,printaVogal(noAux),printaCaixaAlta(noAux));
    printf("\n-----------------------------------------------------\n");
    } else {
      printf("Não existe nenhum nó com esse conteúdo.\n");
    }
    printf("Deseja saber mais informações sobre algum outro nó? Se sim, digite 1, caso contrário, digite 0.\n");
    scanf(" %d",&n);
    }while(n != 0);
}

void leitura(char* arquivo){
  //inicializando a árvore
  Lista* ldf = NULL,*lra = NULL;
  ldf = leituraArquivo(arquivo);
  NODE* raiz = NULL,*noAux;
  raiz = avh(ldf,raiz);
  ldf = NULL;
  //variaveis do menu
  int op,n,vogal,caixaAlta;
  float frequencia;
  char* palavra = (char*) malloc(sizeof(char)*100);
  do{
    
    if(op == 1){
    opcaoCodifica(raiz);
    //-------------------------------OPÇÃO 2 ---------------------------------------//
    } else if(op == 2) {
      opcaoDecodifica(raiz);
    } 
    //-------------------------------OPÇÃO 3 ---------------------------------------//
    else if(op == 3){
        printf("\n. \nGostaria de escolher exatamente quais letras tirar(1)\nOu gostaria de remover elas segundo características em comum? (remover somente vogais, por exemplo)(2)\n");
        scanf(" %d",&n);
        if(n == 1)
            do{
            raiz = opcaoRemove(raiz,arquivo);          
             printf("deseja continuar retirando letras? caso não, digite 0 para sair.");
            scanf("%d",&n);
          }while(n != 0);
         else if(n == 2)
          raiz = opcaoRemovePorChaves(raiz,arquivo);
//-------------------------------OPÇÃO 4 ---------------------------------------//
    } else if(op == 4)
       opcaoMostraArvore(raiz);
//-------------------------------OPÇÃO 5 ---------------------------------------//
     else if(op == 5)
      raiz = opcaoAlteraFrequencia(raiz,arquivo);
//-------------------------------OPÇÃO 6 ---------------------------------------//
    else if(op == 6){
        printf("Ok, você deseja saber o conteúdo de nós. Porém, como você pretende pesquisar?\n1 - Digitando o conteúdo do nó um de cada vez\n2 - Usando critérios em comum\n");
        scanf("%d",&n);
        if(n == 1){
          do{
            printf("Digite o conteúdo do nó desejado:\n");
            scanf(" %[^\n]",palavra);
            noAux = buscaNoArvore(palavra,raiz);
            if(noAux){
            printf("\n-----------------------------------------------------\n");
            printf("|   conteúdo: %s frequência: %.2f %s %s |",noAux->l,noAux->f,printaVogal(noAux),printaCaixaAlta(noAux));
            printf("\n-----------------------------------------------------\n");
            } else {
              printf("Não existe nenhum nó com esse conteúdo.\n");
            }
            printf("Deseja saber mais informações sobre algum outro nó? Se sim, digite 1, caso contrário, digite 0.\n");
            scanf(" %d",&n);
            }while(n != 0);
        }
        else if(n == 2){
          printf("\nVocê escolheu pesquisar de acordo com características em comum.\n As letras que você deseja pesquisar são:\n1 - Vogais\n2 - Consoantes\n3 - Ambas.\n");
          scanf(" %d",&n);
          if(n == 1){
            ldf = procuraVogais(raiz,ldf);
            printf("\nVocê escolheu pesquisar as letras vogais.\n As letras que você deseja pesquisar são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas.\n");
            scanf(" %d",&n);
            ldf = filtro(ldf,n);
            imprimeLista(ldf);
            } 
          else if(n == 2){
              ldf = procuraConsoantes(raiz,ldf);
              printf("\nVocê escolheu pesquisar as letras consoantes.\n As letras que você deseja pesquisar são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas.\n");
              scanf(" %d",&n);
              ldf = filtro(ldf,n);
              imprimeLista(ldf);
            } else{
              ldf = customQuery("12",ldf,raiz);
              printf("\nVocê escolheu pesquisar tanto vogais quanto consoantes.\n As letras que você deseja pesquisar são:\n0 - Minúsculas\n1 - Maiúsculas\n2 - Ambas.\n");
              scanf("%d",&n);
              ldf = filtro(ldf,n);
              imprimeLista(ldf);
            }
            ldf = NULL;
          }
        } else if(op == 7){
          printf("Você decidiu adicionar uma nova letra.\nDigite a letra desejada: ");
          scanf("%s",palavra);
          if(!buscaNoArvore(palavra,raiz) && strlen(palavra)<2 && strlen(palavra)>0){
          printf("\nfrequência: ");
          scanf("%f",&frequencia);
          ldf = leituraArquivo(arquivo);
          lra = insereOrdenado(lra,criaNo(palavra,frequencia,eVogal(palavra),eCaixaAlta(palavra),NULL,NULL));
          while(lra){
                 ldf = insereOrdenado(ldf,lra->n);
                lra = lra->prox;
           }
           atualizaArquivo(ldf,arquivo);
          raiz = avh(ldf,raiz);
          ldf = lra = NULL;
          } else 
            printf("Não foi possível adicionar letra.\n");

        }
    printf("\nMenu:\n1 - Codificar palavras. \n2 - Decodificar códigos.\n3 - Retirar letras.\n4 - Mostrar a árvore.\n5 - Alterar a frequência de uma letra.\n6 - Ver dados sobre os nós disponíveis.\n7 - Adicionar letra\nPara sair, digite 0.\n");
    scanf(" %d",&op);
  }while(op != 0);
  liberaArvore(raiz);
  liberaLista(ldf);
}

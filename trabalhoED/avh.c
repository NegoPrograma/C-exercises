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


int verificaVogal(char m){
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

int verificaCaixaAlta(int m){
  if(m > 64 && m < 91)
      return 1;
  return 0;

}


void imprimeLista(Lista* l){
Lista* aux =l;
while(aux != NULL){
  if(!contains("?",aux->n->l)){
      printf("\n-------------------------------------------------------------\n");
      printf("|   conteúdo: %s frequência: %f vogal: %d consoante: %d |",aux->n->l,aux->n->f,aux->n->v,aux->n->c);
      printf("\n-------------------------------------------------------------\n");
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
  if(n->dir && n->esq){
    if(contains(c,n->dir->l) || (!contains(c,n->esq->l) && !strcmp(n->dir->l,"?"))){
        printf("1");
        codifica(n->dir,c);
      }
     if(contains(c,n->esq->l) || (!contains(c,n->dir->l) && !strcmp(n->esq->l,"?"))){
        printf("0");
        codifica(n->esq,c);
      } 
  }
    return;
}


void codificaAvh(char* str,NODE* raiz){
for(; (*str) != '\0'; str++)
      codifica(raiz,str);
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
  if(atual){
  if(!atual->dir && !atual->esq){
    printf("%c",atual->l[0]);
    decodificaAvh(codigo,raiz,raiz);
    } 
   
  if((*codigo) != '\0')
      if((*codigo) == '1'){
        decodificaAvh(++codigo,atual->dir,raiz);
      }
      else if((*codigo) == '0'){
        decodificaAvh(++codigo,atual->esq,raiz);
      }
    }
  }

void retiraLetra(NODE** no){
    strcpy((*no)->l,"?");
    (*no)->f = 0;
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







void leitura(char* arquivo){
  //inicializando a árvore
  Lista* ldf = NULL,*listaAux = NULL,*letrasRetiradas = NULL;
  ldf = leituraArquivo(arquivo);
  NODE* raiz = NULL,*noAux;
  raiz = avh(ldf,raiz);
  //variaveis do menu
  int op,n,vogal,caixaAlta;
  float frequencia;
  char* palavra = (char*) malloc(sizeof(char)*100);
  char* letra="",letraAux;
  do{
    
    if(op == 1){
      do{
        printf("Digite a palavra a ser codificada:\n");  
        scanf(" %[^\n]",palavra);
        printf("\ncódigo da palavra: ");
        codificaAvh(palavra,raiz);
        printf("\ndeseja continuar codificando? Se sim, digite 1, caso contrário, digite 0.\n");
        scanf(" %d",&n);
    }while(n != 0);
    //-------------------------------OPÇÃO 2 ---------------------------------------//
    } else if(op == 2) {
      do{
        printf("\nDigite o código a ser decodificado:\n");  
        scanf(" %[^\n]",palavra);
        printf("\n A palavra correspondente é:  ");
        decodificaAvh(palavra,raiz,raiz);
        printf("\nDeseja continuar decodificando? Se sim, digite 1, caso contrário, digite 0.\n");
        scanf("%d",&n);
      }while(n != 0);
    } 
    //-------------------------------OPÇÃO 3 ---------------------------------------//
    else if(op == 3){

      printf("\nDeseja retirar uma única letra ou múltiplas letras? (1/2)\n");
      scanf("%d",&n);
      if(n == 1){
      printf("digite a letra a ser retirada:\n");
      scanf(" %[^\n]",palavra);
      noAux = buscaNoArvore(palavra,raiz);
      if(noAux){
        letrasRetiradas = insereOrdenado(letrasRetiradas,criaNo(noAux->l,noAux->f,noAux->v,noAux->c,NULL,NULL));
        retiraLetra(&noAux);
      }
      } else if(n == 2) {
        printf("\nOk, você escolheu retirar múltiplas letras. \nGostaria de escolher exatamente quais letras tirar(1)\nOu gostaria de remover elas segundo características em comum? (remover somente vogais, por exemplo)(2)\n");
        scanf(" %d",&n);
        if(n == 1){
          do{
            printf("digite as letras que serão retiradas:\n");
            scanf(" %[^\n]",palavra);
            for(; (*palavra) != '\0';palavra++){
              noAux = buscaNoArvore(palavra,raiz);
              if(noAux){
                letrasRetiradas = insereOrdenado(letrasRetiradas,criaNo(noAux->l,noAux->f,noAux->v,noAux->c,NULL,NULL));
                retiraLetra(&noAux);
                }
              }
            printf("deseja continuar retirando letras? caso não, digite 0 para sair.");
            scanf("%d",&n);
          }while(n != 0);
        } else if(n == 2){
          printf("\nPara escolher os critérios de remoção, digite os números correspondentes abaixo:\n1 - Vogais\n2 - Consoantes\n3 - Minusculas\n4 - Maiúsculas\n");
          scanf(" %[^\n]",palavra);
          printf("entrada: %s",palavra);
         listaAux = customQuery(palavra,listaAux,raiz);
         while(listaAux){
           letrasRetiradas = insereOrdenado(letrasRetiradas,criaNo(listaAux->n->l,listaAux->n->f,listaAux->n->v,listaAux->n->c,NULL,NULL));
           retiraLetra(&listaAux->n);
           listaAux = listaAux->prox;
         }
         listaAux = NULL;
        }
      }
//-------------------------------OPÇÃO 4 ---------------------------------------//
    } else if(op == 4){
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
//-------------------------------OPÇÃO 5 ---------------------------------------//
    } else if(op == 5){
      printf("digite a letra cuja frequência será mudada:\n");
      scanf(" %[^\n]",palavra);
      ldf = leituraArquivo(arquivo);
      if(!buscaNoLista(letrasRetiradas,palavra)){
      printf("Digite a nova frequência:\n");
      scanf("%f",&frequencia);
      noAux = buscaNoLista(ldf,palavra);
      noAux->f = frequencia;
      raiz = avh(ldf,raiz);
      while(letrasRetiradas){
        noAux = buscaNoArvore(letrasRetiradas->n->l,raiz);
        retiraLetra(&noAux);
        letrasRetiradas = letrasRetiradas->prox;
      }
      } else {
        printf("Essa letra já não está presente na árvore, portanto não foi possível alterar sua frequência.\n");
      }
    } 
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
            printf("\n-------------------------------------------------------------\n");
            printf("|   conteúdo: %s frequência: %f vogal: %d consoante: %d |",noAux->l,noAux->f,noAux->v,noAux->c);
            printf("\n-------------------------------------------------------------\n");
            } else {
              printf("Não existe nenhum nó com esse conteúdo.\n");
            }
            printf("Deseja saber mais informações sobre algum outro nó? Se sim, digite 1, caso contrário, digite 0.\n");
            scanf(" %d",&n);
            }while(n != 0);
        }
        else if(n == 2){
          printf("\nPara escolher os critérios de busca, digite os números correspondentes abaixo:\n1 - Vogais\n2 - Consoantes\n3 - Minusculas\n4 - Maiúsculas\n");
          scanf(" %[^\n]",palavra);
          listaAux = customQuery(palavra,listaAux,raiz);
          imprimeLista(listaAux);
          listaAux = NULL;
        }
    } 
    printf("\nMenu:\n1 - Codificar palavras. \n2 - Decodificar códigos.\n3 - Retirar letras.\n4 - Mostrar a árvore.\n5 - Alterar a frequência de uma letra.\n6 - Ver dados sobre os nós disponíveis.\nPara sair, digite 0.\n");
    scanf(" %d",&op);
  }while(op != 0);
  liberaArvore(raiz);
  liberaLista(ldf);
}

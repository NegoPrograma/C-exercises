#include "tarvb.h"
#include <string.h>

TAB *Inicia_arquivo(TAB* a,int t,FILE *fp){
    char l;
    float f;
    int s,v,c,i=0;
    s=4;
    while(s==4){
		s=fscanf(fp," %c %f %d %d",&l,&f,&v,&c);
		if (s==4)
			a=Insere(a,l,f,v,c,t);
    }
    fclose(fp);
    return a;
}

TAB *Cria(int t){
  TAB* novo = (TAB*)malloc(sizeof(TAB));
  novo->nchaves = 0;
  novo->chave =(NO**)malloc(sizeof(NO*)*((t*2)-1));
  novo->folha=1;
  novo->filho = (TAB**)malloc(sizeof(TAB*)*t*2);
  int i;
  for(i=0; i<(t*2); i++) novo->filho[i] = NULL;
  for(i=0; i<(t*2-1); i++) novo->chave[i] = NULL;
  return novo;
}


void Libera(TAB *a){
  if(a){
    if(!a->folha){
      int i;
      for(i = 0; i <= a->nchaves; i++) Libera(a->filho[i]);
    }
    NO* aux;
    int i= 0;
    while(a->chave[i]){
        aux = a->chave[i];
        free(aux);
        a->chave[i] = a->chave[++i];
    }
    free(a->chave);
    free(a->filho);
    free(a);
  }
}


void Imprime(TAB *a, int andar){
  if(a){
    int i,j;
    for(i=0; i<=a->nchaves-1; i++){
      Imprime(a->filho[i],andar+1);
      for(j=0; j<=andar; j++) printf("   ");
      printf("%c\n", a->chave[i]->l);
    }
    Imprime(a->filho[i],andar+1);
  }
}


TAB *Busca(TAB* x, char ch){
  TAB *resp = NULL;
  if(!x) return resp;
  int i = 0;
  while(i < x->nchaves && ch > x->chave[i]->l) i++;
  if(i < x->nchaves && ch == x->chave[i]->l) return x;
  if(x->folha) return resp;
  return Busca(x->filho[i], ch);
}


TAB *Inicializa(){
  return NULL;
}


TAB *Divisao(TAB *x, int i, TAB* y, int t){
  TAB *z=Cria(t);
  z->nchaves= t - 1;
  z->folha = y->folha;

  int j;
  for(j=0;j<t-1;j++){
   z->chave[j] = y->chave[j+t];
   y->chave[j+t]=NULL;
   
   }
  if(!y->folha){
    for(j=0;j<t;j++){
      z->filho[j] = y->filho[j+t];
      y->filho[j+t] = NULL;
    }
  }
  y->nchaves = t-1;
  for(j=x->nchaves; j>=i; j--) x->filho[j+1]=x->filho[j];
  x->filho[i] = z;
  for(j=x->nchaves; j>=i; j--){ 
  x->chave[j] = x->chave[j-1];
  x->chave[j-1]=NULL;
  }
  x->chave[i-1]= y->chave[t-1];
  y->chave[t-1]=NULL;
  x->nchaves++;
  return x;
}


TAB *Insere_Nao_Completo(TAB *x, char k,float f,int c,int v, int t){
  int i = x->nchaves-1;
  if(x->folha){
    while((i>=0) && (k<x->chave[i]->l)){
      x->chave[i+1] = x->chave[i];
      x->chave[i]=NULL;
      i--;
    }
    x->chave[i+1] = CriaNo(k,f,v,c);
    x->nchaves++;
    return x;
  }
  while((i>=0) && (k<x->chave[i]->l)) i--;
  i++;
  if(x->filho[i]->nchaves == ((2*t)-1)){
    x = Divisao(x, (i+1), x->filho[i], t);
    if(k>x->chave[i]->l) i++;
  }
  x->filho[i] = Insere_Nao_Completo(x->filho[i], k,f,c,v,t);
  return x;
}


TAB *Insere(TAB *T, char k,float f,int c,int v, int t){
  if(Busca(T,k)) return T;
  if(!T){
    T=Cria(t);
    T->chave[0]=CriaNo(k,f,v,c);
    T->nchaves=1;
    return T;
  }
  if(T->nchaves == (2*t)-1){
    TAB *S = Cria(t);
    S->nchaves=0;
    S->folha = 0;
    S->filho[0] = T;
    S = Divisao(S,1,T,t);
    S = Insere_Nao_Completo(S,k,f,c,v,t);
    return S;
  }
  T = Insere_Nao_Completo(T,k,f,c,v,t);
  return T;
}


TAB* remover(TAB* arv, char ch, int t){
  if(!arv) return arv;
  int i;
  printf("Removendo %c...\n", ch);
  for(i = 0; i<arv->nchaves && arv->chave[i]->l < ch; i++);
  if(i < arv->nchaves && ch == arv->chave[i]->l){ //CASOS 1, 2A, 2B e 2C
    if(arv->folha){ //CASO 1
      printf("\nCASO 1\n");
      int j;
      for(j=i; j<arv->nchaves-1;j++){
        NO* aux = arv->chave[j];
         arv->chave[j] = arv->chave[j+1];
         arv->chave[j+1] = NULL;
         free(aux);

      }
      arv->nchaves--;
      return arv;      
    }
    if(!arv->folha && arv->filho[i]->nchaves >= t){ //CASO 2A
      printf("\nCASO 2A\n");
      TAB *y = arv->filho[i];  //Encontrar o predecessor k' de k na árvore com raiz em y
      while(!y->folha) y = y->filho[y->nchaves];
      char temp = y->chave[y->nchaves-1]->l;
      arv->filho[i] = remover(arv->filho[i], temp, t); 
      //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i]->l = temp;
      return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves >= t){ //CASO 2B
      printf("\nCASO 2B\n");
      TAB *y = arv->filho[i+1];  //Encontrar o sucessor k' de k na árvore com raiz em y
      while(!y->folha) y = y->filho[0];
      char temp = y->chave[0]->l;
      y = remover(arv->filho[i+1], temp, t); //Eliminar recursivamente K e substitua K por K' em x
      arv->chave[i]->l = temp;
      return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves == t-1 && arv->filho[i]->nchaves == t-1){ //CASO 2C
      printf("\nCASO 2C\n");
      TAB *y = arv->filho[i];
      TAB *z = arv->filho[i+1];
      y->chave[y->nchaves] = CriaNo(ch,0.0,0,0);
      y->chave[y->nchaves]->l = ch;  
      int j;
      for(j=0; j<t-1; j++){                //juntar chave[i+1] com chave[i]
        y->chave[t+j] = z->chave[j];
        z->chave[j] = NULL;
      }
      for(j=0; j<=t; j++) {                //juntar filho[i+1] com filho[i]
        y->filho[t+j] = z->filho[j];
      }
      y->nchaves = 2*t-1;
      for(j=i; j < arv->nchaves-1; j++){   //remover ch de arv
        arv->chave[j] = arv->chave[j+1];
        arv->chave[j+1] = NULL;
      }
      for(j=i+1; j <= arv->nchaves; j++)  //remover ponteiro para filho[i+1]
        arv->filho[j] = arv->filho[j+1];
      arv->filho[j] = NULL; //Campello
      arv->nchaves--;
      arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;   
    }   
  }

  TAB *y = arv->filho[i], *z = NULL;
  if (y->nchaves == t-1){ //CASOS 3A e 3B
    if((i < arv->nchaves) && (arv->filho[i+1]->nchaves >=t)){ //CASO 3A
      printf("\nCASO 3A: i menor que nchaves\n");
      z = arv->filho[i+1];
      y->chave[t-1] = arv->chave[i];
      arv->chave[i]=NULL;   //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i] = z->chave[0];
      z->chave[0]=NULL;     //dar a arv uma chave de z
      int j;
      for(j=0; j < z->nchaves-1; j++){  //ajustar chaves de z
        z->chave[j] = z->chave[j+1];
        z->chave[j+1]=NULL;
      }
      //z->chave[j] = 0; Rosseti
      y->filho[y->nchaves] = z->filho[0]; //enviar ponteiro menor de z para o novo elemento em y
      for(j=0; j < z->nchaves; j++){       //ajustar filhos de z
        z->filho[j] = z->filho[j+1];
      }
      z->nchaves--;
      arv->filho[i] = remover(arv->filho[i], ch, t);
      return arv;
    }
    if((i > 0) && (!z) && (arv->filho[i-1]->nchaves >=t)){ //CASO 3A
      printf("\nCASO 3A: i igual a nchaves\n");
      z = arv->filho[i-1];
      int j;
      for(j = y->nchaves; j>0; j--) {              //encaixar lugar da nova chave
        y->chave[j] = y->chave[j-1];
        y->chave[j-1]=NULL;
      }
      for(j = y->nchaves+1; j>0; j--)             //encaixar lugar dos filhos da nova chave
        y->filho[j] = y->filho[j-1];
      y->chave[0] = arv->chave[i-1];
      arv->chave[i-1]=NULL;              //dar a y a chave i da arv
      y->nchaves++;
      arv->chave[i-1] = z->chave[z->nchaves-1];
      z->chave[z->nchaves-1]=NULL; //dar a arv uma chave de z
      y->filho[0] = z->filho[z->nchaves];         //enviar ponteiro de z para o novo elemento em y
      z->nchaves--;
      arv->filho[i] = remover(y, ch, t);
      return arv;
    }
    if(!z){ //CASO 3B
      if(i < arv->nchaves && arv->filho[i+1]->nchaves == t-1){
        printf("\nCASO 3B: i menor que nchaves\n");
        z = arv->filho[i+1];
        y->chave[t-1] = arv->chave[i];
        arv->chave[i]=NULL;     //pegar chave [i] e coloca ao final de filho[i]
        y->nchaves++;
        int j;
        for(j=0; j < t-1; j++){
          y->chave[t+j] = z->chave[j];
          z->chave[j]=NULL; //passar filho[i+1] para filho[i]
          y->nchaves++;
        }
        if(!y->folha){
          for(j=0; j<t; j++){
            y->filho[t+j] = z->filho[j];
          }
        }
        for(j=i; j < arv->nchaves-1; j++){ //limpar referências de i
          arv->chave[j] = arv->chave[j+1];
          arv->chave[j+1]=NULL;
          arv->filho[j+1] = arv->filho[j+2];
        }
        arv->nchaves--;
        arv = remover(arv, ch, t);
        return arv;
      }
      if((i > 0) && (arv->filho[i-1]->nchaves == t-1)){ 
        printf("\nCASO 3B: i igual a nchaves\n");
        z = arv->filho[i-1];
        if(i == arv->nchaves){
          z->chave[t-1] = arv->chave[i-1];
          arv->chave[i-1]=NULL;
          } //pegar chave[i] e poe ao final de filho[i-1]
        else{
          z->chave[t-1] = arv->chave[i];
          arv->chave[i]=NULL;
        }   //pegar chave [i] e poe ao final de filho[i-1]
        z->nchaves++;
        int j;
        for(j=0; j < t-1; j++){
          z->chave[t+j] = y->chave[j];     //passar filho[i+1] para filho[i]
          y->chave[j]=NULL;
          z->nchaves++;
        }
        if(!z->folha){
          for(j=0; j<t; j++){
            z->filho[t+j] = y->filho[j];
          }
        }
        arv->nchaves--;
        arv->filho[i-1] = z;
        arv = remover(arv, ch, t);
        return arv;
      }
    }
  }  
  arv->filho[i] = remover(arv->filho[i], ch, t);
  return arv;
}


TAB* retira(TAB* arv, char k, int t){
  if(!arv || !Busca(arv, k)) return arv;
  return remover(arv, k, t);
}

NO* CriaNo(char l,float f,int v, int c){
  NO* novo;
  novo= (NO*) malloc(sizeof(NO));
  novo->l=l;
  novo->f=f;
  novo->v=v;
  novo->c=c;
  return novo;
}
void rastreia_cod(TAB* x, char ch){
    if(!x) return;
    int i = 0;
    while(i < x->nchaves && ch > x->chave[i]->l){
     i++;}
    if(i < x->nchaves && ch == x->chave[i]->l) {
		printf("%d", i);
		return;
    }
    if(x->folha) return;
    if(x->nchaves)
		printf("%d",i);
    rastreia_cod(x->filho[i], ch);
    return;
}
void decodifica_TAB(TAB* a){
  char letra[1000];
  int x,n,tamk,l;
    n=0;
    int i=0;
    printf("Digite a menssagem\n");
    printf("para parar digite: -\n");
    setbuf(stdin, NULL);
    scanf("%[^\n]s",letra);
    setbuf(stdin, NULL);
    tamk = strlen(letra);
    TAB* q;
    while(n<tamk){
      q=a;
      if(q->nchaves){
      i=n;
      for(x=letra[n]-48;x>=0;x--){
        n++;
		    i++;
		l = letra[i] - 48;
		if (x == 0)
			break;
		  q=q->filho[l];
      }
      n++;
      printf("%c",q->chave[l]->l);

    }else{
      a=a->filho[0];
    }
    }
    printf("\n");

}

void Escreve_arqui(TAB *a){
  char vetl[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  char vet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  TAB* elem;
  FILE *existe;
  FILE *wr;
  existe=fopen("existe.txt","rt");
  char nome[120];
  printf("Digite o nome do arquivo(exemplo: Alanturin.txt)\n");
  scanf(" %s", nome);
  printf("passei");
  wr=fopen(nome,"wt");
  printf("passei");
  if(!wr){
    printf("nao abriu");
    exit(1);
  };
  for(int i=0;i<26;i++){
    elem=Busca(a,vetl[i]);
    if (elem){
      for(int j=0;j<elem->nchaves;j++){
        if(elem->chave[j]->l==vetl[i]){
        fprintf(wr,"%c %.2f %d %d\n",elem->chave[j]->l,elem->chave[j]->f,elem->chave[j]->v,elem->chave[j]->c);
        break;
        }
      }
    }
  }
  for(int i=0;i<26;i++){
    elem=Busca(a,vet[i]);
    if (elem){
        for(int j=0;j<elem->nchaves;j++){
          if(elem->chave[j]->l==vet[i]){
          fprintf(wr,"%c %.2f %d %d\n",elem->chave[j]->l,elem->chave[j]->f,elem->chave[j]->v,elem->chave[j]->c);
          break;
          }
        }
    }
  }
  fclose(wr);
  int e;
  fscanf(existe,"%d",&e);
  fclose(existe);
  printf("%d",e);
  if(e>0){
    int i=0;
      Escreve_aux(&e,nome);
      existe=fopen("existe.txt","wt");
      if(!existe){
        printf("Erro ao abrir o arquivo para salvar\n");
        exit(1);
    }
  fprintf(existe,"%d",e);
  fclose(existe);
  return;
  }
  Escreve_aux(&e,nome);
  existe=fopen("existe.txt","wt");
  if(!existe){
    printf("Erro ao abrir o arquivo para salvar\n");
    exit(1);
  }
  fprintf(existe,"%d",e);
  fclose(existe);
  return;
}
void Escreve_aux(int *e,char *nome){
  FILE *nomes;
  int i=0;
  nomes=fopen("nome.txt","rt");
  if(!nomes){
       printf("Erro ao abrir o arquivo para salvar\n");
       exit(1);
      }
  if(*e>0){
  do{
      i++;
      char nomeaq[120];
      fscanf(nomes,"%s",nomeaq);
      if (!strcmp(nomeaq,nome)){
           fclose(nomes);
        return;
      }
     } while (i<*e);
      fclose(nomes);
      nomes=fopen("nome.txt","a+");
      if(!nomes){
       printf("Erro ao abrir o arquivo para salvar\n");
       exit(1);
      }
      fprintf(nomes,"%s",nome);
      *e+=1;
      fclose(nomes);
  }
  nomes=fopen("nome.txt","a+");
  if(!nomes){
   printf("Erro ao abrir o arquivo para salvar\n");
   exit(1);
  }
  fprintf(nomes,"%s\n",nome);
  *e+=1;
  fclose(nomes);
}
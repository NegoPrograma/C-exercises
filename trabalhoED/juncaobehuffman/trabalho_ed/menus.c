#include "menus.h"

NODE* menurem(TAB *a,NODE* raiz,int t){
    char lixo;
    char taux[100];
    int op;
    do{
    printf("**************************************************\n");
    printf("*\n");
    printf("*    1-remover elemento na arvore\n");
    printf("*    2-remover todas as vogais na arvore\n");
    printf("*    3-remover todas as consoantes na arvore\n");
    printf("*    4-remover todas as letras maiusculas na arvore\n");
    printf("*    5-remover todas as letras minusculas na arvore\n");
    printf("*    6-sair\n");
    printf("*\n");
    do{
        
        printf("Digite a opção desejada: ");
        scanf(" %s",taux);
        op=atoi(taux);
  } while ((op<1)||(op>6));
   raiz = opcaoRemovePorChaves(raiz,op);
    if(op==1){
        while(1){
            printf("Digite o elemento q quer remover da arvore B:\n");
            printf("Para parar de remover digite : -  \n");            
            scanf(" %c",&lixo);
            if(lixo=='-')break;
            a = retira(a,lixo,t);
            raiz = opcaoRemove(raiz,&lixo);
            Imprime(a,0);
        }
    }else if(op==2){
        remove_vog(a,t);
        Imprime(a,0);
    }else if(op==3){
        remove_cons(a,t);
        Imprime(a,0);
    }else if(op==4){
        remove_Mai(a, t);
        Imprime(a,0);
    }else if(op==5){
        remove_Mini(a,t);
        Imprime(a,0);
    }
    
    }while(op!=6);
    imprimeArvore(raiz);
    return raiz;
}

NODE* menuins(TAB* a,NODE* raiz,int t){
    char l;
    float f;
    do{
    setbuf(stdin, NULL);
    printf("Digite a letra a ser inserida: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    do{
    printf("Digite a frequencia da letra a ser inserida: ");
    scanf(" %f", &f);
    }while((f<0||f>100));
    TAB* elem=Busca(a,l);
    if(!elem){
    raiz = opcaoAdicionaLetra(raiz,f,l);
    }
    a=Insere(a,l,f,verfica_max(l),verfica_vog(l),t);
    imprimeArvore(raiz);
    Imprime(a,0);
    return raiz;
}

NODE* menufreqalt(TAB* a,NODE*raiz){
    char l;
    float f;
    do{
    printf("Digite a letra que deseja alterar a frequencia: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    do{
    printf("Digite a nova frequencia: ");
    scanf("%f", &f);
    }while((f<0||f>100));
    TAB *elem;
    elem=Busca(a,l);
    if(elem){
        int i;
        for(i=0;i<elem->nchaves;i++){
        if (elem->chave[i]->l==l){
            elem->chave[i]->f=f;
            break;
        }
        }
        raiz = opcaoAlteraFrequencia(raiz,f,l);
    }else{
        printf("Este elemento n existe na arvore.\n\n");
    }
    return raiz;

}

void menucod(TAB* a,int t){
    char letra[1000];
    int p,tam;
    while(1){
      printf("Digite a menssagem\n");
      printf("para parar digite: -\n");
      setbuf(stdin, NULL);
      scanf("%[^\n]s",letra);
      setbuf(stdin, NULL);
      p=0;
      if (letra[0]=='-')
      {
      break;
      }
      tam=strlen(letra);
      while(p<tam){
        if (Busca(a,letra[p])){
          rastreia_cod(a,letra[p]);
        }else{
          printf("?");
        }
        p++;
      }
      printf("\n");
    }
}

void menuelem(TAB* a,NODE* raiz){
    char l;
    do{
    printf("Digite a letra que deseja obter informação: ");
    scanf(" %c", &l);
    }while((l<65||l>90)&&(l<97 ||l>122));
    TAB *elem;
    elem=Busca(a,l);
    printf("\n\n");
    opcaoMostraNos(raiz,&l);
    if(elem){
        int i;
        for(i=0;i<elem->nchaves;i++){
            if (elem->chave[i]->l==l){
                
                printf("Esta letra existe na arvore:\n");
                printf("Frequencia: %.2f ela é uma %s, e é %s.\n\n",elem->chave[i]->f, strinvog(elem,i),strinmax(elem,i));
                break;
            }
        }
        
    }else{
        printf("Este elemento n existe na arvore.\n\n");
    }
}

char* strinvog(TAB* elem,int i){
    char static vogal[]="vogal";
    char static cons[]="consoante";
    if(elem->chave[i]->v){
       return vogal;
    }
    return cons;
}

char* strinmax(TAB* elem,int i){
    char static maiu[]="maiuscula";
    char static minu[]="minuscula";
    if(elem->chave[i]->v){
       return maiu;
    }
    return minu;
}

void remove_vog(TAB *a, int t){
    if(a){
        int i,j;
        char vet[5]={'a','e','i','o','u'};
        char vet1[5]={'A','E','I','O','U'};
        for(i=0;i<5;i++){
            a = retira(a,vet[i],t);
            a = retira(a,vet1[i],t);
        }
    }
}

void remove_cons(TAB *a, int t){
    if(a){
        int i;
        char vet[21]={'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
        char vet1[21]={'B','C','D','F','G','H','J','K','L','M','N','P','Q','R','S','T','V','W','X','Y','Z'};
        for(i=0;i<21;i++){
            a = retira(a,vet[i],t);
            a = retira(a,vet1[i],t);
        }
    }
}

void remove_Mai(TAB *a, int t){
    if(a){
        int i;
        char vet[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        for(i=0;i<26;i++){
            a = retira(a,vet[i],t);
        }
    }
}

void remove_Mini(TAB *a, int t){
    if(a){
        int i;
        char vet[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(i=0;i<26;i++){
            a = retira(a,vet[i],t);
        }
    }
}

int verfica_vog(char l){
  if (((l==97) || (l==101) || (l==105) || (l==111) || (l==117))||((l==65) || (l==69) || (l==73) || (l==79) || (l==85))) return 1;
  return 0;  
}

int verfica_max(char l){
  if (l>=65 && l<=90) return 1;
  return 0;  
}

void corrige(TAB*a,int t){
    while(!a->chave){
		a = a->filho[0];
    }
}
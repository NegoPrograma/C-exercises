#include "menus.h"
#include <string.h>

int main(void){
  FILE *existe,*nomes,*fp;
  int i=0,e,p,tam;
  TAB *a;
  char c,desejo;
  char nomeArquivo[120];
  char letra[1000];
  a=NULL;
  Lista* ldf = NULL;
  ldf = leituraArquivo("default.txt");
  NODE* raiz = NULL;
  raiz = avh(ldf,raiz);
  do{
    printf("Deseja abrir a configuração das arvores atraves de um arquivo editado?[s/n]\n");
    scanf(" %c",&desejo);
    printf("\n\n");
  } while ((desejo!='s')&&(desejo!='n'));
  if(desejo=='s'){
    existe=fopen("existe.txt","rt");
    if(!existe) exit(1);
    fscanf(existe,"%d",&e);
    fclose(existe);
    if(e>0){
    nomes=fopen("nome.txt","rt");
    printf("Nomes dos arquivos disponiveis:\n");
    do
    {
    i++;
    char* nome = (char*) malloc(sizeof(char)*120);
    fscanf(nomes,"%s",nome);
    printf("%s\n",nome);
    } while (i<e);
    fclose(nomes);
    printf("\n\n\n\n");
    printf("Digite o nome do arquivo desejado exemplo: alanturin.txt : \n");
    scanf("%s",nomeArquivo);
    fp= fopen(nomeArquivo,"rt");
    if(fp==NULL){
        printf("Não existe o arquivo no diretorio corrente ou ocorreu um erro ao abrir.\n");
        exit(1);
    }
  }else{
      printf("Não existe um arquivo personalizado, abrindo arquivo de configuração padrao\n");
      fp=fopen("default.txt","rt");
      if(!fp)
        exit(1);

    }
  }else if(desejo=='n'){
    fp=fopen("default.txt","rt");
      if(!fp)
        exit(1);
  }
  printf("\n\n");
  int t,lr;
  do{
  char taux[1000];
  printf("Digite o numero T da arvore B:\n");
  scanf(" %s",taux);
  t=atoi(taux);
  } while ((t<2)||(t>5));
  a=Inicia_arquivo(a,t,fp);
  
  fclose(fp);
  Imprime(a,0);
  int op1;
  do{
  int op;
  printf("**************************************************\n");
  printf("*\n");
  printf("*    1-inserir elemento na arvore\n");
  printf("*    2-remover elemento na arvore\n");
  printf("*    3-alterar a frequencia\n");
  printf("*    4-imprimir a arvore\n");
  printf("*    5-codificar uma menssagem\n");
  printf("*    6-decodificar uma menssagem\n");
  printf("*    7-buscar informação de uma letra \n");
  printf("*    8-sair\n");
  printf("*\n");
  do{
  char taux[10];
  printf("Digite a opção desejada: ");
  scanf(" %s",taux);
  op=atoi(taux);
  op1=op;
  } while ((op<1)||(op>8)); 
  if (op==1){
 raiz =  menuins(a,raiz,t);
  }else if(op==2){
   raiz = menurem(a,raiz,t);
  }else if(op==3){
  raiz =  menufreqalt(a,raiz);
  }else if(op==4){
    do{
      printf("Qual árvore deseja ver?\n 1 - Árvore B\n 2 - Árvore de Huffman\nPara sair, digite 0\n");
    scanf("%d",&op);
    if(op == 2)
      imprimeArvore(raiz);
    else if (op == 1)
      Imprime(a,0);
    }while(op!=0);
  }else if(op==5){
    int op3;
    char palavra[1000];
    do{
    char taux2[10];
    printf("**************************************************\n");
    printf("*\n");
    printf("*    1-Codificar na arvore B\n");
    printf("*    2-Codificar na arvore Huffman\n");
    printf("*    3-Codificar em Ambas\n");
    printf("*    4-sair\n");
    printf("Digite a opção desejada: ");
    scanf(" %s",taux2);
    op3=atoi(taux2);
    if(op3==4)break;
    } while ((op3<1)||(op3>3));
    if(op3 < 4){
    printf("Digite a mensagem a ser codificada:\n ");
    scanf(" %[^\n]",palavra);
    menucod(a,palavra,raiz,op3);
    }

  }else if(op==6){
    int op6;
    do{
      printf("Deseja decifrar a mensagem na Árvore B ou em Huffman?\n1 - Árvore B\n2 - Huffman\n");
      scanf("%d",&op6);
    }while(op6 != 1 && op6 != 2);
    if(op6 == 1){
    int x,n,tamk,l;
    n=0;
    int i=0;
    printf("Digite a menssagem\n");
    setbuf(stdin, NULL);
    scanf(" %[^\n]s",letra);
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
    //huffman a baixo
    } else{
      opcaoDecodifica(raiz);
    }
  }else if (op==7){
    menuelem(a,raiz);
  }
  }while(op1!=8);
  // do
  // {
  // printf("deseja salvar as alterações?[s/n]\n");
  // scanf(" %c",&desejo);
  // } while ((desejo!='s')&&(desejo!='n'));
  // if(desejo=='s'){
  //   Escreve_arqui(a);
  //   return 0;
  // }
  ldf = leituraArquivo("default.txt");
  atualizaArquivo(ldf);

return 0;
}
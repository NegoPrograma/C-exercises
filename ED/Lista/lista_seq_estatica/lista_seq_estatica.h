#include <stdio.h>


#define MAX 100
typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

typedef struct lista{
    int quantidade;// determina quantos espaços do vetor abaixo já foram utilizados
    Aluno dados[MAX];
}Lista;


//funções

Lista* cria_lista();

int tamanho_lista(Lista* li);

void libera_lista(Lista* li);

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

void insere_final(Lista* li,Aluno estudante);

void insere_inicio(Lista* li,Aluno estudante);

void insere_meio(Lista* li,Aluno estudante);

void remove_final(Lista* li);

void remove_inicio(Lista* li);

void remove_meio(Lista* li,int matricula);

void consulta_info_posicao(Lista*li, int posicao, Aluno* estudante);

void consulta_info_conteudo(Lista*li);
#include <stdio.h>
#include <stdlib.h>
#include "lista_seq_estatica.h"



Lista* cria_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        li->quantidade= 0;
        return li;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->quantidade;
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    else
        return (li->quantidade == MAX);
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    else
        return (li->quantidade == 0);
}

void libera_lista(Lista* li){
    free(li);
}

void insere_final(Lista* li, Aluno estudante){
    if(li != NULL)
        if(!(lista_cheia(li))){
            li->dados[li->quantidade] = estudante;
            li->quantidade++;
        }
    }


void insere_inicio(Lista* li,Aluno estudante){
    if(li != NULL)
        if(!(lista_cheia(li))){
            for(int i = li->quantidade; i >=0; i--){
                li->dados[i+1] = li->dados[i];
            }
            li->dados[0] = estudante;
            li->quantidade++;
        }
}

void insere_inicio(Lista* li,Aluno estudante){
    if(li != NULL)
        if(!(lista_cheia(li))){
            //vamos do último do primeiro pra garantir que nenhum dado é sobrescrito
            for(int i = li->quantidade; i >=0; i--){
                li->dados[i+1] = li->dados[i];
            }
            li->dados[0] = estudante;
            li->quantidade++;
        }
}


void insere_meio(Lista* li,Aluno estudante){
    if(li != NULL)
        if(!(lista_cheia(li))){

            int posicao = 0;

            //usamos essa condição porque a ordenação de alunos depende da matrícula, então iteramos sobre a lista e vemos qual maricula é maior
            while(posicao<li->quantidade && li->dados[posicao].matricula > estudante.matricula)
                posicao++;

            //vamos do último do primeiro pra garantir que nenhum dado é sobrescrito
            for(int i = li->quantidade; i >=posicao; i--){
                li->dados[i+1] = li->dados[i];
            }
            li->dados[posicao] = estudante;
            li->quantidade++;
        }
}

void remove_final(Lista* li){
    if(li != NULL)
        if(!lista_vazia(li))
            li->quantidade--;
}

void remove_inicio(Lista* li){
    if(li != NULL)
        if(!lista_vazia(li)){

            for(int i = 0;i < li->quantidade-1; i++){
                li->dados[i] = li->dados[i+1];
            }
            li->quantidade--;
        }
}

void remove_meio(Lista* li,int matricula){
            int posicao = 0;
            while( posicao < li->quantidade && li->dados[posicao].matricula != matricula)
                posicao++;

            for(int i = posicao;i < li->quantidade-1; i++){
                li->dados[i] = li->dados[i+1];
            }
            li->quantidade--;
        }

void consulta_info_posicao(Lista*li, int posicao, Aluno* estudante){

}


int main(){
    
    Lista* li = cria_lista();
    
    
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//a TAD que usaremos é baseada num ponto de plano cartesiano em R²

typedef struct ponto{
    float x;
    float y;
}Ponto;

Ponto* cria_ponto(float x, float y);

void exclui_ponto(Ponto* p);

void acessa_ponto(Ponto* p, float* x, float* y);

void atribui_ponto(Ponto* p, float x, float y);

float dist_dois_pontos(Ponto* a, Ponto* b);



    /* arquivo.h: 

    1° passo:
    -protótipos de funções
    -tipos de ponteiro
    - dados globais*/


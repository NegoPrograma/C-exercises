#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TAD.h"

Ponto* cria_ponto(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }

    return p;
}

void exclui_ponto(Ponto* p){
    free(p);
}

//usamos 2 ponteiros para guardar os valores do ponto, não sei porque, mas é
void acessa_ponto(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

void atribui_ponto(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

float dist_dois_pontos(Ponto* a, Ponto* b){
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    return ((dx*dx) + (dy*dy))/dx*dy;
}


// void atribui_ponto(Ponto* p, float x, float y);

// float dist_dois_pontos(Ponto* a, Ponto* b);


int main(){
   float d;
   Ponto *p, *q;
   p = cria_ponto(2,0);
   q = cria_ponto(4,0);
   d = dist_dois_pontos(p,q);
   printf("%.2f",d);
   exclui_ponto(p);
   exclui_ponto(q);

    return 0;
}

#include "tarvb.h"
#include "avh.h"

void corrige(TAB*a,int t);
int verfica_vog(char l);
int verfica_max(char l);
void menuelem(TAB* a,NODE* raiz);
NODE* menuins(TAB* a,NODE* raiz,int t);
NODE* menufreqalt(TAB* a,NODE* raiz);
void menucod(TAB* a,int t);
void menurem(TAB* a,NODE** raiz,int t);
void remove_vog(TAB *a, int t);
void remove_cons(TAB *a, int t);
void remove_Mai(TAB *a, int t);
void remove_Mini(TAB *a, int t);
char* strinvog(TAB* elem,int i);
char* strinmax(TAB* elem,int i);
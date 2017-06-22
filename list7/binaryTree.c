#include <stdlib.h>
typedef struct ab{
    int info;
    struct ab *esq, *dir;
}TAB;

TAB *cria(int info){
    TAB *novo = malloc(sizeof(TAB));
    novo->info=info;
    return novo;
}

TAB *copia(TAB *a){
    if(!a){
        return a;
    }

    TAB *novo = cria(a->info);
    if(a->dir){
        novo->dir= copia(a->dir);
    }
    if(a->esq){
        novo->esq= copia(a->esq);
    }
    return novo;
}


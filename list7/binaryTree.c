#include <stdlib.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TAB;

TAB *cria(int info) {
    TAB *novo = malloc(sizeof(TAB));
    novo->info = info;
    return novo;
}

TAB *copia(TAB *a) {
    if (!a) {
        return a;
    }

    TAB *novo = cria(a->info);
    if (a->dir) {
        novo->dir = copia(a->dir);
    }
    if (a->esq) {
        novo->esq = copia(a->esq);
    }
    return novo;
}

TAB *espelho(TAB *a) {
    if (!a) {
        return a;
    }

    TAB *novo = cria(a->info);
    if (a->dir) {
        novo->dir = copia(a->esq);
    }
    if (a->esq) {
        novo->esq = copia(a->dir);
    }
    return novo;
}

int igual(TAB *a, TAB *b) {
    if (!a && !b) {
        return 1;
    }
    if (!a || !b) {
        return 0;
    }
    if (a->info == b->info) {
        return igual(a->dir, b->dir) && igual(a->esq, b->esq);
    }
    return 0;
}

/*
TAB *retira_impares(TAB *a) {
    if (!a) {
        return a;
    }
    if (a->info % 2) {
        if (!a->dir && !a->esq) {
            free(a);
            return NULL;
        } else if (!a->esq) {
            TAB *t = a;
            a = a->dir;
            free(a);
            retira_impares(a);
        } else if (!a->dir) {
            TAB *t = a;
            a = a->esq;
            free(a);
            retira_impares(a);
        } else {
            TAB *t = a;
            while (t->dir) {
                t = t->dir;
            }
            a->info = f->info;
            f->info = elem;
            a->esq = retira_impares(a->esq, elem);
        }
    }
}
 */

void libera(TAB *a) {
    if (a) {
        libera(a->dir);
        libera(a->esq);
        free(a);
    }
}

static int value = 0;

int ni(TAB *a){
    if(!a){
        return 0;
    }
    int count = 0;
    if(a->dir || a->esq){
        count+=1;
    }
    if(a->dir){
        count += ni(a->dir);
    }
    if(a->esq){
        count += ni(a->esq);
    }
    return count;

}
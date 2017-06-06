#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct fila {
    TNO *ini, *fim;
} TFila;

int vazia_f(TFila *f) {
    return f->ini == NULL;
}

TFila *inicia_f(void) {
    TFila *p = malloc(sizeof(TFila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}

TFila *insere(TFila *f, int elem) {
    if (!f) {
        f = inicia_f();
    }
    TNO *novo = malloc(sizeof(TNO));
    novo->prox = NULL;
    novo->info = elem;
    if (vazia_f(f)) {
        f->ini = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return f;
}

int retira(TFila *f) {
    if (vazia_f(f)) {
        exit(1);
    }
    int info = f->ini->info;
    TNO *p = f->ini;
    f->ini = f->ini->prox;
    free(p);
    if (!f->ini) {
        f->fim = NULL;
    }
    return info;
}

void libera_f(TFila *f) {
    TNO *p = f->ini;
    while (p) {
        TNO *q = p;
        p = p->prox;
        free(q);
    }
    free(p);
}



TFila* inv_fila (TFila *f){
    TPilha *aux = inicia_p();
    while(!vazia_f(f)){
        push(aux,retira(f));
    }
    TFila *fim = inicia_f();
    while(!vazia_p(aux)){
        insere(fim,pop(aux));
    }
    libera_p(aux);
    return fim;
}
#include <stdio.h>
#include <stdlib.h>
#include "node.c"

typedef struct fila {
    TNO *ini, *fim;
} TFila;

int vazia(TFila *f) {
    return f->ini == NULL;
}

TFila *inicializa(void) {
    TFila *p = malloc(sizeof(TFila));
    p->ini = NULL;
    p->fim = NULL;
    return p;
}

TFila *insere(TFila *f, int elem) {
    if (!f) {
        f = inicializa();
    }
    TNO *novo = malloc(sizeof(TNO));
    novo->prox = NULL;
    novo->info = elem;
    if (vazia(f)) {
        f->ini = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    return f;
}

int retira(TFila *f) {
    if (vazia(f)) {
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

void libera(TFila *f) {
    TNO *p = f->ini;
    while (p) {
        TNO *q = p;
        p = p->prox;
        free(q);
    }
    free(p);
}
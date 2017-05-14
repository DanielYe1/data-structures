#include <stdio.h>
#include <stdlib.h>
#include "node.h"

typedef struct pilha {
    TNO *topo;
} TPilha;

TPilha *inicia_p(void) {
    TPilha *p = malloc(sizeof(TNO));
    p->topo = NULL;
    return p;
};

void push(TPilha *p, int elem) {
    TNO *novo = malloc(sizeof(TNO));
    novo->info = elem;
    novo->prox = p->topo;
    p->topo = novo;
}

int vazia_p(TPilha *p) {
    return p->topo == NULL;
}

int pop(TPilha *p) {
    if (vazia_p(p)) {
        exit(1);
    }
    TNO *q = p->topo;
    p->topo = q->prox;
    int info = q->info;
    free(q);
    return info;
}

void libera_p(TPilha *p) {
    TNO *q = p->topo;
    while(q){
        TNO *t = q;
        q=q->prox;
        free(t);
    }
}

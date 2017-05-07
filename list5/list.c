#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} TLSE;

TLSE *create() {
    return NULL;
}

TLSE *ins_ini(TLSE *l, int value) {
    TLSE *first = (TLSE *) malloc(sizeof(TLSE));
    first->prox = l;
    first->info = value;
    return first;
}

TLSE *ins_final(TLSE *l, int value) {
    if (!l)
        return ins_ini(l, value);

    TLSE *p = l;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = ins_ini(NULL, value);
    return l;
}

TLSE *find(TLSE *l, int value) {
    while (((l) && (l->info != value))) {
        l = l->prox;
    }
    return l;
}

void print(TLSE *l) {
    while (l) {
        printf("%d ", l->info);
        l = l->prox;
    }
    printf("\n");
}

void clean(TLSE *l) {
    while (l) {
        TLSE *p = l;
        l = l->prox;
        free(p);
    }
}

TLSE *ins_ord(TLSE *l, int value) {
    TLSE *ant = NULL, *p = l;
    while ((p) && (l->info < value)) {
        ant = p;
        p = p->prox;
    }
    if (!ant) {
        return ins_ini(l, value);
    } else {
        ant->prox = ins_ini(ant->prox, value);
        return l;
    }
}

TLSE *remove_first_value(TLSE *l, int value) {
    TLSE *ant = NULL, *p = l;
    while ((p) && (p->info != value)) {
        ant = p;
        p = p->prox;
    }
    if (!p) return l;
    if (!ant)l = l->prox;
    else ant->prox = p->prox;
    return l;
}

void sort(TLSE *l) {
    TLSE *p, *menor = l;
    for (p = l; p; p->prox) {
        if (menor->info > p->info) {
            menor = p;
        }
    }
    if (menor != p) {
        int temp = menor->info;
        menor->info = p->info;
        p->info = temp;
    }
}

void inverte(TLSE *l){
    TLSE *aux = create(),*p;
    p=l;
    while(p){
        aux = ins_ini(aux,p->info);
        p=p->prox;
    }
    p=l;
    while(aux){
        p->info = aux->info;
        aux=aux->prox;
        p=p->prox;
    }
    free(aux);
    free(p);
}
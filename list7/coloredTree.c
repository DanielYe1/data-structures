#include <stdlib.h>

typedef struct abc {
    int info;
    int cor;
    struct abc *esq, *dir;
} TABC;

void coloreRec(TABC *a, int cor) {
    if (!a) {
        return;
    }
    a->cor = cor;
    if (cor) {
        cor = 0;
    } else {
        cor = 1;
    }
    if (a->dir)
        coloreRec(a->dir, cor);
    if (a->esq)
        coloreRec(a->esq, cor);
}

void colore(TABC *a) {
    int cor = 0;
    coloreRec(a, cor);

}

TABC *cria(int info) {
    TABC *novo = malloc(sizeof(TABC));
    novo->info = info;
    return novo;
}

void libera(TABC *a) {
    if (a) {
        libera(a->dir);
        libera(a->esq);
        free(a);
    }
}
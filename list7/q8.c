#include <stdio.h>
#include "coloredTree.c"

int main() {
    TABC *t = cria(4);
    t->dir = cria(1);
    t->esq = cria(5);
    t->dir->dir = cria(2);
    t->dir->esq = cria(2);
    t->esq->esq = cria(3);
    t->esq->dir = cria(3);

    colore(t);

    libera(t);

    return 0;
}
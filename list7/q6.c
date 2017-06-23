#include <stdio.h>
#include "binaryTree.c"

int main() {
    TAB *t = cria(4);
    t->dir = cria(1);
    t->esq = cria(5);
    t->dir->dir = cria(2);
    t->esq->esq = cria(3);

    TAB *b = cria(4);
    b->dir = cria(1);
    b->esq = cria(5);
    b->dir->dir = cria(2);
    b->esq->esq = cria(3);

    libera(t);
    libera(b);


    printf("%d",igual(t,b));
    return 0;
}
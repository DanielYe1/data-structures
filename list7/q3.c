#include <stdio.h>
#include "binaryTree.c"

int main() {
    TAB *t = cria(4);
    t->dir = cria(1);
    t->esq = cria(5);
    t->dir->dir = cria(2);
    t->esq->esq = cria(3);
    TAB *i = espelho(t);

    printf("1\n");
    return 0;
}
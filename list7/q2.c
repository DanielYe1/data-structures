#include <stdio.h>
#include "binaryTree.c"

int main() {
    TAB *t = cria(4);
    t->dir = cria(1);
    t->esq = cria(5);
    t->dir->dir = cria(1);
    TAB *i = copia(t);
    libera(i);
    libera(t);

    printf("1\n");
    return 0;
}
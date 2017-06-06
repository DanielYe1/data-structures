#include <stdio.h>
#include "stack.c"
#include "queue.c"

TFila *p2f(TPilha *p) {
    if (!p) {
        return NULL;
    }
    TFila *fila = inicia_f();
    TNO *it = p->topo;
    while (it) {
        insere(fila, it->info);
        it= it->prox;
    }
    free(it);
    return fila;
}

int main() {
    TPilha *pilha = inicia_p();
    int i;
    for (i = 0; i < 4; ++i) {
        push(pilha,i);
    }

    TFila *fila = p2f(pilha);

    libera_p(pilha);
    libera_f(fila);

    return 0;
}
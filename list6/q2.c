#include <stdio.h>
#include "queue.c"
#include "stack.c"


int main() {
    TFila *myqueue = inicia_f();
    for (int i = 0; i < 3; ++i) {
        insere(myqueue,i);
    }
    TFila *inverted = inv_fila(myqueue);

    libera_f(myqueue);
    libera_f(inverted);
    return 0;
}
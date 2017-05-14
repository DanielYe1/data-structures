#include <stdio.h>
#include "queue.c"
#include "stack.c"

TPilha *f2p(TFila *f){
    TPilha *aux = inicia_p(), *fim = inicia_p();
    while(f->ini){
        push(aux,retira(f));
    }
    while(!vazia_p(aux)){
        push(fim,pop(aux));
    }
    return fim;
}

int main() {
    TFila *fila = inicia_f();
    for (int i = 0; i < 4; ++i) {
        insere(fila,i);
    }
    TPilha *pilha = f2p(fila);

    libera_f(fila);
    libera_p(pilha);
    return 0;
}
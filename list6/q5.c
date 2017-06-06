#include <stdio.h>
#include "stack.c"

void retira_pares (TPilha *p){
    if(p) {
        TPilha *aux = inicia_p();
        while (!vazia_p(p)) {
            int x = pop(p);
            if(x%2==0){
                push(aux,x);
            }
        }
        while(!vazia_p(aux)){
            push(p,pop(aux));
        }
        libera_p(aux);
    }
}

int main() {
    TPilha *pilha = inicia_p();
    for (int i = 0; i < 4; ++i) {
        push(pilha,i);
    }

    retira_pares(pilha);

    libera_p(pilha);


    return 0;
}
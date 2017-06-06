#include <stdio.h>
#include "queue.c"
#include "stack.c"

int verifica_primeiro(TFila *f){
    return f->ini->info;
}

TFila* sep_fila (TFila *f){
    TFila *pares = inicia_f();
    if(vazia_f(f)){
        return pares;
    }
    while(f->ini){

    }


}

int main() {

    return 0;
}
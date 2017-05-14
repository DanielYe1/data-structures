#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
    int mat;
    float cr;
    struct aluno *prox;
} TAluno;

TAluno *copia(TAluno *l) {
    TAluno *p = NULL, *aux = l;
    TAluno *a=NULL;

    if(aux){
        p = malloc(sizeof(TAluno));
        p->mat = aux->mat;
        p->cr = aux->cr;
        a = p;
        aux = aux->prox;
    }
    while (aux) {
        p->prox = malloc(sizeof(TAluno));
        p->prox->mat = aux->mat;
        p->prox->cr = aux->cr;

        p = p->prox;
        aux = aux->prox;
    }
    return a;
}

int main() {
    TAluno *um = malloc(sizeof(TAluno));
    um->mat = 10;
    um->prox = malloc(sizeof(TAluno));
    um->prox->prox=malloc(sizeof(TAluno));

    TAluno *dois = copia(um);

    printf("1");
    return 0;
}
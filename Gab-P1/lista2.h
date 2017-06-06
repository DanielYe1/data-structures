#include <stdio.h>
#include <stdlib.h>

typedef struct lista2{
  int info;
  struct lista2 *ant, *prox;
} TLista2;

TLista2* insere(TLista2 *l, int elem);
void imprime(TLista2 *l);
void libera(TLista2 *l);
TLista2* retira(TLista2 *l, int elem);
TLista2* busca(TLista2 *l, int elem);


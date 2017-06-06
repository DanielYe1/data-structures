#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
  char info[31];
  struct lc *prox;
} TLC;

TLC* insere(TLC *l, char *info);
TLC* retira(TLC *l, char *info);
void imprime(TLC *l);
void libera(TLC *l);

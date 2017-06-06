#include "lista2.h"

TLista2* insere(TLista2 *l, int elem){
  TLista2 *novo = (TLista2 *) malloc(sizeof(TLista2));
  novo->ant = NULL;
  novo->prox = l;
  novo->info = elem;
  if(l) l->ant = novo;
  return novo;
}

void imprime(TLista2 *l){
  TLista2 *p = l;
  while(p){
    printf("% d ", p->info);
    p = p->prox;
  } 
}

void libera(TLista2 *l){
  TLista2 *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

TLista2* retira(TLista2 *l, int elem){
  TLista2 *p = busca(l, elem);
  if(!p) return l;
  if(p == l) l = l->prox;
  else p->ant->prox = p->prox;
  if(p->prox) p->prox->ant = p->ant;
  free(p);
  return l;
}

TLista2* busca(TLista2 *l, int elem){
  TLista2 *p = l;
  while(p){
    if(p->info == elem) return p;
    p = p->prox;
  } 
  return NULL;
}


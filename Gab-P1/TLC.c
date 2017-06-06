#include "TLC.h"

TLC* insere(TLC *l, char *info){
  TLC* novo = (TLC*) malloc (sizeof(TLC));
  strcpy(novo->info, info);
  if(!l){
    novo->prox = novo;
    return novo;
  }
  TLC *p = l->prox, *ant = l;
  while(p != l){
    ant = p;
    p = p->prox;
  }
  novo->prox = l;
  ant->prox = novo;
  return l;
}

TLC* retira(TLC *l, char *info){
  if((!l) || ((l->prox == l) && (!strcmp(l->info, info)))){
    if(l) free(l);
    return NULL;
  }

  TLC *p = l->prox, *ant = l;
  while((p != l) && (strcmp(p->info, info))){
    ant = p;
    p = p->prox;
  }

  if((p == l) && (strcmp(l->info, info))) return l;
  ant->prox = p->prox;
  if(p == l) l = l->prox;
  free(p);
  return l;
}
 
void imprime(TLC *l){
  if(l){
    printf("%s\t", l->info);
    TLC *p = l->prox;
    while(p != l){
      printf("%s\t", p->info);
      p = p->prox;
    }
    printf("\n");
  }
}

void libera(TLC *l){
  if(l){
    TLC *p = l->prox;
    while(p != l){
      TLC *temp = p;
      p = p->prox;
      free(temp);
    }
    free(l);
  }
}

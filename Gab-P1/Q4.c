//
// Q4
//
#include "TLC.h"

int jp(TLC *l, int passo){
  if((!l) || (passo <= 0)) return 0;

  if(l->prox == l) return 1;

  TLC *laux = NULL;
  laux = insere(laux, l->info);
  TLC *p = l->prox;
  while(p != l){
    laux = insere(laux, p->info);
    p = p->prox;
  }

  int j;
  p = laux;
  while(laux->prox != laux){
    j = 0;
    while(j != passo){
      j++;
      p = p->prox;
    }
    printf("%s morreu...\n", p->info);
    char aux[31];
    strcpy(aux, p->info);
    p = p->prox;
    laux = retira(laux, aux);
  }

  int num = 1;
  p = l;
  do{
    if(strcmp(p->info, laux->info) == 0){
      libera(laux);
      return num;
    }
    num++;
    p = p->prox;
  } while(p != l);
}


int main (void){
  while(1){
    printf("Testando questao 4...\n");

    TLC *l = NULL;
    char nome[31];

    scanf(" %30[^\n]", nome);
    while(strcmp(nome, "FIM")){
      l = insere(l, nome);
      scanf(" %30[^\n]", nome);
    }
    imprime(l);

    int passo, resp;
    printf("passo... ");
    scanf("%d", &passo);
    resp = jp(l, passo);
    printf("%d\n", resp);
    libera(l);

    int parada;
    printf("Deseja parar? Digite 0\n");
    scanf("%d", &parada);
    if(!parada) return 0;
  }  
}

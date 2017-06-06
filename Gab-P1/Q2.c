//
// Q2
//
#include "lista.h"

void misc(TLSE *l, int x){
  if((!l) || (x <= 0)) return;

  TLSE *p = l;
  while(p){
    if(p->info == x){
      TLSE *q = p->prox;
      int i;
      for(i = x; i >= 1; i--) p->prox = inserel(p->prox, i);
      p->prox = inserel(p->prox, x);
      for(i = x; i >= 2; i--) p->prox = inserel(p->prox, i);
      p->info = 1;
      p = q;
    }
    else p = p->prox;
  }
}


int main(void){
  while(1){
    TLSE *l = NULL;
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      l = inserel(l, n);
    }
    imprimel(l);
    printf("\n");

    printf("n ... ");
    scanf("%d", &n);
    misc(l, n);
    imprimel(l);
    printf("\n");

    int parada;
    printf("Deseja parar? Digite 0\n");
    scanf("%d", &parada);
    if(!parada) return 0;
  }
}

//
// Q3
//
#include "pilha-lista.h"

TPilha *radx(TPilha *p, int x){
  TPilha *resp = inicializa_p(), *aux_resp = inicializa_p();
  int y;
  while(!vazia_p(p)) push(aux_resp, pop(p));

  while(!vazia_p(aux_resp)){
    int y = pop(aux_resp);
    push(resp, y);
    push(p, y);
  }

  while(!vazia_p(resp)){
    y = pop(resp);
    if(x == y){
      if(!vazia_p(aux_resp)) pop(aux_resp);
      if(!vazia_p(resp)) pop(resp);
    }
    push(aux_resp, y);
  }

  while(!vazia_p(aux_resp)) push(resp, pop(aux_resp));
  libera_p(aux_resp);
  return resp;
}


int main(void){
  while(1){
    TPilha *p = inicializa_p();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      push(p, n);
    }
    imprime_p(p);
    printf("\n");

    printf("n ... ");
    scanf("%d", &n);
    TPilha *resp = radx(p, n);

    printf("p:\n");
    imprime_p(p);
    printf("\n");
    libera_p(p);

    printf("resp:\n");
    imprime_p(resp);
    printf("\n");
    libera_p(resp);

    int parada;
    printf("Deseja parar? Digite 0\n");
    scanf("%d", &parada);
    if(!parada) return 0;
  }
}

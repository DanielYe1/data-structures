//
// Q1
//
#include "lista2.h"

TLista2 *pega_impar(TLista2 *p) {
    if (!p)
        return p;

    TLista2 *t = p;
    while (t) {
        if (t->info % 2 == 1) {
            return t;
        }
        t = t->prox;
    }
    return t;
}

void troca_info(TLista2 *a, TLista2 *b) {
    int x = a->info;
    a->info = b->info;
    b->info = x;
}

void i_p(TLista2 *p) {


    while (p) {
        if (p->info % 2 == 1) {
            p = p->prox;
        } else {
            TLista2 *temp = pega_impar(p);
            if (!temp)return;
            if (p->prox == temp) {
                troca_info(p, p->prox);
            } else {
                if (temp->prox)
                    temp->prox->ant = temp->ant;

                temp->ant->prox = temp->prox;
                temp->prox = p->prox;
                p->prox->ant = temp;
                p->prox = temp;
                temp->ant = p;

                troca_info(temp, p);

                p = p->prox;
            }


        }
    }

    /*
    if (!l) return;

    TLista2 *prim_par = l;
    while ((prim_par) && (prim_par->info % 2)) prim_par = prim_par->prox;
    if (!prim_par) return;

    TLista2 *prox_impar = prim_par->prox;
    while (prox_impar) {
        while ((prox_impar) && ((prox_impar->info % 2) == 0)) prox_impar = prox_impar->prox;
        if (!prox_impar) return;

        TLista2 *q = prox_impar;
        int n = q->info;
        while (q != prim_par) {
            q->info = q->ant->info;
            q = q->ant;
        }
        q->info = n;
        prim_par = prim_par->prox;
        prox_impar = prox_impar->prox;
    }
     */
}


int main(void) {
    while (1) {
        TLista2 *l = NULL;
        int n;
        while (1) {
            scanf("%d", &n);
            if (n < 0) break;
            l = insere(l, n);
        }
        imprime(l);
        printf("\n");
        i_p(l);
        imprime(l);
        printf("\n");

        int parada;
        printf("Deseja parar? Digite 0\n");
        scanf("%d", &parada);
        if (!parada) return 0;
    }
}

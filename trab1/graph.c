#include <stdio.h>
#include <stdlib.h>

typedef struct viz {
    int id_viz;
    int custo;
    struct viz *prox_viz;
} TViz;

typedef struct no {
    int id_no;
    TViz *prim_viz;
    struct no *prox_no;
} TNO;

typedef struct grafo {
    TNO *prim;
} TG;

TG *cria(void) {
    TG *g = (TG *) malloc(sizeof(TG));
    g->prim = NULL;
    return g;
}

TNO *busca_no(TG *g, int n) {
    TNO *p = g->prim;
    while ((p) && (p->id_no != n)) {
        p = p->prox_no;
    }
    return p;
}

void insere_no(TG *g, int no) {
    TNO *p = busca_no(g, no);
    if (p)return;
    p = (TNO *) malloc((sizeof(TNO)));
    p->id_no = no;
    p->prim_viz = NULL;
    p->prox_no = g->prim;
    g->prim = p;
}

TViz *busca_aresta(TG *g, int no1, int no2) {
    TNO *viz1 = busca_no(g, no1);
    if (!viz1)return NULL;
    TNO *viz2 = busca_no(g, no2);
    if (!viz2)return NULL;

    TViz *p = viz1->prim_viz;
    while ((p) && (p->id_viz != no2)) {
        p = p->prox_viz;
    }
    return p;
}

void insere_aresta(TG *g, int id1, int id2, int custo) {
    TNO *p1 = busca_no(g, id1);
    if (!p1)return;
    TNO *p2 = busca_no(g, id2);
    if (!p2)return;
    TViz *v = busca_aresta(g, id1, id2);
    if (v) {
        v->custo = custo;
        return;
    }
    v = (TViz *) malloc(sizeof(TViz));
    v->id_viz = id2;
    v->custo = custo;
    v->prox_viz = p1->prim_viz;
    p1->prim_viz = v;
}


void imprime(TG *g) {
    TNO *p = g->prim;
    while (p) {
        printf("%d:\n", p->id_no);
        TViz *v = p->prim_viz;
        while (v) {
            printf("viz: %d \t  custo:%d\n", v->id_viz, v->custo);
            v = v->prox_viz;
        }
        p = p->prox_no;
    }
}


void retira_aresta(TG *g, int id1, int id2) {
    TNO *p1 = busca_no(g, id1);
    if (!p1)return;
    TNO *p2 = busca_no(g, id2);
    if (!p2)return;

    TViz *v = p1->prim_viz, *ant = NULL;
    while ((v) && (v->id_viz != id2)) {
        ant = v;
        v = v->prox_viz;
    }
    if (!v)return;;
    if (!ant)
        p1->prim_viz = v->prox_viz;
    else
        ant->prox_viz = v->prox_viz;

    free(v);
}

void retira_no(TG *g, int id) {
    TNO *p = g->prim, *ant = NULL;

    while ((p) && p->id_no != id) {
        ant = p;
        p = p->prox_no;
    }

    if (!p) return;

    TViz *v = p->prim_viz;
    while (v) {
        retira_aresta(g, id, v->id_viz);
        v = p->prim_viz;
    }

    if (!ant) {
        g->prim = p->prox_no;
    } else {
        ant->prox_no = p->prox_no;
    }
    free(p);

}


void libera(TG *g){
    TNO *p = g->prim;
    while(p){
        TViz *v = p->prim_viz;
        while (v){
            TViz *t = v;
            v=v->prox_viz;
            free(t);
        }

        TNO *q=p;
        p=p->prox_no;
        free(q);
    }
    free(g);
}





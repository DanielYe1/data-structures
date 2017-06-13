#include <stdio.h>
#include <stdlib.h>
#include "graph.c"

int checkOrientation(int *values, int total_nodes);

static int visit[1000] = {0};

static void reachR(TG *G, int check) {
    visit[check] = 1;
    TNO *p = G->prim;
    while (p->id_no!=check) {
        p = p->prox_no;
    }
    TViz *viz = p->prim_viz;
    while(viz){
	  	if (visit[viz->id_viz] == 0) {
    	    reachR(G, viz->id_viz);
    	}
        viz=viz->prox_viz;
    }

}

int graphBFS(TG *G, int from, int searched) {
    for (int i = 0; i < 1000; ++i) {
        visit[i] = 0;
    }
    reachR(G, from);
    if (visit[searched] == 0) {
        printf("nao achou");
        return 0;
    } else {
        printf("achou");
        return 1;
    }
}

int main() {
    FILE *arq = fopen("trab1/arquivo.txt", "r");
    if (!arq) {
        exit(1);
    }

    // lendo total de nós
    int total_nodes;
    fscanf(arq, "%d", &total_nodes);
    printf("%d\n", total_nodes);


    TG *graph = cria();
    // inserindo nós
    for (int i = 0; i < total_nodes; ++i) {
        insere_no(graph, i + 1);
    }

    // inserindo arestas

    int *aux = malloc(sizeof(int) * total_nodes);
    int from, to;
    while (fscanf(arq, "%d %d", &from, &to) != EOF) {
        aux[from - 1] += to;
        aux[to - 1] -= from;
        insere_aresta(graph, from, to, 1);
        printf("%d %d\n", from, to);
    }

    int oriented = checkOrientation(aux, total_nodes);

    graphBFS(graph,1,5);

    fclose(arq);


    free(aux);

    return 0;
}

int checkOrientation(int *values, int total_nodes) {
    int oriented = 1;
    for (int j = 0; j < total_nodes; j++) {
        if (values[j]) {
            oriented = 0;
            break;
        }
    }
    if (oriented) {
        printf("orientado\n");
    } else {
        printf("nao orientado\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "graph.c"


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
    for (int i = total_nodes-1; i >= 0; i--) {
        insere_no(graph, i);
    }

    // inserindo arestas

    int *aux = malloc(sizeof(int) * total_nodes);
    int from, to;
    while (fscanf(arq, "%d %d", &from, &to) != EOF) {
        aux[from-1] += to;
        aux[to-1] -= from;
        insere_aresta(graph, from-1, to-1, 1);
        printf("%d %d\n", from, to);
    }

    int sc[1000];

    int oriented = checkOrientation(aux, total_nodes);
    int connected = graphStillConnected(graph, total_nodes);

    if (oriented) {
        show_strong_components(graph,sc,total_nodes);
    } else {
        if (connected) {
            printBridges(graph, total_nodes);
            printArticulations(graph, total_nodes);
        } else {
            printClusters(graph, total_nodes);
        }
    }
    fclose(arq);
    free(aux);

    return 0;
}

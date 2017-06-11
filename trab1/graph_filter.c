#include <stdio.h>
#include <stdlib.h>
#include "graph.c"

int main() {
    FILE *arq = fopen("trab1/arquivo.txt", "r");
    if (!arq) {
        exit(1);
    }

    int total_nodes;
    fscanf(arq, "%d", &total_nodes);
    printf("%d\n", total_nodes);

    TG *graph = cria();
    // inserindo nós
    for (int i = 0; i < total_nodes; ++i) {
        insere_no(graph, i + 1);
    }

    imprime(graph);


    int from, to;
    while (fscanf(arq, "%d %d", &from, &to) != EOF) {
        insere_aresta(graph, from, to, 1);
        printf("%d %d\n", from, to);
    }

    imprime(graph);

    fclose(arq);
    return 0;
}
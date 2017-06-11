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
    for (int i = 0; i < total_nodes; ++i) {
        insere_no(graph, i + 1);
    }

    // inserindo arestas

    int *aux = malloc(sizeof(int)*total_nodes);
    int from, to;
    while (fscanf(arq, "%d %d", &from, &to) != EOF) {
        aux[from-1]+=to;
        aux[to-1]-=from;
        insere_aresta(graph, from, to, 1);
        printf("%d %d\n", from, to);
    }

    for (int k = 0; k < total_nodes; k++) {
        printf("%d ",aux[k]);
    }

    int oriented=1;
    for (int j = 0; j < total_nodes; j++) {
        if(aux[j]){
            oriented=0;
            break;
        }
    }
    if(oriented){
        printf("aux");
    }else{
        printf("nao aux");
    }
    fclose(arq);


    free(aux);

    return 0;
}
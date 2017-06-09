#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq = fopen("trab1/arquivo.txt", "r");
    if (!arq) {
        exit(1);
    }

    int total_nodes;
    fscanf(arq, "%d", &total_nodes);
    printf("%d\n", total_nodes);

    int from, to;
    while (fscanf(arq, "%d %d", &from, &to) != EOF) {
        printf("%d %d\n", from, to);
    }

    fclose(arq);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int grau;
    scanf("%d", &grau);
    int *polinomio = malloc((grau + 1) * sizeof(int));
    for (int i = 0; i < grau + 1; ++i) {
        scanf("%d", &polinomio[i]);
    }

    printf("0 ");
    for (int j = 0; j < grau + 1; ++j) {
        printf("%d ", polinomio[j] / (j + 1));
    }
    printf("\n");
    for (int k = 1; k < grau + 1; ++k) {
        printf("%d ", polinomio[k] * k);
    }

    free(polinomio);

    return 0;
}
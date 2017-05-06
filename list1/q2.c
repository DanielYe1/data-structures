#include <stdio.h>

int main() {
    int x, y, value;
    scanf("%d %d", &x, &y);
    while(x >0 && y >0) {

        for (int i = x; i < y; ++i) {
            value = 1;
            for (int j = 2; j < i; ++j) {
                if (i % j == 0) {
                    value = 0;
                    break;
                }
            }
            if (value) printf("%d", i);
        }
        scanf("%d %d", &x, &y);
    }
    return 0;
}
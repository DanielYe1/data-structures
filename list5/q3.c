#include <stdio.h>
#include "list.c"


int main() {
    TLSE *l = create();
    int i;
    for (i = 0; i < 5; ++i) {
        l = ins_ini(l, i);
    }
    print(l);
    l = desloca(l, 1);
    print(l);
    l = desloca(l, 1);
    print(l);
    clean(l);
    return 0;
}
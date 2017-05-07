#include <stdio.h>
#include "list.c"

int main() {

    TLSE *l = create();
    int i;
    for (i = 0; i < 5; ++i) {
        l = ins_ini(l, i);
    }
    print(l);
    invert_void(l);
    print(l);
    clean(l);
    return 0;
}
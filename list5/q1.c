#include <stdio.h>
#include "list.c"

int main(){

    TLSE *l = create();
    ins_ini(l,5);
    printf("%d",l->info);
	return 0;
}   
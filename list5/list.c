#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int info;
	struct lista *prox;
}TLSE;

TLSE *create(){
	return NULL;
}

TLSE *ins_ini(TLSE *l,int value){
	TLSE *first = (TLSE *) malloc (sizeof(TLSE));
	first -> prox = l;
	first -> info = value;
	return first;
}

TLSE *ins_final(TLSE *l,int value){
	if(!l)
		return ins_ini(l,value);

	TLSE *p = l;
	while(p->prox!=NULL){
		p = p -> prox;
	}
    p->prox = ins_ini(NULL,value);
    return l;
}
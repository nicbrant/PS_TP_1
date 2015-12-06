#include<stdio.h>
#include<stdlib.h>
#include"listaPalestra.h"

void desalocaListaPalestras(ArmazenaPalestra *lista) {
return;
	ArmazenaPalestra *q = lista;
	ArmazenaPalestra *t = q->prox;
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
}

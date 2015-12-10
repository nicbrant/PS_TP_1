#include<stdio.h>
#include<stdlib.h>
#include"leituraPalestrante.h"

void desalocaListaPalestrantes(ArmazenaDispo *lista) {
return;
	ArmazenaDispo *q = lista;
	ArmazenaDispo *t = q->prox;
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
}

int ListaPalestrantesVazia (ArmazenaDispo *lista) {
	return (lista == NULL);
}

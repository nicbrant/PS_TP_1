#include<stdio.h>
#include<stdlib.h>
#include"leituraPalestrante.h"

void desalocaListaPalestrantes(ArmazenaDispo *lista) {
return;
	/* Veriifca se a lista é vazia */
	if (lista == NULL) {
		printf ("Lista vazia\n");
		return;
	}
	ArmazenaDispo *q = lista;
	ArmazenaDispo *t = q->prox;
	/* Arrasto = 1 */
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
	/* Veriifca se a lista é não vazia */
	if (lista != NULL) {
		printf ("Lista nao vazia\n");
		return;
	}
}

/* Verifica se a lista é vazia */
int ListaPalestrantesVazia (ArmazenaDispo *lista) {
	return (lista == NULL);
}

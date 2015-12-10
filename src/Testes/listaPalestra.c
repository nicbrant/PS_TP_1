#include<stdio.h>
#include<stdlib.h>
#include"listaPalestra.h"

void desalocaListaPalestras(ArmazenaPalestra *lista) {
return;
	/* Verifica se a lista é vazia */
	if (lista == NULL) {
		printf ("Lista vazia\n");
		return;
	}
	ArmazenaPalestra *q = lista;
	ArmazenaPalestra *t = q->prox;
	/* Arrasto = 1 */
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
	/* Verifica se a lista é não vazia */
	if (lista != NULL) {
		printf ("Lista nao vazia\n");
		return;
	}
}

/* Verifica se a lista é vazia */
int ListaPalestrasVazia (ArmazenaPalestra *lista) {
	return (lista == NULL);
}

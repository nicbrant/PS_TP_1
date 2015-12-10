#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"leituraPalestrante.h"

/* Armazena os dados do arquivo 'palestrantes.txt'
* numa lista do tipo 'ArmazenaDispo'
*/

ArmazenaDispo* leArquivo1(FILE *arquivo) {
	char palavra[1000];
	ArmazenaDispo *atual = (ArmazenaDispo*) malloc(sizeof(ArmazenaDispo));
	ArmazenaDispo *prim = NULL;

	/* Verifica se o arquivo passado é nulo */
	if (arquivo == NULL) {
		printf ("Nenhum arquivo foi passado\n");
		return NULL;
	}
	/* Verifica se a variável atual é alocada */
	if (atual == NULL) {
		printf ("Erro ao alocar memoria\n");
		return NULL;
	}
	prim = atual;

	/* Arrasto = 2 */
	while (fscanf(arquivo, "%s", palavra) >= 1) {
		if (!strcmp(palavra, "Nome:")) {
			fscanf(arquivo, "%[^\n]", atual->nomePalestrante);
		}
		else if (!strcmp(palavra, "Disponibilidade:")) {
			fscanf(arquivo, "%[^\n]", atual->dispo);
			atual->prox = (ArmazenaDispo*)malloc(sizeof(ArmazenaDispo));
			atual = atual->prox;
			if (atual == NULL)
				exit(2016);
		}
	}
	/* Verifica se o arquivo passado é nulo */
	if (arquivo == NULL) {
		printf ("Nenhum arquivo foi passado\n");
		return NULL;
	}

	return prim;
}

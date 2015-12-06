#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"listas.h"
/* Armazena os dados do arquivo 'palestrantes.txt'
* numa lista do tipo 'ArmazenaDispo'
*/

ArmazenaDispo leArquivo1(FILE *arquivo) {
	char palavra[1000];
	ArmazenaDispo *atual = (ArmazenaDispo*) malloc(sizeof(ArmazenaDispo));
	ArmazenaDispo *prim;
	if (atual == NULL) {
		exit(2015);
	}
	prim = atual;
	while (fscanf(arquivo, "%s", palavra) != EOF) {
		if (!strcmp(palavra, "Nome:")) {
			fscanf(arquivo, "%[^/n]", atual->nomePalestrante);
		}
		else if (!strcmp(palavra, "Disponibilidade:")) {
			fscanf(arquivo, "%[^/n]", atual->dispo);
			atual = atual->prox;
			atual = (ArmazenaDispo*)malloc(sizeof(ArmazenaDispo));
			if (atual == NULL)
				exit(2016);
		}
	}
	return prim;
}

/* Armazena os dados do arquivo 'palestras.txt'
* numa lista do tipo 'ArmazenaPalestra'
*/
ArmazenaPalestra leArquivo2(FILE *arquivo) {
	char palavra[1000];
	ArmazenaPalestra *atual = (ArmazenaPalestra*)malloc(sizeof(ArmazenaPalestra));
	ArmazenaPalestra *prim;
	if (atual == NULL) {
		exit(2017);
	}
	prim = atual;
	while (fscanf(arquivo, "%s", palavra) != EOF) {
		if (!strcmp(palavra, "Nome:")) {
			fscanf(arquivo, "%[^/n]", atual->nomePalestra);
		}
		else if (!strcmp(palavra, "Palestrante:")) {
			fscanf(arquivo, "%[^/n]", atual->nomePessoa);
		}
		else if (!strcmp(palavra, "Tema:")) {
			fscanf(arquivo, "%[^/n]", atual->tema);
		}
		else if (!strcmp(palavra, "Local:")) {
			fscanf(arquivo, "%[^/n]", atual->local);
		}
		else if (!strcmp(palavra, "Duracao:")) {
			fscanf(arquivo, "%[^/n]", atual->duracao);
			atual = atual->prox;
			atual = (ArmazenaPalestra*)malloc(sizeof(ArmazenaPalestra));
			if (atual == NULL)
				exit(2018);
		}
	}
	return prim;
}
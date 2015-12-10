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
	if (atual == NULL) {
		exit(2015);
	}
	prim = atual;
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
		}else{
			printf("Arquivo \"palestrantes.txt\" esta com os dados de forma errada.\nFechando o programa.\n");
			fclose(arquivo);
			exit(1);
		}
	}
	return prim;
}

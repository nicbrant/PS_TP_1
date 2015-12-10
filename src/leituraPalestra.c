#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"listaPalestra.h"
#include"listaLocal.h"

/* Armazena os dados do arquivo 'palestras.txt'
* numa lista do tipo 'ArmazenaPalestra'
*/
ArmazenaPalestra* leArquivo2(FILE *arquivo) {
	char palavra[1000];
	ArmazenaPalestra *atual = (ArmazenaPalestra*)malloc(sizeof(ArmazenaPalestra));
	ArmazenaPalestra *prim = NULL;
	if (atual == NULL) {
		exit(2017);
	}
	prim = atual;
	while (fscanf(arquivo, "%s", palavra) != EOF) {
		if (!strcmp(palavra, "Nome:")) {
			fscanf(arquivo, "%[^\n]", atual->nomePalestra);
		}
		else if (!strcmp(palavra, "Palestrante:")) {
			fscanf(arquivo, "%[^\n]", atual->nomePessoa);
		}
		else if (!strcmp(palavra, "Tema:")) {
			fscanf(arquivo, "%[^\n]", atual->tema);
		}
		else if (!strcmp(palavra, "Local:")) {
			fscanf(arquivo, "%[^\n]", atual->local);
		}
		else if (!strcmp(palavra, "Duracao:")) {
			fscanf(arquivo, "%[^\n]", atual->duracao);
			atual->prox = (ArmazenaPalestra*)malloc(sizeof(ArmazenaPalestra));
			atual = atual->prox;
			if (atual == NULL)
				exit(2018);
		}else{
			printf("Arquivo \"palestras.txt\" esta com os dados de forma errada.\nFechando o programa.\n");
			fclose(arquivo);
			exit(1);
		}
	}
	return prim;
}

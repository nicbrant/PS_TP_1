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

	/* Verifica se o arquivo passado é nulo */
	if (arquivo == NULL) {
		printf ("Nenhum arquivo foi passado\n");
		return NULL;
	}
	/* Verifica se a variável atual foi alocada */
	if (atual == NULL) {
		printf ("Erro na alocacao\n");
		return NULL;
	}
	prim = atual;

	/* Arrasto = 4 */
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
		}
	}

	/* Verifica se o arquivo passado é nulo */
	if (arquivo == NULL) {
		printf ("Nenhum arquivo foi passado\n");
		return NULL;
	}

	return prim;
}

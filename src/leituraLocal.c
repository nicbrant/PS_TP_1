#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"listaLocal.h"

LocalStr* leArquivoLocal(FILE *arquivo)
 {
	/* Verifica se o ponteiro do arquivo é nulo */
	if (arquivo == NULL) {
		printf ("Erro ao abrir o arquivo\n");
		return NULL;
	}

	char palavra[1000];
	LocalStr *atual = (LocalStr*)malloc(sizeof(LocalStr));
	LocalStr *prim = NULL;

	/* Verifica se a variável foi alocada */
	if (atual == NULL) 
	{
		printf ("Erro ao alocar memória\n");
		return NULL;
	}
	prim = atual;

	/* Arrasto = 4 */
	while (fscanf(arquivo, "%s", palavra) >= 1)
	{
		if (!strcmp(palavra, "Nome:"))
			fscanf(arquivo, "%[^\n]", atual->sala);

		else if (!strcmp(palavra, "Endereco:"))
			fscanf(arquivo, "%[^\n]", atual->endereco);

		else if (!strcmp(palavra, "Disponibilidade:"))
		{
			fscanf(arquivo, "%[^\n]", atual->dispo);

			if (feof(arquivo))
				break;		
			atual->prox = (LocalStr*)malloc(sizeof(LocalStr));
			atual = atual->prox;
			if (atual == NULL)
				exit(1);
		}
	}

	/* Verifica se o ponteiro do arquivo é nulo durante a execução */
	if (arquivo == NULL) {
		printf ("Erro ao abrir o arquivo\n");
		return NULL;
	}
	return prim;
}

/* Verifica se lista é vazia */
int ListaLocalVazia (LocalStr* lista) {
	return (lista == NULL);
}

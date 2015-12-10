#include<stdio.h>
#include<stdlib.h>
#include"listaLocal.h"

LocalStr* leArquivoLocal(FILE *arquivo)
 {
	char palavra[1000];
	LocalStr *atual = (LocalStr*)malloc(sizeof(LocalStr));
	LocalStr *prim = NULL;
	if (atual == NULL)
	{
		exit(1);
	}
	prim = atual;
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
		}else{
			printf("Arquivo \"localidade.txt\" esta com os dados de forma errada.\nFechando o programa.\n");
			fclose(arquivo);
			exit(1);
		}
	}
	return prim;
}

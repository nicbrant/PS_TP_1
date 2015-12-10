#ifndef _LISTAPALESTRA_H
#define _LISTAPALESTRA_H

/**
*Estrutura para guardar dados do aquivo 'palestras.txt'
*/
struct armazenaPalestra /*Vamos nos referir a lista dela como "arquivo2"*/
{
	char nomePessoa[50], nomePalestra[50], tema[50], local[50], duracao[50];
	struct armazenaPalestra *prox;
};
typedef struct armazenaPalestra ArmazenaPalestra;

/**
*Desaloca a lista de palestras
*@param lista ponteiro para ArmazenaPalestra que sera desalocado
*/
void desalocaListaPalestras(ArmazenaPalestra *lista);
int ListaPalestrasVazia (ArmazenaPalestra *lista);

#endif

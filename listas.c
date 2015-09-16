#include<stdio.h>
#include<stdlib.h>

/*Estrutura para guardar dados do arquivo 'palestrantes.txt'*/
struct armazenaDispo /*Vamos nos referir a lista dela como "arquivo1"*/
{
	char nomePalestrante[100];
	char dispo[1000];
	struct armazenaDispo *prox;
};
typedef struct armazenaDispo ArmazenaDispo;

/*Estrutura para guardar dados do aquivo 'palestras.txt'*/
struct armazenaPalestra /*Vamos nos referir a lista dela como "arquivo2"*/
{
	char nomePessoa[50], nomePalestra[50], tema[50], local[50];
	int duracao;
	struct armazenaPalestra *prox;
};
typedef struct armazenaPalestra ArmazenaPalestra;

/*Nó da lista para armazenar arquivo1*/
struct listaParaArquivo1
{
	ArmazenaDispo *info;
	struct listaParaArquivo1 *prox;
};
typedef listaParaArquivo1 ListaParaArquivo1;

/*Nó da lista para armazenar arquivo2*/
struct listaParaArquivo2
{
	ArmazenaPalestra *info;
	struct listaParaArquivo2 *prox;
};
typedef listaParaArquivo2 ListaParaArquivo2;

ListaParaArquivo1 CriaLista1() {
	ListaParaArquivo1 *lista = (*ListaParaArquivo1) malloc(sizeof(ListaParaArquivo1));
	return lista;
}

ListaParaArquivo2 CriaLista2() {
	istaParaArquivo2 *lista = (*ListaParaArquivo2) malloc(sizeof(ListaParaArquivo2));
	return lista;
}

void VerificaCriacao(ListaParaArquivo1* lista1, ListaParaArquivo2 *lista2) {
	if ((lista1 == NULL) && (lista2 == NULL)) {
		exit(2005);
	}
	else if (lista1 == NULL) {
		free(lista2);
		exit(2006);
	}
	else if (lista2 == NULL) {
		free(lista1);
		exit(2007);
	}
}

void DesalocaLista1(ListaParaArquivo1 *lista) {
	ListaParaArquivo1 *q = lista->info;
	ListaParaArquivo1 *t;
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
}

void DesalocaLista2(ListaParaArquivo2 *lista) {
	ListaParaArquivo2 *q = lista->info;
	ListaParaArquivo2 *t;
	while (q) {
		t = q->prox;
		free(q);
		q = t;
	}
	free(lista);
}

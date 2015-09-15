#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"leitura.h"

ListaCalendario *criaListaTratada(ArmazenaDispo *ant, ArmazenaPalestra  *listaArquivo2)
{
	ListaCalendario *nova = NULL;
	ArmazenaDispo *temp = ant;
	char dispoTemp;
	int i;

	/*Copia dados da lista anterior para a nova com os dados organizados */
	for (temp = ant; temp != NULL; temp = temp->prox)
	{
		dispoTemp = temp->dispo;
		/*Copia a data e hora para os campos numéricos da nova lista. Observe a conversão de char para int. */
		for (i=0; strlen(dispoTemp) <= i; i+=30)
		{
			ListaCalendario *endTemp = nova;
			nova = (ListaCalendario*) malloc(sizeof(ListaCalendario));

			/*Armazena tema, local e duração (em segundos) */
			strcpy(nova->temaPalestra, listaArquivo2->tema);
			strcpy(nova->local, listaArquivo2->local);
			nova->duracao = listaArquivo2->duracao;

			/*Transfere nome do palestrante*/
			strcpy(nova->nomePalestrante, temp->nomePalestrante);	
			/*Alocação da data*/
			nova->disponibilidade->dia = (dispoTemp[i+5]-48)*10 + (dispoTemp[i+6]-48);
			nova->disponibilidade->mes = (dispoTemp[i+8]-48)*10 + (dispoTemp[i+9]-48);
			nova->disponibilidade->ano = (dispoTemp[i+11]-48)*1000 + (dispoTemp[i+12]-48)*100 + (dispoTemp[i+13]-48)*10 + (dispoTemp[i+14]-48);
			/*Alocação da hora */
			nova->horaInicio = (dispoTemp[i+17]-48)*60 + (dispoTemp[i+18]-48);
			nova->minutoInicio = (dispoTemp[i+17]-48)*60 + (dispoTemp[i+18]-48);
			nova->horaFim = (dispoTemp[i+20]-48)*60 + (dispoTemp[i+21]-48);
			nova->minutoFim = (dispoTemp[i+23]-48)*60 + (dispoTemp[i+24]-48);

			/*Faz novo endereço apontar para o anterior*/
			nova->prox = endTemp;
		}
	}
	liberaListaArquivo1(ant);
	liberaListaArquivo2(listaArquivo2);


	return nova;
}

void liberaListaArquivo1(ArmazenDispo *lista)
{
	/*libera a lista que armazena palestras.txt*/
}
void liberaListaArquivo2(ArmazenaPalestra *lista)
{
	/*libera a lista que armazena palestrantes.txt*/
}
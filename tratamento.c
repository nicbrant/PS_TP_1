#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tratamento.h"
#include"listaLocal.h"
#include"listaPalestra.h"
#include"leituraPalestrante.h"

/* Cria um calendário com os dados dos palestrantes e dos horários de palestras. */
/* Une os dados de listaPalestrante e listaPalestras em um único conjunto, o calendário. */

ListaCalendario *criaListaTratada(ArmazenaDispo *listaArquivo1, ArmazenaPalestra  *listaArquivo2)
{
	ListaCalendario *nova, *prim = NULL;
	ArmazenaDispo *tempDispo = listaArquivo1;
	ArmazenaPalestra *tempPalestra = listaArquivo2;
	char dispoTemp[1000];
	int i;
	
	for (tempDispo = listaArquivo1, tempPalestra = listaArquivo2 ; tempDispo != NULL ; tempDispo = tempDispo->prox, tempPalestra = tempPalestra->prox)
	{
		strcpy(dispoTemp, tempDispo->dispo);
		i = 1;
		while(i < strlen(dispoTemp))
		{
			nova = (ListaCalendario *) malloc(sizeof(ListaCalendario));

			// Atribui dia da semana de forma numérica
			nova->diaSemana = atribuiSemana(dispoTemp+i);

			/*Adiciona informações do palestrante*/
			strcpy(nova->nomePalestrante, tempPalestra->nomePessoa);
			strcpy(nova->nomePalestra, tempPalestra->nomePalestra);
			strcpy(nova->tema, tempPalestra->tema);
			strcpy(nova->lugar, tempPalestra->local);
			strcpy(nova->duracao, tempPalestra->duracao);

			if (dispoTemp[i+7] == '/')
			{
				/*Altera dia para numerico */
				nova->disponibilidade.dia = (dispoTemp[i+5]-48)*10+(dispoTemp[i+6]-48);
				nova->disponibilidade.mes = (dispoTemp[i+8]-48)*10+(dispoTemp[i+9]-48);
				nova->disponibilidade.ano = (dispoTemp[i+11]-48)*1000+(dispoTemp[i+12]-48)*100+(dispoTemp[i+13]-48)*10+(dispoTemp[i+14]-48);
			
				/*Horas de inicio e fim para numéricos */
				nova->horaInicio = (dispoTemp[i+17]-48)*10+(dispoTemp[i+18]-48);
				nova->minutoInicio = (dispoTemp[i+20]-48)*10+(dispoTemp[i+21]-48);
				nova->horaFim = (dispoTemp[i+23]-48)*10+(dispoTemp[i+24]-48);
				nova->minutoFim = (dispoTemp[i+26]-48)*10+(dispoTemp[i+27]-48);

				i += 30;
			}
			else
			{

				/*Altera dia para numerico */
				nova->disponibilidade.dia = 0;
				nova->disponibilidade.mes = 0;
				nova->disponibilidade.ano = 0;

				/*Horas de inicio e fim para numéricos */
				nova->horaInicio = (dispoTemp[i+5]-48)*10+(dispoTemp[i+6]-48);
				nova->minutoInicio = (dispoTemp[i+8]-48)*10+(dispoTemp[i+9]-48);
				nova->horaFim = (dispoTemp[i+11]-48)*10+(dispoTemp[i+12]-48);
				nova->minutoFim = (dispoTemp[i+14]-48)*10+(dispoTemp[i+15]-48);
			
				i += 18;
			}
			
			nova->prox = prim;
			prim = nova;
		}
	}

	return prim;

}

int atribuiSemana(char *dia)
{
	if (!strncmp(dia, "Dom", 3))
		return 1;
	else if (!strncmp(dia, "Seg", 3))
		return 2;
	else if (!strncmp(dia, "Ter", 3))
		return 3;
	else if (!strncmp(dia, "Qua", 3))
		return 4;
	else if (!strncmp(dia, "Qui", 3))
		return 5;
	else if (!strncmp(dia, "Sex", 3))
		return 6;
	else if (!strncmp(dia, "Sab", 3) || strncmp(dia, "Sáb", 3))
		return 7;
}

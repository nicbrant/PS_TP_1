#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaLocal.h"
#include"tratamento.h"
#include"tratamentoLocal.h"

/*Atribui dia da semana para disponibilidade */
int atribuiSemana2(char *dia)
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

/*Retorna lista encadeada com a localidade tratada*/
Localidade *converteLocalStrInt(LocalStr *localidadeStr)
{
	Localidade *nova = NULL, *prim = NULL;
	LocalStr *t = NULL;
	char dispoTemp[200];
	int i;

	/* Exemplo de disponibilidade: Qui, 03/09/2015, 07:00-09:30; Seg, 00/10/2015, 14:00-16:30 */

	for (t = localidadeStr; t != NULL; t = t->prox)
	{
		strcpy(dispoTemp, t->dispo);
		i = 1;
		
		while(i < strlen(dispoTemp))
		{
			nova = (Localidade *) malloc(sizeof(Localidade));

			nova->diaSemana = atribuiSemana2(dispoTemp+i);

			/*Adiciona informações do local que permanecerão como string */
			strcpy(nova->sala, t->sala);
			strcpy(nova->endereco, t->endereco);

			if (dispoTemp[i+7] == '/')
			{
				/*Altera dia para numerico */
				nova->dia = (dispoTemp[i+5]-48)*10+(dispoTemp[i+6]-48);
				nova->mes = (dispoTemp[i+8]-48)*10+(dispoTemp[i+9]-48);
				nova->ano = (dispoTemp[i+11]-48)*1000+(dispoTemp[i+12]-48)*100+(dispoTemp[i+13]-48)*10+(dispoTemp[i+14]-48);
			
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
				nova->dia = 0;
				nova->mes = 0;
				nova->ano = 0;

				/*Horas de inicio e fim para numéricos */
				nova->horaInicio = (dispoTemp[i+6]-48)*10+(dispoTemp[i+7]-48);
				nova->minutoInicio = (dispoTemp[i+9]-48)*10+(dispoTemp[i+10]-48);
				nova->horaFim = (dispoTemp[i+12]-48)*10+(dispoTemp[i+13]-48);
				nova->minutoFim = (dispoTemp[i+14]-48)*10+(dispoTemp[i+15]-48);
			
				i += 18;
			}

			nova->prox = prim;
			prim = nova;
		}
	}
	/* Libera a lista LocalStr em formato de string */
	t = NULL;
	while (localidadeStr != NULL)
	{
		t = localidadeStr->prox;
		free(localidadeStr);
		localidadeStr = t;
	}

	return prim;
}


/* Adiciona as localidades no calendário, da seguinte forma: se existe um local
que se encaixe nas especificações pedidas, o campo 'local' de ListaCalendario
irá apontar para o local */
ListaCalendario* alocaLocal(ListaCalendario *calendario, Localidade *lugar)
{
	ListaCalendario *calenTemp = NULL;
	Localidade *localTemp = NULL;

	for (calenTemp = calendario; calenTemp != NULL  ; calenTemp = calenTemp->prox)
	{
		calenTemp->local = NULL;
		for (localTemp = lugar; localTemp != NULL ; localTemp = localTemp->prox)
		{
			/*Verifica se o local pode ser usado */
			if (calenTemp->disponibilidade.dia == localTemp->dia
			&&  calenTemp->disponibilidade.mes == localTemp->mes
			&&  calenTemp->disponibilidade.ano == localTemp->ano
			&&  calenTemp->horaInicio >= localTemp->horaInicio
			&&  calenTemp->horaFim <= localTemp->horaFim
			&&  calenTemp->minutoInicio >= localTemp->minutoInicio
			&&  calenTemp->minutoFim <= localTemp->minutoFim)
			{
				calenTemp->local = localTemp;
				localTemp = localTemp->prox;
				calenTemp->existeLocal = 1;
			}
			
		}
		/*Verifica se houve local*/
		if (calenTemp->local == NULL)
			calenTemp->existeLocal = 0;
	}

	return calendario;
}

int locaisVazios(Localidade *local)
{
	return local == NULL;
}

int calendarioVazio(ListaCalendario *c)
{
	return c == NULL;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaLocal.h"
#include"tratamento.h"
#include"calendario.h"

/*Ordena a lista tratada em todos os aspectos usando apenas uma função*/
void ordenaListaTratada(ListaCalendario *c)
{
	ListaCalendario *temp, *temp2, *inicioSemZero = NULL;
	int qtdEventosDiaZero = 0;

	/* Coloca todos os eventos de data 0/0/0 no início da lista. */
	for (temp = c->prox, temp2 = c; temp->prox != NULL; temp = temp->prox)
	{
		if (temp->disponibilidade.dia == 0 && temp->disponibilidade.mes == 0 && temp->disponibilidade.ano == 0)
		{
			swapDadosLista(temp, temp2);
			qtdEventosDiaZero++;
			temp2 = temp2->prox;
		}

	}

	/*Faz com que 'iniciaSemZero' aponte para a posição da lista aonde os eventos 0/0/0 terminam. */
	inicioSemZero = c;
	while (qtdEventosDiaZero--)
		inicioSemZero = inicioSemZero->prox;

	/* Realiza a ordenação dos elementos do calendário a partir de 'iniciaSemZero' usando bubblesort. */
	for (temp = inicioSemZero; temp->prox != NULL; temp = temp->prox)
	{
		for (temp2 = inicioSemZero; temp2->prox != NULL; temp2 = temp2->prox)
		{
			/* Se um evento é antes, ele é alternado de acordo com o próximo */
			if (temp2->disponibilidade.ano > temp2->prox->disponibilidade.ano)
			{
				swapDadosLista(temp2, temp2->prox);
				continue;
			}
			else if (temp2->disponibilidade.ano == temp2->prox->disponibilidade.ano)
				if (temp2->disponibilidade.mes > temp2->prox->disponibilidade.mes)
				{
					swapDadosLista(temp2, temp2->prox);
					continue;
				}
				else if (temp2->disponibilidade.mes == temp2->prox->disponibilidade.mes)
					if (temp2->disponibilidade.dia > temp2->prox->disponibilidade.dia)
					{
						swapDadosLista(temp2, temp2->prox);
						continue;
					}
		}
	}
}

/* Alterna os dados em uma lista encadeada */
void swapDadosLista(ListaCalendario *l1, ListaCalendario *l2)
{
	ListaCalendario temp;
	
	copiaInfoLista(&temp, l1);
	copiaInfoLista(l1, l2);
	copiaInfoLista(l2, &temp);
}
	
/* Copia a informação de uma estrutura para outra */
void copiaInfoLista(ListaCalendario *dest, ListaCalendario *orig)
{
	
	strcpy(dest->nomePalestrante, orig->nomePalestrante);
	strcpy(dest->nomePalestra, orig->nomePalestra);
	strcpy(dest->tema, orig->tema);
	strcpy(dest->lugar, orig->lugar);
	strcpy(dest->duracao, orig->duracao);

	dest->disponibilidade.dia = orig->disponibilidade.dia;
	dest->disponibilidade.mes = orig->disponibilidade.mes;
	dest->disponibilidade.ano = orig->disponibilidade.ano;

	dest->horaInicio = orig->horaInicio;
	dest->minutoInicio = orig->minutoInicio;
	dest->horaFim = orig->horaFim;
	dest->minutoFim = orig->minutoFim;
}
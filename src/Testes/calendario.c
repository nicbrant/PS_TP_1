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

	/* Verifica se a lista para ser tratada não é nula */
	if (c == NULL) {
		printf ("Lista esta vazia!\n");
		return;
	}
	/* Coloca todos os eventos de data 0/0/0 no início da lista. Arrasto = 1 */
	for (temp = c->prox, temp2 = c; temp->prox != NULL; temp = temp->prox)
	{
		if (temp->disponibilidade.dia == 0 && temp->disponibilidade.mes == 0 && temp->disponibilidade.ano == 0)
		{
			swapDadosLista(temp, temp2);
			qtdEventosDiaZero++;
			temp2 = temp2->prox;
		}

	}

	/* Verifica se a lista está vazia durante a execução */
	if (c == NULL) {
		printf ("Lista esta vazia!\n");
		return;
	}

	/*Faz com que 'iniciaSemZero' aponte para a posição da lista aonde os eventos 0/0/0 terminam.
		Arrasto = 1 */
	inicioSemZero = c;

	/* Verifica se a lista está vazia durante a execução */
	if (inicioSemZero == NULL) {
		printf ("Lista esta vazia\n");
		return;
	}
	/* Arrasto = 1 */
	while (qtdEventosDiaZero--)
		inicioSemZero = inicioSemZero->prox;

	/* Realiza a ordenação dos elementos do calendário a partir de 'iniciaSemZero' usando bubblesort.
		Arrasto = 1 */
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

	/* Verifica se a lista 1 está vazia */
	if (l1 == NULL) {
		printf ("Lista 1 esta vazia!\n");
		return;
	}
	/* Verifica se a lista 2 está vazia */
	if (l2 == NULL) {
		printf ("Lista 2 esta vazia!\n");
		return;
	}
	copiaInfoLista(&temp, l1);
	copiaInfoLista(l1, l2);
	copiaInfoLista(l2, &temp);
}
	
/* Copia a informação de uma estrutura para outra */
void copiaInfoLista(ListaCalendario *dest, ListaCalendario *orig)
{
	
	/* Verifica se lista destino é nula */
	if (dest == NULL) {
		printf ("Lista destino esta vazia!\n");
		return;
	}
	/* Verifica se lista origem é nula */
	if (orig == NULL) {
		printf ("Lista origem esta vazia\n");
		return;
	}
	strcpy(dest->nomePalestrante, orig->nomePalestrante);
	strcpy(dest->nomePalestra, orig->nomePalestra);
	strcpy(dest->tema, orig->tema);
	strcpy(dest->lugar, orig->lugar);
	strcpy(dest->duracao, orig->duracao);

	/* Verifica se lista destino é nula durante a execução */
	if (dest == NULL) {
		printf ("Lista destino esta vazia!\n");
		return;
	}
	/* Verifica se lista origem é nula durante a execução */
	if (orig == NULL) {
		printf ("Lista origem esta vazia\n");
		return;
	}

	dest->disponibilidade.dia = orig->disponibilidade.dia;
	dest->disponibilidade.mes = orig->disponibilidade.mes;
	dest->disponibilidade.ano = orig->disponibilidade.ano;

	dest->horaInicio = orig->horaInicio;
	dest->minutoInicio = orig->minutoInicio;
	dest->horaFim = orig->horaFim;
	dest->minutoFim = orig->minutoFim;
}

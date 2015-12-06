#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"listaLocal.h"
#include"tratamento.h"
#include"calendario.h"

/*Ordena a lista tratada em todos os aspectos usando apenas uma função*/
void ordenaListaTratada(ListaCalendario *c)
{
	ListaCalendario *temp;
	for (temp = c; temp->prox != NULL; temp = temp->prox)
	{
		/* Se um evento é antes, ele é alternado de acordo com o próximo */
		if (temp->disponibilidade.dia >= temp->prox->disponibilidade.dia
		&&  temp->disponibilidade.mes >= temp->prox->disponibilidade.mes
		&&  temp->disponibilidade.ano >= temp->prox->disponibilidade.ano
		&&  temp->horaInicio >= temp->prox->horaInicio
		&&  temp->minutoInicio >= temp->prox->minutoInicio)
		{
			swapDadosLista(temp, temp->prox);
		}
	}
}

/* Alterna os dados em uma lista encadeada */
void swapDadosLista(ListaCalendario *l1, ListaCalendario *l2)
{
	ListaCalendario *temp;
	
	copiaInfoLista(temp, l1);
	copiaInfoLista(l1, l2);
	copiaInfoLista(l2, temp);
}
	
/* Copia a informação de uma estrutura para outra */
void copiaInfoLista(ListaCalendario *dest, ListaCalendario *orig)
{
	ListaCalendario *temp;
	
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
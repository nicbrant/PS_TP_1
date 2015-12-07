#ifndef _LISTALOCAL_H
#define _LISTALOCAL_H

struct localStr
{
	char sala[50], endereco[100], dispo[1000];
	struct localStr *prox;
};
typedef struct localStr LocalStr;

struct localidade
{
	char sala[50], endereco[100];
	int horaInicio, horaFim, dia, mes, ano, minutoInicio, minutoFim;
	int diaSemana;
	struct localidade *prox;
};
typedef struct localidade Localidade;


#endif
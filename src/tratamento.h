#ifndef _TRATAMENTO_H
#define _TRATAMENTO_H

#include"listaPalestra.h"
#include"leituraPalestrante.h"
#include "listaLocal.h"

/*    Estrutura para armazenar a disponibilidade de forma numérica.
 * Para armazenar os dados tratados, será criada uma lista do tipo
 * 'dataPalestra' dentro da estrutura 'ListaCalendario', para o caso 
 * de haver mais de uma disponibilidade
 */
struct disponibilidadeNum
{
	int dia, mes, ano;
};
typedef struct disponibilidadeNum DisponibilidadeNumerica;


/*	Estrutura que irá guardar os dados tratados, ou seja, onde
 * a disponibilidade será em números.
 */
struct listaCalendario
{
	char nomePalestrante[100], nomePalestra[100], tema[100], lugar[100], duracao[50];
	int horaInicio, horaFim, minutoInicio, minutoFim;
	int existeLocal; /*1 se ouver local, 0 caso contrário*/
	int diaSemana; /*1 a 7, sendo de domingo até sábado */
	DisponibilidadeNumerica disponibilidade;
	Localidade *local;
	struct listaCalendario *prox;
};
typedef struct listaCalendario ListaCalendario;


/*	Cria lista onde a disponibilidade passa a ser númerica ao invés
 * de uma string, facilitando a manipulação. Mais especificamente, uma
 * lista encadeada do tipo 'dataPalestra'
 * 	Após a criação da nova lista com disponibidade numérica, destruir
 * a lista anterior 'l', ou seja, a que ainda guarda a disponibilidade 
 * em forma de string.
 */

ListaCalendario *criaListaTratada(ArmazenaDispo *listaArquivo1, ArmazenaPalestra  *listaArquivo2);
int atribuiSemana(char *dia);

#endif

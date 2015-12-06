#ifndef _PERSISTENCIA_H
#define _PERSISTENCIA_H

#include "tratamento.h"

/* Enumeração para retornar o dia da semana em valor numérico */
enum dias_da_semana {DOM = 1, SEG, TER, QUA, QUI, SEX, SAB} semana;

/**
*Imprime os dados da lista do tipo 'listaCalendario' em um arquivo
*com a formatação necessária.
*@param calendario ponteiro para ListaCalendario sera usada como fonte para a criação do calendario
*@param arquivoSaida Ponteiro Para um arquivo sera usado como destino do calendario
*/
void imprimeCalendario(ListaCalendario *calendario, FILE *arquivoSaida);

/* Imprime no arquivo o mês e o ano passado como parâmetro */
void imprimeDataArquivo (FILE *arquivoSaida, int mes, int ano);

/**
*Algoritmo que descobre a quantidade de dias do mês, lembrando que
*fevereiro alterna entre 28 e 29, caso o ano seja não bissexto ou bissexto, respectivamente.
*@param mes inteiro sera usado para saber quantos dias tem o mes
*@param ano inteiro sera usado para saber quantos dias tem o mes naquele ano
*@return um inteiro
*/
int alternaMeses(int mes, int ano);

/* Função que a partir de uma data, retorna que dia da semana é */
int retornaDiaSemana(int mes, int dia, int ano);

#endif

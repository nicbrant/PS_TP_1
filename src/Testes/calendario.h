#ifndef _CALENDARIO_H
#define _CALENDARIO_H

#include"tratamento.h"

/*A intenção do calendario.c é de ordenar a lista, para que sua impressão possa ser direta.
Ela será ordenada por data mais próxima */

/**
*Ordena a lista em todos os aspectos
*@param c um ponteiro para uma lista calendario
*/
void ordenaListaTratada(ListaCalendario *c);


/**
*Ordena as datas por dia
*@param c um ponteiro para uma lista calendario
*/
void ordenaPorDia(ListaCalendario *c);
/**
*Ordena as datas por mes
*@param c um ponteiro para uma lista calendario
*/
void ordenaPorMes(ListaCalendario *c);
/**
*Ordena as datas por ano
*@param c um ponteiro para uma lista calendario
*/
void ordenaPorAno(ListaCalendario *c);
/**
*Ordena as horas por horas
*@param c um ponteiro para uma lista calendario
*/
void ordenaPorHora(ListaCalendario *c);
/**
*Ordena as horas por minuto
*@param c um ponteiro para uma lista calendario
*/
void ordenaPorMinuto(ListaCalendario *c);
/**
*Copia os dados de uma lista calendario para outra
*@param dest um ponteiro para uma lista calendario que será o destino
*@param orig um ponteiro para uma lista calendario que será o origem
*/
void copiaInfoLista(ListaCalendario *dest, ListaCalendario *orig);
/**
*troca os dados entre duas listas
*@param l1 um ponteiro para uma lista calendario que será trocado com l2
*@param l2 um ponteiro para uma lista calendario que será trocado com l1
*/
void swapDadosLista(ListaCalendario *l1, ListaCalendario *l2);

#endif

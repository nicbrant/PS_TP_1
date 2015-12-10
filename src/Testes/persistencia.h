#ifndef _PERSISTENCIA_H
#define _PERSISTENCIA_H

#include "tratamento.h"

void imprimeCalendario(ListaCalendario *cal);
void imprimeMesAno(int mes, int ano, FILE *arquivo);
void imprimeTodoCalendario(ListaCalendario *c, FILE *arquivo);
void imprimeDiaCalendario(ListaCalendario *cal,FILE* arquivo);
void imprimeCalendarioDeAB(ListaCalendario *cal,FILE * arquivo);
void imprimePalestraSemLocal(ListaCalendario *temp, FILE* arquivo);
void imprimePalestraComLocal(ListaCalendario *temp, FILE* arquivo);
void imprimeLocal(ListaCalendario *c, FILE *arquivo);

#endif

#ifndef _TRATAMENTOLOCAL_H
#define _TRATAMENTOLOCAL_H

/**
*converte os dados de um LocalStr para uma Localidade
*@param localidadeStr um ponteiro para um LocalStr que será converida no retorno
*@return Uma Struct Localidade
*/
Localidade *converteLocalStrInt(LocalStr *localidadeStr);

/**
*Aloca ao dia o local da palestra
*@param calendario um ponteiro para uma lista calendario que será o destino de uma localidade
*@param lugar um ponteiro para uma Localidade que será alocada no calendario
*@return Uma Struct ListaCalendario
*/
ListaCalendario* alocaLocal(ListaCalendario *calendario, Localidade *lugar);

int locaisVazios(Localidade *local);

int calendarioVazio(ListaCalendario *c);

/**
*atribui uma semana ao dia
*@param dia um ponteiro para caracter que será convertido em inteiro para semana
*@return Um inteiro
*/
int atribuiSemana2(char *dia);

#endif

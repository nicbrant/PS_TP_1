#ifndef _LEITURAPALESTRA_H
#define _LEITURAPALESTRA_H

#include "listaPalestra.h"

/**
*Armazena os dados do arquivo 'palestras.txt'numa lista do tipo 'ArmazenaPalestra'
*@param arquivo um ponteiro para um arquivo que será a origem dos
*@return Uma Struct ArmazenaPalestra
*/
ArmazenaPalestra* leArquivo2(FILE *arquivo);

#endif

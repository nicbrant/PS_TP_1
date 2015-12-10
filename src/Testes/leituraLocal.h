#ifndef _LEITURALOCAL_H
#define _LEITURALOCAL_H

#include "listaLocal.h"
/**
*le e pega os dados de local de um arquivo
*@param arquivo um ponteiro para um arquivo que será a origem
*@return Uma Struct LocalStr
*/
LocalStr* leArquivoLocal(FILE *arquivo);
int ListaLocalVazia (LocalStr *lista);

#endif

#ifndef LEITURAPALESTRANTE_H
#define LEITURAPALESTRANTE_H

struct armazenaDispo /*Vamos nos referir a lista dela como "arquivo1"*/
{
	char nomePalestrante[100];
	char dispo[1000];
	struct armazenaDispo *prox;
};
typedef struct armazenaDispo ArmazenaDispo;

/* Armazena os dados do arquivo 'palestrantes.txt'
* numa lista do tipo 'ArmazenaDispo'
*/
ArmazenaDispo* leArquivo1(FILE *arquivo);

void desalocaListaPalestrantes(ArmazenaDispo *lista);

#endif

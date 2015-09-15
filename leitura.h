/*Estrutura para guardar dados do arquivo 'palestrantes.txt'*/
struct armazenaDispo /*Vamos nos referir a lista dela como "arquivo1"*/
{
	char nomePalestrante[100];
	char dispo[1000];
	struct armazena *prox;
};
typedef struct armazenaDispo ArmazenaDispo;

/*Estrutura para guardar dados do aquivo 'palestras.txt'*/
struct armazenaPalestra /*Vamos nos referir a lista dela como "arquivo2"*/
{
	char nomePessoa[50], nomePalestra[50], tema[50], local[50];
	int duracao;
};
typedef struct armazenaPalestra ArmazenaPalestra;

/* Armazena os dados do arquivo 'palestrantes.txt'
 * numa lista do tipo 'ArmazenaDispo'
 */

ArmazenaDispo* leArquivo1(FILE *arquivo1);

/* Armazena os dados do arquivo 'palestras.txt'
 * numa lista do tipo 'ArmazenaPalestra'
 */
ArmazenaPalestra* leArquivo2(FILE *arquivo2);

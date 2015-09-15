/*Estrutura para guardar dados do arquivo 'palestrantes.txt'*/
struct armazenaDispo /*Vamos nos referir a lista dela como "arquivo1"*/
{
	char nomePalestrante[100];
	char dispo[1000];
	struct armazenaDispo *prox;
};
typedef struct armazenaDispo ArmazenaDispo;

/*Estrutura para guardar dados do aquivo 'palestras.txt'*/
struct armazenaPalestra /*Vamos nos referir a lista dela como "arquivo2"*/
{
	char nomePessoa[50], nomePalestra[50], tema[50], local[50];
	int duracao;
	struct armazenaPalestra *prox;
};
typedef struct armazenaPalestra ArmazenaPalestra;

/*Nó da lista para armazenar arquivo1*/
struct listaParaArquivo1
{
	ArmazenaDispo *info;
	struct listaParaArquivo1 *prox;
};
typedef listaParaArquivo1 ListaParaArquivo1;

/*Nó da lista para armazenar arquivo2*/
struct listaParaArquivo2
{
	ArmazenaPalestra *info;
	struct listaParaArquivo2 *prox;
};
typedef listaParaArquivo2 ListaParaArquivo2;

/*Nó da lista para armazenar arquivo2*/
struct listaParaArquivo2
{
  ArmazenaPalestra *info;
  struct listaParaArquivo2 *prox;
};
typedef listaParaArquivo2 ListaParaArquivo2;

ListaParaArquivo1 CriaLista1();
ListaParaArquivo2 CriaLista2();
void VerificaCriacao(ListaParaArquivo1* lista1, ListaParaArquivo2 *lista2);
void DesalocaLista1(ListaParaArquivo1 *lista);
void DesalocaLista2(ListaParaArquivo2 *lista);
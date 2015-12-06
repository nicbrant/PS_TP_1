/*Estrutura para guardar dados do arquivo 'palestrantes.txt'*/
struct armazenaDispo /*Vamos nos referir a lista dela como "arquivo1"*/
{
	char nomePalestrante[100];
	char dispo[1000];
<<<<<<< HEAD
	struct armazena *prox;
=======
	struct armazenaDispo *prox;
>>>>>>> f3cfc8487544d1176dc3b8960bb58bd5a324082d
};
typedef struct armazenaDispo ArmazenaDispo;

/*Estrutura para guardar dados do aquivo 'palestras.txt'*/
struct armazenaPalestra /*Vamos nos referir a lista dela como "arquivo2"*/
{
	char nomePessoa[50], nomePalestra[50], tema[50], local[50];
	int duracao;
<<<<<<< HEAD
=======
	struct armazenaPalestra *prox;
>>>>>>> f3cfc8487544d1176dc3b8960bb58bd5a324082d
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
<<<<<<< HEAD
=======

ListaParaArquivo1 CriaLista1();
ListaParaArquivo2 CriaLista2();
void VerificaCriacao(ListaParaArquivo1* lista1, ListaParaArquivo2 *lista2);
void DesalocaLista1(ListaParaArquivo1 *lista);
void DesalocaLista2(ListaParaArquivo2 *lista);
>>>>>>> f3cfc8487544d1176dc3b8960bb58bd5a324082d

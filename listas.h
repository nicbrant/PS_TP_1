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
/*    Estrutura para armazenar a disponibilidade de forma numérica.
 * Para armazenar os dados tratados, será criada uma lista do tipo
 * 'dataPalestra' dentro da estrutura 'ListaCalendario', para o caso 
 * de haver mais de uma disponibilidade
 */
struct data
{
  int dia, mes, ano;
};
typedef struct data dataPalestra;


/*	Estrutura que irá guardar os dados tratados, ou seja, onde
 * a disponibilidade será em números.
 */
struct listaCalendario
{
	dataPalestra disponibilidade;
	char nomePalestrante[100];
	char temaPalestra[100];
	/*Hora e minuto serão em segundos */
	int horaInicio, minutoInicio, horaFim, minutoFim, duracao;
	struct listaCalendario *prox;
};
typedef struct listaCalendario ListaCalendario;


/*	Cria lista onde a disponibilidade passa a ser númerica ao invés
 * de uma string, facilitando a manipulação. Mais especificamente, uma
 * lista encadeada do tipo 'dataPalestra'
 * 	Após a criação da nova lista com disponibidade numérica, destruir
 * a lista anterior 'l', ou seja, a que ainda guarda a disponibilidade 
 * em forma de string.
 */
ListaCalendario* criaListaTratada(ListaParaArquivo1 *l);

void liberaListaArquivo1(ArmazenDispo *lista);

void liberaListaArquivo2(ArmazenaPalestra *lista);
/* Imprime os dados da lista do tipo 'listaCalendario' em um arquivo
com a formatação necessária.
*/
void imprimeCalendario(ListaCalendario *calendario, FILE *arquivoSaida);

/* Algoritmo que alterna os meses entre 30 e 31 dias, lembrando que
fevereiro alterna entre 28 e 29.
*/
void anternaMeses(int anterior);
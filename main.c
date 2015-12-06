#include<stdio.h>
#include"leitura.h"
#include"listas.h"
/* O trabalho será implementado nas seguintes etapas:

1°Etapa:	Será lido os dados do arquivo 'palestrantes.txt' e cada informação será 
	alocada em uma lista encadeada dentro de uma estrutura chamada 'ArmazenaDispo'.
	Chamaremos 'palestrantes.txt' e 'palestras.txt' de arquivo1 e arquivo2 por
	facilidade e organização.
		Essa etapa será realizada com as funções de 'leitura.h' (leitura) e o
	armazenamento nas estruturas é realizado pelo arquivo 'listas.h';

2ºEtapa:	A segunda etapa é o tratamento de dados. Eles serão tratados para que sua
	manipulação seja mais fácil e eficaz. Os dados da estrutura 'AmazenaPalestra'
	gerado na etapa passada serão clonados em uma nova lista encadeada (a ser criada)
	do tipo listaCalendario, mas com algumas diferenças da anterior, seu campo 'dispo' 
	que se refere a disponibilidade será alterado para valores numéricos, atráves da 
	estrutura 'dataPalestra' que contêm campos que representam dia, mês e ano. Assim,
	por exemplo, seu dia será referido por:
			listaCalendario->disponibilidade->dia
		Vale observar que a nova cópia contêm alguns campos adicionais, como:
	- Nome do palestrante;
	- Horário de início e fim;
	As informações para esses campos serão retirados do arquivo2 atráves das funções do 
	arquivo 'tratamento.h' e copiadas para a lista clonada criada na segunda etapa,
	armazenado nos novos campos gerados.
		Importante liberar a antiga lista 'ArmazenaPalestra' gerada na primeira etapa.

3°Etapa:	Através do arquivo 'calendario.h', a lista que contêm as informações das 
	palestras (numa lista do tipo 'ListaCalendario') será ordenada de acordo com dia, mês
	e ano, respectivamente. Após ordenar por data, irá ordenar de acordo com as horas.
		
4ºEtapa:	A última etapa consiste apenas em imprimir os dados da lista do tipo 'Lista
	Calendario' com a formatação requerida, afinal de contas eles já estão ordenados. 
	O único ponto a ser observado é fazer com que os meses tenham 30 e 31 dias em alterna
	tividade e o mês 2 (fevereiro) tenha 28 e 29 da mesma forma.

5°Etapa:	Cantar We Are The Champios e festejar...
	...ou talvez refazer tudo diversas vezes. D:
		Por isso, controle na hora de codificar e cuidado. Cada alteração em uma função 
	como retorno, argumentos, assim como as estruturas deve ser notificado a todo o grupo.

*/
int main()
{
	ListaParaArquivo1 *lista1 = CriaLista1();
	ListaParaArquivo2 *lista2 = CriaLista2();
	VerificaCriacao(lista1, lista2);
	FILE *arquivo1 = fopen("palestrantes.txt", "r");
	if (!arquivo1) {
		exit(2027);
	}
	lista1->info = leArquivo1(arquivo1);
	fclose(arquivo1);
	FILE *arquivo2 = fopen("palestras.txt", "r");
	if (!arquivo2) {
		exit(2028);
	}
	lista1->info = leArquivo1(arquivo2);
	fclose(arquivo2);
	/*code*/
	DesalocaLista1(lista1);
	DesalocaLista2(lista2);
return 0;
}
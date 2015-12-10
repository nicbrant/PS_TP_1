#include<stdio.h>
#include<stdlib.h>
#include"leituraPalestra.h"
#include"leituraPalestrante.h"
#include"leituraLocal.h"
#include"listaLocal.h"
#include"listaPalestra.h"
#include"listaPalestrante.h"
#include"calendario.h"
#include"persistencia.h"
#include"tratamento.h"
#include"tratamentoLocal.h"

/* Verifica se os arquivos foram abertos corretamente */
void verificaAbertura(FILE *);

int main()
{
	ArmazenaDispo *listaPalestrantes = NULL;
	ArmazenaPalestra *listaPalestras = NULL;
	ListaCalendario *calendario = NULL;
	Localidade *local = NULL;
	LocalStr *lugarStr = NULL;

	/* Abre arquivo palestrantes.txt */
	FILE *arquivoPalestrantes = fopen("palestrantes.txt", "a+");
	verificaAbertura(arquivoPalestrantes);

	/* Lê o arquivo aberto acima e fecha em seguida */
	listaPalestrantes = leArquivo1(arquivoPalestrantes);
	fclose(arquivoPalestrantes);

	/* Abre arquivo palestras.txt */
	FILE *arquivoPalestras = fopen("palestras.txt", "a+");
	verificaAbertura(arquivoPalestras);
	
	/* Lê o arquivo aberto acima e fecha em seguida */
	listaPalestras = leArquivo2(arquivoPalestras);
	fclose(arquivoPalestras);
	
	/* Abre arquivo localidade.txt */
	FILE *arquivoLocais = fopen("localidade.txt", "a+");
	verificaAbertura(arquivoLocais);

	/* Lê o arquivo aberto acima e fecha em seguida, mas ao
	 mesmo tempo ele trata a estrutura do arquivo e atribui
	 a informação em uma lista encadeada */
	lugarStr = (LocalStr*) leArquivoLocal(arquivoLocais);
	local = converteLocalStrInt(lugarStr);
	fclose(arquivoLocais);

	/* Trata a as informações coletadas dos arquivos e atribui ao calendário */
	calendario = criaListaTratada(listaPalestrantes, listaPalestras);

	/* Libera a memória usada pelas estruturas que (agora) são inúteis */
	desalocaListaPalestrantes(listaPalestrantes);
	desalocaListaPalestras(listaPalestras);

	/* Ordena o calendário de acordo com a data e hora */
	ordenaListaTratada(calendario);
	
	/* Atribui um local para cada elemento do calendário */ 
	calendario = alocaLocal(calendario, local);

	/* Grava o calendário em um arquivo de saída */
	imprimeCalendario(calendario);

	return 0;
}

void verificaAbertura(FILE *arquivo)
{
	if (arquivo == NULL)
	{
		printf ("Arquivo não aberto! Verifique se os arquivos necessários estão disponíveis!"
			"\nPrograma abortado!\n");
		exit(1);
	}
}

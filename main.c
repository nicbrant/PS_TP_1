#include<stdio.h>
#include<stdlib.h>
#include"leituraPalestra.h"
#include"leituraPalestrante.h"
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

	/*
	TESTE E ERRO: QUANDO VAMOS IMPRIMIR TODOS OS LOCAIS. APÓS IMPRIMIR O ULTIMO DÁ SEG. FAULT
	Se a mensagem final for impressa, o erro não existe mais.

	Localidade *l;
	for (l = local; l != NULL; l=l->prox)
	 printf("%d:%d %d:%d %d/%d/%d %s\n", l->horaInicio, l->minutoInicio, l->horaFim, l->minutoFim, l->dia, l->mes, l->ano, l->sala);
	printf("Percorreu os locais perfeitamente. ");
	*/

	/* Trata a as informações coletadas dos arquivos e atribui ao calendário */
	calendario = criaListaTratada(listaPalestrantes, listaPalestras);

	/*
	TESTE SEM ERRO:
		Imprime os dados do calendário ainda sem o local.
		
	ListaCalendario *l;
	for (l = calendario; l != NULL; l=l->prox)
	 printf("%d:%d %d:%d %d/%d/%d %d %s %s\n", l->horaInicio, l->minutoInicio, l->horaFim, l->minutoFim, l->disponibilidade.dia, l->disponibilidade.mes, l->disponibilidade.ano, l->diaSemana, l->nomePalestra, l->nomePalestrante);
	*/


	/* Libera a memória usada pelas estruturas que (agora) são inúteis */
	desalocaListaPalestrantes(listaPalestrantes);
	desalocaListaPalestras(listaPalestras);

	/* Ordena o calendário de acordo com a data e hora */
	ordenaListaTratada(calendario);

	/* Atribui um local para cada elemento do calendário */ 
	calendario = alocaLocal(calendario, local);

	printf("Alocou os locais no calendário!\n");

	/* Abre o arquivo de saída */
	FILE *arquivoFinal = fopen("calendario.txt", "w+");
	verificaAbertura(arquivoFinal);

	/* Grava o calendário no arquivo de saída */
	imprimeCalendario(calendario, arquivoFinal);

	fclose(arquivoFinal);

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

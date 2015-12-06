#include <stdio.h>
#include <stdlib.h>
#include "listaPalestra.h"
#include "leituraPalestrante.h"
#include "persistencia.h"
#include "listaLocal.h"
#include "tratamento.h"

/* Função que grava no arquvio de saída o calendario com os meses, dias, palestrantes, palestras e outros dados */
void imprimeCalendario(ListaCalendario *calendario, FILE *arquivoSaida) {
	ListaCalendario *auxiliar, *auxiliar2;
	int dia, mes, ano, ultimoMes, ultimoAno, diaMes, condicao = 0, i, diaSemana;

	auxiliar = calendario;
	auxiliar2 = calendario;
	dia = calendario->disponibilidade.dia;
	mes = calendario->disponibilidade.mes;
	ano = calendario->disponibilidade.ano;

	/* Encontra a última data que tem alguma palestra */
	while (auxiliar != NULL) {
		if (auxiliar->prox == NULL) {
			ultimoMes = auxiliar->disponibilidade.mes;
			ultimoAno = auxiliar->disponibilidade.ano;
			break;
		}
		auxiliar = auxiliar->prox;
	}
	
	/* Começa a gravar no arquivo os dados */
	fprintf (arquivoSaida, "Calendario de Palestras (%d/%d - %d/%d)", mes, ano, ultimoMes, ultimoAno);
	auxiliar = calendario;

	/* Laço de repetição que grava toda a lista no arquivo */
	do {
		imprimeDataArquivo(arquivoSaida, mes, ano);

		/* Descobre quantos dias tem o mês que está gravando */
		diaMes = alternaMeses(mes, ano);

		/* Grava os dados referentes a cada dia no arquivo até chegar no último dia do mês */
		while (dia <= diaMes) {
			fprintf (arquivoSaida, "Dia %d", dia);
			i = dia;
			diaSemana = retornaDiaSemana(mes, dia, ano);

			while (dia == auxiliar->disponibilidade.dia || auxiliar->disponibilidade.dia == 00) {
				/* Para a cada dia da semana, verifica se tem alguém que está disponível para o mês todo e imprime a pessoa caso exista */
				if (i == diaSemana) {

					while (auxiliar2->disponibilidade.mes == mes) {
						fprintf (arquivoSaida, "%s (%s): \n", auxiliar->tema, auxiliar->nomePalestrante);
						fprintf (arquivoSaida, "%d:%d %d:%d\n", (int)(auxiliar->horaInicio/3600), (int)(auxiliar->minutoInicio/60),
																										(int)(auxiliar->horaFim/3600), (int)(auxiliar->minutoFim/60));

						if (auxiliar2->existeLocal == 1) {
							fprintf (arquivoSaida, "Local: %s\nEndereço: %s\n", auxiliar->local->sala, auxiliar->local->endereco);
						}
						else {
							fprintf (arquivoSaida, "Local a designar\n");
						}
						auxiliar2 = auxiliar2->prox;
					}

					auxiliar2 = calendario;
					i = 1;
				}

				else if (auxiliar->disponibilidade.dia != 00) {
					fprintf (arquivoSaida, "%s (%s): \n", auxiliar->tema, auxiliar->nomePalestrante);
					fprintf (arquivoSaida, "%d:%d %d:%d\n", (int)(auxiliar->horaInicio/3600), (int)(auxiliar->minutoInicio/60),
																									(int)(auxiliar->horaFim/3600), (int)(auxiliar->minutoFim/60));

					if (auxiliar->existeLocal == 1) {
						fprintf (arquivoSaida, "Local: %s\nEndereço: %s\n", auxiliar->local->sala, auxiliar->local->endereco);
					}
					else {
						fprintf (arquivoSaida, "Local a designar\n");
					}
					auxiliar = auxiliar->prox;
					i++;
				}
			}
            fprintf (arquivoSaida, "\n");
            dia++;
		}

		/* Reinicia o valor da variável dia e muda de mês, caso o mês seja o último de ano, também muda o ano */
		dia = auxiliar2->disponibilidade.dia;
		mes++;
		i = dia;
		if (mes > 12) {
			ano++;
			mes = 1;
		}
		/* Condição para descobrir se já foi gravado todos os dados no arquivo */
		if (auxiliar == NULL) {
			condicao = 1;
		}

	}	while (condicao == 0);

}

/* Função que descobre quantos dias tem cada mês, incluindo se o ano for bissexto, e retorna a quantidade de dias do mês */
int alternaMeses (int mes, int ano) {
	if (mes == 2) {
		if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else {
		if ((mes == 1)	|| (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
			return 31;
		}
		else {
			return 30;
		}
	}
}

/* Função que retorna valor numérico referente ao dia da semana de acordo com a data */
int retornaDiaSemana(int mes, int dia, int ano) {  
	int a = ((12 - mes) / 10);
	int b = ano - a;
	int c = mes + (12 * a);
	int d = b / 100;
	int e = d / 4;
	int f = 2 - d + e;
	int g = (int) 365.25 * b;
	int h = (int) (30.6001 * (c + 1));
	int i = (int) ((f + g) + (h + dia) + 5);
	int j = (int) (i % 7); /* Resto de I por 7, onde 0=SAB, 1=DOM, 2=SEG, 3=TER, 4=QUA, 5=QUI, 6=SEX */

	if (j != 0) {
		j = j - 1;
	}
	else {
		j = 6;
	}

	/* Testa o resultado e retorna */
	switch (j) {
		case 0:
			return SAB;
		case 1:
			return DOM;
		case 2:
			return SEG;
		case 3:
			return TER;
		case 4:
			return QUA;
		case 5:
			return QUI;
		case 6:
			return SEX;
		default:
			return -1;
	}
}

/* Imprime no arquivo o mês e ano passado como parâmetro */
void imprimeDataArquivo (FILE *arquivoSaida, int mes, int ano) {

	fprintf (arquivoSaida, "Mes %d/%d - ", mes, ano);

	switch (mes) {
		case 1:
			fprintf (arquivoSaida, "Janeiro\n\n");
		break;
		case 2:
			fprintf (arquivoSaida, "Fevereiro\n\n");
		break;
		case 3:
			fprintf (arquivoSaida, "Marco\n\n");
		break;
		case 4:
			fprintf (arquivoSaida, "Abril\n\n");
		break;
		case 5:
			fprintf (arquivoSaida, "Maio\n\n");
		break;
		case 6:
			fprintf (arquivoSaida, "Junho\n\n");
		break;
		case 7:
			fprintf (arquivoSaida, "Julho\n\n");
		break;
		case 8:
			fprintf (arquivoSaida, "Agosto\n\n");
		break;
		case 9:
			fprintf (arquivoSaida, "Setembro\n\n");
		break;
		case 10:
			fprintf (arquivoSaida, "Outubro\n\n");
		break;
		case 11:
			fprintf (arquivoSaida, "Novembro\n\n");
		break;
		case 12:
			fprintf (arquivoSaida, "Dezembro\n\n");
		break;
	}
}

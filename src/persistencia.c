#include<stdio.h>
#include<stdlib.h>
#include"tratamento.h"
#include"persistencia.h"

int exibeMenu()
{
	int opcaoMenu;
	system("clear");
	printf("Bem vindo ao sistema de gerenciamento de palestras.\nSelecione uma opção:\n");
	printf("1. Exibir todo o calendário;\n2. Exibir apenas um dia específico;\n3. Exibir a partir de uma data;\n4. Sair\n\nOpção: ");
	scanf(" %d", &opcaoMenu);
	system("clear");
	return opcaoMenu;
}

void imprimeMesAno(int mes, int ano, FILE *arquivo)
{
	int i;
	fprintf(arquivo, "\n");
	switch(mes)
	{
		case 0: fprintf(arquivo, "A data deste evento ainda está indeterminada!\n"); 
			for (i=0; i<30;i++)
				fprintf(arquivo, "*");
					fprintf(arquivo, "\n");
			return;
		case 1: fprintf(arquivo, "Janeiro - "); break;
		case 2: fprintf(arquivo, "Fevereiro - "); break;
		case 3:	fprintf(arquivo, "Março - "); break;
		case 4: fprintf(arquivo, "Abril - "); break;
		case 5: fprintf(arquivo, "Maio - "); break;
		case 6: fprintf(arquivo, "Junho - "); break;
		case 7: fprintf(arquivo, "Julho - "); break;
		case 8: fprintf(arquivo, "Agosto - "); break;
		case 9: fprintf(arquivo, "Setembro - "); break;
		case 10:	fprintf(arquivo, "Outubro - "); break;
		case 11:	fprintf(arquivo, "Novembro - "); break;
		case 12:	fprintf(arquivo, "Dezembro - "); break;
	}
	fprintf(arquivo, "Ano: %d\n", ano);
	for (i=0; i<30;i++)
		fprintf(arquivo, "*");
	fprintf(arquivo, "\n");
}

void imprimePalestraComLocal(ListaCalendario *l, FILE *arquivo)
{
	fprintf(arquivo, "Palestra: %s\nPalestrante: %s\nLocal: %s\nSala: %s\n"
							 "Horário: %d:%d até %d:%d\n\n", l->nomePalestra, l->nomePalestrante, l->local->endereco, l->local->sala,
							 					 l->horaInicio, l->minutoInicio, l->horaFim, l->minutoFim);
}

void imprimePalestraSemLocal(ListaCalendario *l, FILE *arquivo)
{
	fprintf(arquivo, "Palestra: %s\nPalestrante: %s\nLocal a definir\n"
							 "Horário: %d:%d até %d:%d\n\n", l->nomePalestra, l->nomePalestrante,
							 					 l->horaInicio, l->minutoInicio, l->horaFim, l->minutoFim);
}

void imprimeLocal(ListaCalendario *l, FILE *arquivo)
{
	if (l->local == NULL)
			imprimePalestraSemLocal(l, arquivo);
	else
			imprimePalestraComLocal(l, arquivo);
}

void imprimeTodoCalendario(ListaCalendario *c, FILE *arquivo)
{
	ListaCalendario *l;
	int mesAtual = c->disponibilidade.mes, anoAtual = c->disponibilidade.ano;
	imprimeMesAno(mesAtual, anoAtual, arquivo);
	for (l = c; l != NULL; l = l->prox)
	{
		if (mesAtual != l->disponibilidade.mes)
		{
			mesAtual = l->disponibilidade.mes;
			anoAtual = l->disponibilidade.ano;
			imprimeMesAno(mesAtual, anoAtual, arquivo);
		}
		fprintf(arquivo, "Dia: %d/%d/%d\n", l->disponibilidade.dia, mesAtual, anoAtual);
		while (l->prox != NULL &&
			   l->disponibilidade.dia == l->prox->disponibilidade.dia &&
			   l->disponibilidade.mes == l->prox->disponibilidade.mes &&
			   l->disponibilidade.ano == l->prox->disponibilidade.ano)
		{
			imprimeLocal(l, arquivo);
		}
		imprimeLocal(l, arquivo);
	}
	printf("O calendário foi gerado. Consulte o arquivo 'calendário' em seu diretório local.\n");
	getchar();
	getchar();
}

void imprimeDiaCalendario(ListaCalendario *c, FILE *arquivo)
{
	system("clear");
	int dia, mes, ano, existe = 0;
	ListaCalendario *l = c;

	printf("Insira o dia que deseja consultar (dd/mm/aa): ");
	scanf(" %d %d %d", &dia, &mes, &ano);

	fprintf(arquivo, "Eventos para o dia %d/%d/%d: \n\n", dia, mes, ano);
	while (l != NULL && l->disponibilidade.dia != dia && l->disponibilidade.mes != mes && l->disponibilidade.ano != ano)
		l = l->prox;
	while (l != NULL && l->disponibilidade.dia == dia && l->disponibilidade.mes == mes && l->disponibilidade.ano == ano)
	{
		imprimeLocal(l, arquivo);
		existe = 1;
		l = l->prox;
	}

	if (!existe)
		fprintf(arquivo, "Não existem eventos registrados para o dia %d/%d/%d.\n", dia, mes, ano);

	system("clear");
	printf("O calendário foi gerado. Consulte o arquivo 'calendário' em seu diretório local.\n");
	getchar();
	getchar();
}


void imprimeCalendarioDeAB(ListaCalendario *c, FILE *arquivo)
{
	system("clear");
	int anoInicio, mesInicio, m, a;
	printf("Insira o mês e ano de inicio (mm/aaaa): ");
	scanf(" %d %d", &mesInicio, &anoInicio);

	ListaCalendario *l = c;
	while (l->disponibilidade.mes < mesInicio || l->disponibilidade.ano < anoInicio)
		l = l->prox;
	system("clear");
	imprimeTodoCalendario(l, arquivo);
}

void imprimeCalendario(ListaCalendario *c)
{
	int opcaoMenu = 0;
	
	while (opcaoMenu != 4)
	{
		opcaoMenu = exibeMenu();
		
		FILE *arquivo = fopen("calendario.txt", "w+");
		if (arquivo == NULL)
		{
			printf("Impossivel abrir arquivo final!\nPrograma Abortado!\n");
			exit(1);
		}

		if (opcaoMenu == 1)
		{
			imprimeTodoCalendario(c, arquivo);
			fclose(arquivo);
		}
		else if (opcaoMenu == 2)
		{
			imprimeDiaCalendario(c, arquivo);
			fclose(arquivo);
		}
		else if (opcaoMenu == 3)
		{
			imprimeCalendarioDeAB(c, arquivo);
			fclose(arquivo);
		}
		system("clear");
	
	}
}

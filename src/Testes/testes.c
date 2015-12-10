#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "listaPalestra.h"
#include "leituraPalestrante.h"
#include "listaLocal.h"
#include "leituraLocal.h"
#include "persistencia.h"
#include "tratamento.h"
#include "tratamentoLocal.h"

void Teste_alternaMeses_Fevereiro28 (void);
void Teste_alternaMeses_Fevereiro29 (void);
void Teste_alternaMeses_Mes30 (void);
void Teste_alternaMeses_Mes31 (void);
void Teste_retornaDiaSemana_Domingo (void);
void Teste_retornaDiaSemana_Quarta (void);
void Teste_retornaDiaSemana_Sexta (void);
void Teste_atribuiSemana_Segunda (void);
void Teste_atribuiSemana_Quinta (void);
void Teste_atribuiSemana_Sabado (void);
void Teste_ListaPalestrasVazia (void);
void Teste_ListaPalestras_NaoVazia (void);
void Teste_ListaPalestrantesVazia (void);
void Teste_ListaPalestrantes_NaoVazia (void);
void Teste_ListaLocalVazia (void);
void Teste_ListaLocal_NaoVazia (void);
void Teste_calendarioVazio (void);
void Teste_calendario_NaoVazio (void);
void Teste_locaisVazios (void);
void Teste_locais_NaoVazios (void);
void Add_Suite_Testes(void);

int main(void){
	
	if (CUE_SUCCESS != CU_initialize_registry()){
		return CU_get_error();
	}
   
   Add_Suite_Testes();
   CU_basic_set_mode(CU_BRM_VERBOSE);
   
   CU_basic_run_tests();
   CU_cleanup_registry();

	return CU_get_error();
}

void Teste_alternaMeses_Fevereiro28 (void) {
	CU_ASSERT_EQUAL(alternaMeses(2, 2015), 28);
	return;
}

void Teste_alternaMeses_Fevereiro29 (void) {
	CU_ASSERT_EQUAL(alternaMeses(2, 2016), 29);
	return;
}

void Teste_alternaMeses_Mes30 (void) {
	CU_ASSERT_EQUAL(alternaMeses(4, 2015), 30);
	return;
}


void Teste_alternaMeses_Mes31 (void) {
	CU_ASSERT_EQUAL(alternaMeses(1, 2015), 31);
	return;
}

void Teste_retornaDiaSemana_Domingo (void) {
	CU_ASSERT_EQUAL(retornaDiaSemana(11, 1, 2015), DOM);
	return;
}

void Teste_retornaDiaSemana_Quarta (void) {
	CU_ASSERT_EQUAL(retornaDiaSemana(11, 4, 2015), QUA);
	return;
}

void Teste_retornaDiaSemana_Sexta (void) {
	CU_ASSERT_EQUAL(retornaDiaSemana(11, 6, 2015), SEX);
	return;
}

void Teste_atribuiSemana_Segunda (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Seg"), 2);
	return;
}

void Teste_atribuiSemana_Quinta (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Qui"), 5);
	return;
}

void Teste_atribuiSemana_Sabado (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Sab"), 7);
	return;
}

void Teste_ListaPalestrasVazia (void) {
	ArmazenaPalestra *AP = NULL;

	CU_ASSERT_TRUE(ListaPalestrasVazia(AP));
	return;
}

void Teste_ListaPalestras_NaoVazia (void) {
	ArmazenaPalestra *AP;
	*AP = (ArmazenaPalestra *) malloc(sizeof(ArmazenaPalestra));
	AP->prox = NULL;

	CU_ASSERT_FALSE(ListaPalestrasVazia(AP));
	desalocaListaPalestras(AP);
	return;
}

void Teste_ListaPalestrantesVazia (void) {
	ArmazenaDispo *AD = NULL;

	CU_ASSERT_TRUE(ListaPalestrantesVazia(AD));
	return;
}

void Teste_ListaPalestrantes_NaoVazia (void) {
	ArmazenaDispo *AD;
	*AD = (ArmazenaDispo *) malloc(sizeof(ArmazenaDispo));
	AD->prox = NULL;

	CU_ASSERT_FALSE(ListaPalestrantesVazia(AD));
	desalocaListaPalestrantes(AD);
	return;
}

void Teste_ListaLocalVazia (void) {
	LocalStr *LS = NULL;

	CU_ASSERT_TRUE(ListaLocalVazia(LS));
	return;
}

void Teste_ListaLocal_NaoVazia (void) {
	LocalStr *LS;
	*LS = (LocalStr *) malloc(sizeof(LocalStr));
	LS->prox = NULL;

	CU_ASSERT_FALSE(ListaLocalVazia(LS));
	free(LS);
	return;
}

void Teste_calendarioVazio (void) {
	ListaCalendario *LC = NULL;

	CU_ASSERT_TRUE(calendarioVazio(LC));
	return;
}

void Teste_calendario_NaoVazia (void) {
	ListaCalendario *LC;
	*LC = (ListaCalendario *) malloc(sizeof(ListaCalendario));
	LC->prox = NULL;

	CU_ASSERT_FALSE(calendarioVazio(LC));
	free(LC);
	return;
}

void Teste_locaisVazios (void) {
	Localidade *local = NULL;

	CU_ASSERT_TRUE(locaisVazios(local));
	return;
}

void Teste_locais_NaoVazios (void) {
	Localidade *local;
	*local = (Localidade *) malloc(sizeof(Localidade));
	local->prox = NULL;

	CU_ASSERT_TRUE(locaisVazios(local));
	free(local);
	return;
}

void Add_Suite_Testes(void) {
	CU_pSuite suite = NULL;

	suite = CU_add_suite( "Testes", NULL, NULL);

	CU_ADD_TEST(suite, Teste_alternaMeses_Fevereiro28);
	CU_ADD_TEST(suite, Teste_alternaMeses_Fevereiro29);
	CU_ADD_TEST(suite, Teste_alternaMeses_Mes30);
	CU_ADD_TEST(suite, Teste_alternaMeses_Mes31);
	CU_ADD_TEST(suite, Teste_retornaDiaSemana_Domingo);
	CU_ADD_TEST(suite, Teste_retornaDiaSemana_Quarta);
	CU_ADD_TEST(suite, Teste_retornaDiaSemana_Sexta);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Segunda);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Quinta);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Sabado);
	CU_ADD_TEST(suite, Teste_ListaPalestrasVazia);
	CU_ADD_TEST(suite, Teste_ListaPalestras_NaoVazia);
	CU_ADD_TEST(suite, Teste_ListaPalestrantesVazia);
	CU_ADD_TEST(suite, Teste_ListaPalestrantes_NaoVazia);
	CU_ADD_TEST(suite, Teste_ListaLocalVazia);
	CU_ADD_TEST(suite, Teste_ListaLocal_NaoVazia);
	CU_ADD_TEST(suite, Teste_calendarioVazio);
	CU_ADD_TEST(suite, Teste_calendario_NaoVazio);
	CU_ADD_TEST(suite, Teste_locaisVazios);
	CU_ADD_TEST(suite, Teste_locais_NaoVazios);

	return;
}

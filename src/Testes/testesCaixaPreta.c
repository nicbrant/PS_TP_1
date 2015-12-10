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

void Teste_atribuiSemana_Domingo (void);
void Teste_atribuiSemana_Segunda (void);
void Teste_atribuiSemana_Terca (void);
void Teste_atribuiSemana_Quarta (void);
void Teste_atribuiSemana_Quinta (void);
void Teste_atribuiSemana_Sexta (void);
void Teste_atribuiSemana_Sabado (void);
void Teste_atribuiSemana_Sabado2 (void);
void Teste_atribuiSemana2_Domingo (void);
void Teste_atribuiSemana2_Segunda (void);
void Teste_atribuiSemana2_Terca (void);
void Teste_atribuiSemana2_Quarta (void);
void Teste_atribuiSemana2_Quinta (void);
void Teste_atribuiSemana2_Sexta (void);
void Teste_atribuiSemana2_Sabado (void);
void Teste_atribuiSemana2_Sabado2 (void);
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
void Teste_alocaLocal (void);
void Teste_alocaLocal_Vazio (void);

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

void Teste_atribuiSemana_Domingo (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Dom"), 1);
	return;
}

void Teste_atribuiSemana_Segunda (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Seg"), 2);
	return;
}

void Teste_atribuiSemana_Terca (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Ter"), 3);
	return;
}

void Teste_atribuiSemana_Quarta (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Qua"), 4);
	return;
}

void Teste_atribuiSemana_Quinta (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Qui"), 5);
	return;
}

void Teste_atribuiSemana_Sexta (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Sex"), 6);
	return;
}

void Teste_atribuiSemana_Sabado (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Sab"), 7);
	return;
}

void Teste_atribuiSemana_Sabado2 (void) {
	CU_ASSERT_EQUAL(atribuiSemana("Sáb"), 2);
	return;
}

void Teste_atribuiSemana2_Domingo (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Dom"), 1);
	return;
}

void Teste_atribuiSemana2_Segunda (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Seg"), 2);
	return;
}

void Teste_atribuiSemana2_Terca (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Ter"), 3);
	return;
}

void Teste_atribuiSemana2_Quarta (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Qua"), 4);
	return;
}

void Teste_atribuiSemana2_Quinta (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Qui"), 5);
	return;
}

void Teste_atribuiSemana2_Sexta (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Sex"), 6);
	return;
}

void Teste_atribuiSemana2_Sabado (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Sab"), 7);
	return;
}

void Teste_atribuiSemana2_Sabado2 (void) {
	CU_ASSERT_EQUAL(atribuiSemana2("Sáb"), 2);
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

void Teste_alocaLocal (void) {
	ListaCalendario *calendario;
	Localidade *local;

	*calendario = (ListaCalendario *) malloc(sizeof(ListaCalendario));
	calendario->disponibilidade.dia = 1;
	calendario->disponibilidade.mes = 1;
	calendario->disponibilidade.ano = 1;
	calendario->horaInicio = 1;
	calendario->horaFim = 1;
	calendario->minutoInicio = 1;
	calendario->minutoFim = 1;
	calendario->prox = NULL;
	*local = (Localidade *) malloc(sizeof(Localidade));
	local->dia = 1;
	local->mes = 1;
	local->ano = 1;
	local->horaInicio = 1;
	local->horaFim = 1;
	local->minutoInicio = 1;
	local->minutoFim = 1;
	local->prox = NULL;


	CU_ASSERT_TRUE((alocaLocal(calendario, local) != NULL));
	free(calendario);
	free(local);
	
}

void Teste_alocaLocal_Vazio (void) {
	ListaCalendario *calendario;

	*calendario = (ListaCalendario *) malloc(sizeof(ListaCalendario));
	calendario->prox = NULL;

	CU_ASSERT_FALSE((alocaLocal(calendario, NULL) != NULL));
	free(calendario);
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

	CU_ADD_TEST(suite, Teste_atribuiSemana_Domingo);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Segunda);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Terca);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Quarta);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Quinta);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Sexta);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Sabado);
	CU_ADD_TEST(suite, Teste_atribuiSemana_Sabado2);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Domingo);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Segunda);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Terca);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Quarta);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Quinta);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Sexta);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Sabado);
	CU_ADD_TEST(suite, Teste_atribuiSemana2_Sabado2);
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
	CU_ADD_TEST(suite, Teste_alocaLocal);
	CU_ADD_TEST(suite, Teste_alocaLocal_Vazio);

	return;
}

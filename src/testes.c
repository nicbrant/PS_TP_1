#include <stdio.h>
#include <stdlib.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "listaPalestra.h"
#include "leituraPalestrante.h"
#include "listaLocal.h"
#include "persistencia.h"
#include "tratamento.h"

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

void Add_Suite_Testes(void) {
	CU_pSuite suite = NULL;

	suite = CU_add_suite( "Testes", NULL, NULL);

	CU_ADD_TEST(suite, Teste_alternaMeses_Fevereiro28);
	CU_ADD_TEST(suite, Teste_alternaMeses_Fevereiro29);
	CU_ADD_TEST(suite, Teste_alternaMeses_Mes30);
	CU_ADD_TEST(suite, Teste_alternaMeses_Mes31);
	CU_ADD_TESTE(suite, Teste_retornaDiaSemana_Domingo);
	CU_ADD_TESTE(suite, Teste_retornaDiaSemana_Quarta);
	CU_ADD_TESTE(suite, Teste_retornaDiaSemana_Sexta);
	CU_ADD_TESTE(suite, Teste_atribuiSemana_Segunda);
	CU_ADD_TESTE(suite, Teste_atribuiSemana_Quinta);
	CU_ADD_TESTE(suite, Teste_atribuiSemana_Sabado);

	return;
}

/***************************************************************************
*  $MCI Módulo de implementação: Módulo dados
*
*  Arquivo gerado:              DADOS.C
*  Letras identificadoras:      DADO
*
*  Nome da base de software:    Jogo de Gamão
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: idmv - Igor Duarte Milanez Vieira 
* 
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações 
*	   2.0     idmv   15/09/2015     Finalizacao 
*      1.0     idmv   15/09/2015     Codificacao
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <stdlib.h>
#define DADOS_OWN
#include "DADOS.H"
#undef DADOS_OWN
#include <time.h>


/***Estrutura***/
typedef struct dado{
    int valorDado1;
	int valorDado2;
}DADO_tpDado;
 
 
 /***** Protótipos das funções encapuladas no módulo *****/
 int GeraValorAleatorio ();
 int GeraValorAleatorio2 ();

/***************************************************************************
*
*  Função: DADO  &Criar dado
*  ****/
	DADO_tpCondRet DADO_CriaDado(DADO_tpDado ** vet, int indice)
	{
		if ( vet[indice] != NULL)
		{
			return DADO_tpCondRetDadoJaExiste;
		}
	 vet[indice] = (DADO_tpDado *) (malloc(sizeof(DADO_tpDado)));
	 if( vet[indice] == NULL)
	 {
	     return DADO_tpCondRetFaltouMemoria;
	 }
			
	 return DADO_tpCondRetOK; 
	}
/**************** FIM FUNCAO Criar Dado ************************************/


/***************************************************************************
*
*  Função: DADO  &Destroi dado
*  ****/
	DADO_tpCondRet DADO_DestroiDado (DADO_tpDado * pDado)
	{
		
	 if ( pDado != NULL)
	 {
	     pDado = NULL;
	     free(pDado);
	 }
		else
	 {
	     return DADO_tpCondRetEstruturaVazia;
	 }
		 return DADO_tpCondRetOK;
	}
/*************** FIM FUNCAO Destroi Dado ***********************************/


/***************************************************************************
*
*  Função: DADO  &Gera Valor Dado
*  ****/
	DADO_tpCondRet DADO_GeraValorDado (DADO_tpDado * pDado)
	{
	 int valor_aleatorio;
	 int valor_aleatorio2;
	 if (pDado == NULL)
	 {
	     return DADO_tpCondRetEstruturaVazia;
	 }
	 
	 valor_aleatorio = GeraValorAleatorio();
	 valor_aleatorio2 = GeraValorAleatorio2();
	 pDado->valorDado1 = valor_aleatorio;
	 pDado->valorDado2 = valor_aleatorio2;
	 return DADO_tpCondRetOK;


	}
/*************** FIM FUNCAO Gera Valor Dado ***********************************/


/*****  Código das funções encapsuladas pelo módulo  *****/

/***************************************************************************
*
*  Função: DADO  &Gera Valor Aleatorio 1
*  ****/

	int GeraValorAleatorio () 
	{
	 int aleatorio;
	 srand(time(NULL));
	 aleatorio = rand()%6 +1;
	 
	 if ( aleatorio < 1 || aleatorio > 6)
	 {
	     return -1;
	 }
	 return aleatorio;
	}
/********************** FIM FUNCAO Gera Valor Aleatorio ***********/

/***************************************************************************
*
*  Função: DADO  &Gera Valor Aleatorio 2
*  ****/

		int GeraValorAleatorio2 () 
	{
	 int aleatorio;
	 aleatorio = rand()%6 +1;
	 
	 if ( aleatorio < 1 || aleatorio > 6)
	 {
	     return -1;
	 }
	 return aleatorio;
	}
		
/********************** FIM FUNCAO Gera Valor Aleatorio 2***********/


/********** Fim do módulo de implementação: DADO Modulo Dados **********/

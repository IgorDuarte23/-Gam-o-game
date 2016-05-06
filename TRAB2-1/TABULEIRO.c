/***************************************************************************
*  $MCI Módulo de implementação: TAB Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    JOGO DE GAMAO
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: idmv -  Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações 
*      4.0     idmv   22/09/2015     assertivas de erros
*      3.0     idmv   21/09/2015     finalizacao
*      2.0     idmv   20/09/2015     mais funcoes
*      1.0     idmv   18/09/2015     inicio do modulo
*
***************************************************************************/

#define TABULEIRO_OWN
#include "TABULEIRO.H"
#undef TABULEIRO_OWN
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor da cabeça do tabuleiro
*
*
***********************************************************************/

   typedef struct tabuleiro {

	   LIS_tppLista pBaseDoTabuleiro;
	   
	   LIS_tppLista pCasaCorr;

   } TAB_tpTabuleiro;
   

   
   /***** Protótipos das funções encapuladas no módulo *****/
   void DestroiBase(void * pValor);

   void DestroiCasa(void * pValor);


/***************************************************************************
*
*  Função: TAB  &Cria tabuleiro
*  ****/
    TAB_tpCondRet TAB_CriaTabuleiro( TAB_tpTabuleiro ** pTabuleiro,int indice){

	   int nmr_pecas;
	   LIS_tpCondRet CondRet;

	   if (pTabuleiro[indice] != NULL)
	   {
		    return TAB_CondRetTabuleiroJaExiste;
		   
	   } 

	   pTabuleiro[indice] = (TAB_tpTabuleiro *)malloc(sizeof(TAB_tpTabuleiro));
	   if (pTabuleiro == NULL){
		   return TAB_CondRetFaltouMemoria;

	   }

	   pTabuleiro[indice]->pBaseDoTabuleiro = LIS_CriarLista(DestroiBase);

	   if (pTabuleiro[indice]->pBaseDoTabuleiro == NULL)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }

	   for (nmr_pecas = 0; nmr_pecas < 24; nmr_pecas++){

		   pTabuleiro[indice]->pCasaCorr = LIS_CriarLista(DestroiCasa);

		   if (pTabuleiro[indice]->pCasaCorr == NULL)
		   {
		   return TAB_CondRetFaltouMemoria;
		   }

		   CondRet = LIS_InserirElementoAntes(pTabuleiro[indice]->pBaseDoTabuleiro, pTabuleiro[indice]->pCasaCorr);

		   if (CondRet == LIS_CondRetFaltouMemoria)
		   {
				return TAB_CondRetFaltouMemoria;
		   }

	   } 
	   return TAB_CondRetOK;

   } /* Fim função: TAB  &Cria tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Destroi tabuleiro
*  ****/

   TAB_tpCondRet TAB_DestroiTabuleiro(TAB_tpTabuleiro ** pTabuleiro, int indice ){

	   int nmr_pecas;

	   if (pTabuleiro[indice]== NULL)
	   {
		   return TAB_CondRetTabuleiroNaoExiste;
	   }

	   IrInicioLista(pTabuleiro[indice]->pBaseDoTabuleiro);

	   for (nmr_pecas = 0; nmr_pecas < 23; nmr_pecas++){

		   pTabuleiro[indice]->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro[indice]->pBaseDoTabuleiro);
		   

		   LIS_DestruirLista(pTabuleiro[indice]->pCasaCorr);

		   LIS_AvancarElementoCorrente(pTabuleiro[indice]->pBaseDoTabuleiro, 1);

	   } 

	   pTabuleiro[indice]->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro[indice]->pBaseDoTabuleiro);

	   LIS_DestruirLista(pTabuleiro[indice]->pCasaCorr);
   
	   LIS_DestruirLista(pTabuleiro[indice]->pBaseDoTabuleiro);

	   pTabuleiro = NULL;

	   return TAB_CondRetOK;
   
   } /* Fim função: TAB  &Destroi tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Quantidade de Pecas Casa
*  ****/   
   TAB_tpCondRet TAB_QuantidadePecasCasa(TAB_tpTabuleiro * pTabuleiro, int casa, int *qtd){

	   LIS_tpCondRet CondRet;
	  

	   *qtd = 0;

	   if (pTabuleiro == NULL)
	   {
		   return TAB_CondRetTabuleiroNaoExiste;
	   }

	   if (casa < 1 || casa > 24)
	   {
		   return TAB_CondRetCasaNaoExiste;
	   }

	   IrInicioLista(pTabuleiro->pBaseDoTabuleiro);
	   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseDoTabuleiro, casa - 1);

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseDoTabuleiro);

	   IrInicioLista(pTabuleiro->pCasaCorr);

	   while (CondRet == LIS_CondRetOK){

		   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pCasaCorr, 1);
		   *qtd +=1;

	   }

	   if (CondRet == LIS_CondRetListaVazia){

		   *qtd = 0;
		   return TAB_CondRetCasaVazia;
	   }

	   return TAB_CondRetOK;
   }/* Fim funcao Quantidade de Pecas Casas */


/***************************************************************************
*
*  Função: TAB  &Retira Peca
*  ****/
   TAB_tpCondRet TAB_RetiraPeca(TAB_tpTabuleiro * pTabuleiro, void **peca, int casa){

	   if (pTabuleiro == NULL)
	   {
		   return TAB_CondRetTabuleiroNaoExiste;
	   }
	  
	   if (casa < 1 || casa > 24)
	   {
		   return TAB_CondRetCasaNaoExiste;
	   }
	   
	   IrInicioLista(pTabuleiro->pBaseDoTabuleiro); 

	   LIS_AvancarElementoCorrente(pTabuleiro->pBaseDoTabuleiro, casa - 1);

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseDoTabuleiro); 

	   IrFinalLista(pTabuleiro->pCasaCorr); 
	   
	   *peca = LIS_ObterValor(pTabuleiro->pCasaCorr); 

	   if (*peca == NULL) 
	   {
		   return TAB_CondRetCasaVazia;
	   }

	   IrFinalLista(pTabuleiro->pCasaCorr);
	   LIS_ExcluirElemento(pTabuleiro->pCasaCorr); 
	   return TAB_CondRetOK;
   } /* Fim função: TAB  &Retira Peca */

      
/***************************************************************************
*
*  Função: TAB  &Insere Peca
*  ****/
   TAB_tpCondRet TAB_InserePeca(TAB_tpTabuleiro * pTabuleiro, void *pPeca, int casa){

	   LIS_tpCondRet CondRet;

	   if (pTabuleiro == NULL)
	   {
		   return TAB_CondRetTabuleiroNaoExiste;
	   }
	   if (casa < 1 || casa > 24)
	   {
		   return TAB_CondRetCasaNaoExiste;
	   }
	   
	   IrInicioLista(pTabuleiro->pBaseDoTabuleiro);
	   LIS_AvancarElementoCorrente(pTabuleiro->pBaseDoTabuleiro, casa - 1);
	   
	   pTabuleiro->pCasaCorr = (LIS_tppLista )LIS_ObterValor(pTabuleiro->pBaseDoTabuleiro);

	   CondRet = LIS_InserirElementoApos(pTabuleiro->pCasaCorr, pPeca);

	   if (CondRet != LIS_CondRetOK)
	   {
		   return TAB_CondRetFaltouMemoria;
	   }

	   return TAB_CondRetOK;
   } /* Fim função: TAB  &Insere Peca */


/***************************************************************************
*
*  Função: TAB  &Move Peca
*  ****/

   TAB_tpCondRet TAB_MovePeca(TAB_tpTabuleiro * pTabuleiro, int casa, int qtd_movimentos){

	   TAB_tpCondRet CondRet;
	   void* aux;

	   CondRet = TAB_RetiraPeca(pTabuleiro, &aux, casa);

	   if (CondRet != TAB_CondRetOK)
	   {
		   return CondRet;
	   }
	   3 +
	   CondRet = TAB_InserePeca(pTabuleiro, aux, casa + qtd_movimentos);

	   return CondRet;

   } /* Fim função: TAB  &Move Peca */

   /*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: TAB - Destroi casa
*
***********************************************************************/

   void DestroiCasa(void * pValor)
   {
	   free(pValor);

   } /* Fim função: TAB - Destroi casa */


/*********************************************************************
*
*  $FC Função: TAB - Destroi base
*
***********************************************************************/

   void DestroiBase(void * pValor)
   {
	   pValor = NULL;

   } /* Fim função: TAB - Destroi base */




   /********** Fim do módulo de implementação: TAB  Modulo Tabuleiro **********/

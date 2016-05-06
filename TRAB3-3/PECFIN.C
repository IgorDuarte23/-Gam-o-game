/***************************************************************************
*
*  $MCD Módulo de implementação: PFN  Peças finalizadas
*
*  Arquivo gerado:              PECFIN.c
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00    idm    20/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*      Implementa as listas para armazenar as peças finalizadas
*      As listas de Finalizadas são estaticas no modulo e só podem existir duas listas.
*      A estrutura possui uma cabeça encapsulando o seu estado.
*
***************************************************************************/
#define PECFIN_OWN
#include "PECFIN.H"
#undef PECFIN_OWN
#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: PFN Descritor das peças finalizadas
*
*
***********************************************************************/

   typedef struct Pecas_Finalizadas {

	   LIS_tppLista pFinalizadasUm;
	   /* Ponteiro para a cabeca da primeira lista de Finalizadas */

	   LIS_tppLista pFinalizadasDois;
	   /* Ponteiro para a cabeca da segunda lista de Finalizadas */

   } PFN_tpPecasFinalizadas;

   
/***** Protótipos das funções encapuladas no módulo *****/

   
   void DestruirPecasFinalizadas(void * pValor);


/***************************************************************************
*
*  Função: PFN  &Criar lista de peças finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tpPecasFinalizadas ** pPecasFinalizadas, int indice){
	   
	   if (pPecasFinalizadas[indice] != NULL)
		   return PFN_CondRetEstruturaJaExiste;

	   pPecasFinalizadas[indice] = (PFN_tpPecasFinalizadas *)malloc(sizeof(PFN_tpPecasFinalizadas ));
	   if (pPecasFinalizadas[indice] == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas[indice]->pFinalizadasUm = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas[indice]->pFinalizadasUm == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas[indice]->pFinalizadasDois = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas[indice]->pFinalizadasDois == NULL)
		   return PFN_CondRetFaltouMemoria;


	   return PFN_CondRetOK;

   } /* Fim função: PFN  &Criar estrutura das listas de finalizadas */


/***************************************************************************
*
*  Função: PFN  &Destruir estrutura que contém lista das peças Finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tpPecasFinalizadas ** pPecasFinalizadas, int indice){

	   if (pPecasFinalizadas == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }
	   if ( pPecasFinalizadas[indice] == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }

	   LIS_DestruirLista(pPecasFinalizadas[indice]->pFinalizadasUm);

	   LIS_DestruirLista(pPecasFinalizadas[indice]->pFinalizadasDois);
	   
	   free(pPecasFinalizadas[indice]);
	   pPecasFinalizadas[indice]->pFinalizadasUm = NULL;
	   pPecasFinalizadas[indice]->pFinalizadasDois = NULL;
	   pPecasFinalizadas[indice] = NULL;
	   
	   return PFN_CondRetOK;
   
   } /* Fim função: PFN  &Destruir estrutura de peças Finalizadas */


/***************************************************************************
*
*  Função: PFN  &Inserir peca finalizada
*
****************************************************************************/

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tpPecasFinalizadas * pPecasFinalizadas, int jogador){

	   LIS_tpCondRet CondRet;
	   
	   if (pPecasFinalizadas == NULL)
	   {
		   return PFN_CondRetEstruturaNaoExiste;
	   }
	   if (jogador != 1 && jogador != 2)
	   {
		   return PFN_CondRetJogadorNaoExiste;
	   }   
	   if (jogador == 1 )
	   {
			CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasUm, NULL);
	   }
	   else
	   {
		   CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasDois, NULL);
	   }
	   if (CondRet != LIS_CondRetOK) // caso nao conseguiu inserir
	   {
		   return PFN_CondRetFaltouMemoria;
	   }
	   return PFN_CondRetOK;

   } /* Fim função: PFN  &inserir peca finalizada*/

   
/***************************************************************************
*
*  Função: PFN  &Contar peca finalizada
*  
***************************************************************************/
   
   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tpPecasFinalizadas * pPecasFinalizadas, int jogador, int *finalizadas){
	   int verificador = 0;
	   LIS_tpCondRet CondRet;
	   CondRet = LIS_CondRetOK;
	   
	   *finalizadas = 0;



	   if (pPecasFinalizadas == NULL)
		   return PFN_CondRetEstruturaNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PFN_CondRetJogadorNaoExiste;
	   	   
	   if (jogador == 1 ){
		  
		  IrInicioLista(pPecasFinalizadas->pFinalizadasUm);
		  
		 	  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente(pPecasFinalizadas->pFinalizadasUm, 1);
				if (CondRet == 1 && verificador == 0)
				{
					return PFN_CondRetListaVazia;
				}
				verificador++;
				(*finalizadas)++;
			  }		
	   }
	   else{
		  
			IrInicioLista(pPecasFinalizadas->pFinalizadasDois);
		  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente(pPecasFinalizadas->pFinalizadasDois, 1);
				if (CondRet == 1 && verificador == 0)
				{
					return PFN_CondRetListaVazia;
				}
			    verificador++;
				(*finalizadas)++;
			  }		
	   }


	   return PFN_CondRetOK;

   } /* Fim função: PFN  &contar peca capturada*/


   
/*****  Código das funções encapsuladas no módulo  *****/

   /********** Fim do módulo de implementação: PFN Peças Finalizadas **********/
/***************************************************************************
*  $MCI Módulo de implementação: PCAP Peças Capturadas
*
*  Arquivo gerado:              PECCAP.C
*  Letras identificadoras:      PCAP
*
*  Nome da base de software:    JOGO DE GAMAO
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: rrvs - Rodrigo Rangel Vargas dos Santos
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      2.0     rrvs   21/09/2015     finalizacao
*      1.0     rrvs   20/10/2015     inicio do modulo
*
***************************************************************************/

#define PCAP_OWN
#include "PECCAP.H"
#undef PCAP_OWN
#include <stdlib.h>

/***********************************************************************
*
*  $TC Tipo de dados: PCAP Descritor da cabeça da Peças Capturadas
*
*
***********************************************************************/

typedef struct PecCap {

	LIS_tppLista PecasCapJ1;

	LIS_tppLista PecasCapJ2;

	int QtdJ1;

	int QtdJ2;

} PCAP_tpPecCap;


/***************************************************************************
*
*  Função: PCAP  &Cria Peças Capturadas
*  ****/
	PCAP_tpCondRet PCAP_CriaPecCap(PCAP_tpPecCap ** pPecCap, int indice) {

		if (pPecCap[indice] != NULL) {
			return PCAP_CondRetEstruturaJaExiste;
		}

		pPecCap[indice] = (PCAP_tpPecCap*)malloc(sizeof(PCAP_tpPecCap));
		if (pPecCap[indice] == NULL) {
			return PCAP_CondRetFaltouMemoria;
		}

		pPecCap[indice]->PecasCapJ1 = LIS_CriarLista(NULL);
		if (pPecCap[indice]->PecasCapJ1 == NULL) {
			return PCAP_CondRetFaltouMemoria;
		}

		pPecCap[indice]->PecasCapJ2 = LIS_CriarLista(NULL);
		if (pPecCap[indice]->PecasCapJ2 == NULL) {
			return PCAP_CondRetFaltouMemoria;
		}

		pPecCap[indice]->QtdJ1 = 0;

		pPecCap[indice]->QtdJ2 = 0;


		return PCAP_CondRetOK;

	}/* Fim função: PCAP  &Cria Peças Capturadas */


 /***************************************************************************
 *
 *  Função: PCAP  &Destroi Peças Capturadas
 *  ****/
	 PCAP_tpCondRet PCAP_DestroiPecasCap(PCAP_tpPecCap ** pPecCap, int indice) {

		 if (pPecCap[indice] == NULL) {
			 return PCAP_CondRetEstruturaNaoExiste;
		 }

		 LIS_DestruirLista(pPecCap[indice]->PecasCapJ1);
		 LIS_DestruirLista(pPecCap[indice]->PecasCapJ2);

		 pPecCap[indice] = NULL;

		 return PCAP_CondRetOK;

	 }/* Fim função: PCAP  &Destroi Peças Capturadas */


/***************************************************************************
 *
 *  Função: PCAP  &Quantidade de Pecas Capturadas
 *  ****/
	 PCAP_tpCondRet PCAP_QuantidadePecasCap(PCAP_tpPecCap * pPecCap, int jogador, int *qtd) {

		 if (pPecCap == NULL) {
			 return PCAP_CondRetEstruturaNaoExiste;
		 }

		 if (jogador == 1) {
			 *qtd = pPecCap->QtdJ1;
		 }
		 else if (jogador == 2) {
			 *qtd = pPecCap->QtdJ2;
		 }
		 else {
			 return PCAP_CondRetJogadorNaoExiste;
		 }

		 return PCAP_CondRetOK;

	 }/* Fim função: PCAP  &Quantidade de Pecas Capturadas */


/***************************************************************************
 *
 *  Função: PCAP  &Retirar peca
 *  ****/
	 PCAP_tpCondRet PCAP_RetiraPeca(PCAP_tpPecCap * pPecCap, void **peca, int jogador) {

		 if (pPecCap == NULL) {
			 return PCAP_CondRetEstruturaNaoExiste;
		 }

		 if (jogador == 1) {

			 if (pPecCap->QtdJ1 == 0)
			 {
				 return PCAP_CondRetListaVazia;
			 }

			 IrFinalLista(pPecCap->PecasCapJ1);
			 *peca = LIS_ObterValor(pPecCap->PecasCapJ1);
			 LIS_ExcluirElemento(pPecCap->PecasCapJ1);
			 pPecCap->QtdJ1--;
		 }
		 else if (jogador == 2) {
			 if (pPecCap->QtdJ2 == 0)
			 {
				 return PCAP_CondRetListaVazia;
			 }

			 IrFinalLista(pPecCap->PecasCapJ2);
			 *peca = LIS_ObterValor(pPecCap->PecasCapJ2);
			 LIS_ExcluirElemento(pPecCap->PecasCapJ2);
			 pPecCap->QtdJ2--;
		 }
		 else {
			 return PCAP_CondRetJogadorNaoExiste;
		 }

		 return PCAP_CondRetOK;

	 }/* Fim função: PCAP  &Retirar peca */


/***************************************************************************
*
*  Função: PCAP  &Insere Peca
*  ****/
	 PCAP_tpCondRet PCAP_InserePeca(PCAP_tpPecCap * pPecCap, int jogador, void * peca) {

		 LIS_tpCondRet CondRet;

		 if (pPecCap == NULL) {
			 return PCAP_CondRetEstruturaNaoExiste;
		 }

		 if (jogador != 1 && jogador != 2) {
			 return PCAP_CondRetJogadorNaoExiste;
		 }

		 if (jogador == 1) {
			 CondRet = LIS_InserirElementoApos(pPecCap->PecasCapJ1, peca);
			 if (CondRet != LIS_CondRetOK)
			 {
				 return PCAP_CondRetFaltouMemoria;
			 }
			 pPecCap->QtdJ1++;
		 }
		 else {
			 CondRet = LIS_InserirElementoApos(pPecCap->PecasCapJ2, peca);
			 if (CondRet != LIS_CondRetOK)
			 {
				 return PCAP_CondRetFaltouMemoria;
			 }
			 pPecCap->QtdJ2++;
		 }

		 return PCAP_CondRetOK;

	 }/* Fim função: PCAP  &Insere Peca */
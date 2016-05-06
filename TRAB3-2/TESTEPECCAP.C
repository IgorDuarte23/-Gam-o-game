/***************************************************************************
*  $MCI Modulo de implementação: TPCAP Teste Peças Capturadas
*
*  Arquivo gerado:              TESTEPECCAP.C
*  Letras identificadoras:      TPCAP
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: rrvs - Rodrigo Rangel Vargas dos Santos
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data         Observações
*     2.00    rrvs     21/09/2015    finalizacao do modulo
*     1.00    rrvs     20/10/2015    inicio da implementacao
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"PECCAP.H"

#define     CRIAR_PECCAP_CMD          "=criapecascap"
#define     DESTRUIR_PECCAP_CMD       "=destroipecascap"
#define     INSERIR_PECA_CMD		  "=inserepeca"
#define     RETIRAR_PECA_CMD		  "=retirapeca"
#define     QUANTIDADE_PECA_CMD		  "=quantidadepeca"

#define  MAX_PECCAP 1


/***********************************************************************
*
*  $FC Função: TTAB &Testar pecas capturadas
*
*  $ED Descrição da função
*     a funçao tem objetivo de testar o modulo PECCAP.C
*
*     Comandos disponíveis:
*
*     =criapecascap				int		condret
*     =destroipecascap			int		condret
*     =inserepeca				int		int		condret
*     =retirapeca				int		int		int		condret
*     =quantidadepeca			int		int		int		condret
*
***********************************************************************/

static tppPecCap pPecCap[MAX_PECCAP];

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste) {

	int numLidos = -1,
		CondRetEsp = -1,
		jogador,
		capturadas,
		capturadasEsperadas,
		inxPeca = -1;

	void * Peca = 0;

	PCAP_tpCondRet CondRet;

	/* testar criar estrutura de pecas capturadas */

	if (strcmp(ComandoTeste, CRIAR_PECCAP_CMD) == 0) {

		numLidos = LER_LerParametros("ii", &inxPeca, &CondRetEsp);

		if (numLidos != 2) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PCAP_CriaPecCap(pPecCap, inxPeca);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao criar estrutura de pecas capturadas.");

	} /* Fim ativa: Testar criar estrutura de pecas capturadas */

	/* Testar destruir estrutura de pecas capturadas */

	else if (strcmp(ComandoTeste, DESTRUIR_PECCAP_CMD) == 0) {

		numLidos = LER_LerParametros("ii", &inxPeca, &CondRetEsp);

		if (numLidos != 2) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PCAP_DestroiPecasCap(pPecCap, inxPeca);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao destruir estrutura de pecas capturadas.");

	} /* Fim ativa: Testar destruir estrutura de pecas capturadas */

	/* Testar inserir peca na lista da estrutura de pecas capturadas */

	else if (strcmp(ComandoTeste, INSERIR_PECA_CMD) == 0) {

		numLidos = LER_LerParametros("iii", &inxPeca, &jogador, &CondRetEsp);

		if (numLidos != 3) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PCAP_InserePeca(pPecCap[inxPeca], jogador, Peca);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao inserir peca na lista.");
	} /* Fim ativa: Testar inserir peca na lista da estrutura de pecas capturadas */

	/* Testar retirar peca da lista da estrutura de pecas capturadas */

	else if (strcmp(ComandoTeste, RETIRAR_PECA_CMD) == 0) {

		numLidos = LER_LerParametros("iii", &inxPeca, &jogador, &CondRetEsp);

		if (numLidos != 3) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PCAP_RetiraPeca(pPecCap[inxPeca], &Peca, jogador);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao retirar peca na lista.");
	} /* Fim ativa: Testar retirar peca da lista da estrutura de pecas capturadas */

	/* Testar obter quantidade de pecas capturadas */

	else if (strcmp(ComandoTeste, QUANTIDADE_PECA_CMD) == 0) {

		numLidos = LER_LerParametros("iiii", &inxPeca, &jogador, &capturadasEsperadas, &CondRetEsp);

		if (numLidos != 4) {
			return TST_CondRetParm;
		} /* if */

		capturadas = 0;
		CondRet = PCAP_QuantidadePecasCap(pPecCap[inxPeca], jogador, &capturadas);

		if (capturadas != capturadasEsperadas && CondRet == 0) {
			CondRet = PCAP_CondRetQuantidadeErrada;
		}

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao obter a quantidade de pecas capturadas.");

	} /* Fim ativa: Testar obter quantidade de pecas capturadas */

	return TST_CondRetNaoConhec;

} /* Fim função: TPFN &Testar pecas capturadas */


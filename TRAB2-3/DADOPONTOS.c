/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo dado pontos
*
*  Arquivo gerado:              DADOPONTOS.C
*  Letras identificadoras:      DADOP
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Igor Duarte Milanez Vieira 1410492
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es 
*	   2.0     idmv   16/09/2015     Finalizacao 
*      1.0     idmv   16/09/2015     Codificacao
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <stdlib.h>
#define DADOP_OWN
#include "DADOPONTOS.H"
#undef DADOP_OWN


/*** Estrutura ***/

typedef struct pontos{
	int pontos;
	int jogador;
}tpDadoP;


 /*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***************************************************************************
*
*  Fun��o: DADO  &Criar dado pontos
*  ****/

DADOP_tpCondRet DADOP_CriaDadoPontos (tpDadoP ** vet,int indice)
{
	if (vet[indice] != NULL)
	{
		return DADOP_CondRetDadoJaFoiCriado;
	}

	vet[indice] = (tpDadoP *) (malloc(sizeof(tpDadoP)));

	if ( vet[indice] == NULL)
	{
		return DADOP_CondRetFaltouMemoria;
	}

	vet[indice]->jogador = 1; // jogador 1
	vet[indice]->pontos = 1; // jogo comeca valendo 1 ponto
	
	return DADOP_CondRetOK;
}

// Fim Funcao Cria DADO PONTOS

/***************************************************************************
*
*  Fun��o: DADO  &Dobra valor
*  ****/


DADOP_tpCondRet DADOP_DobraValor (tpDadoP * tgDados, int jogador_da_vez)
{
	if ( tgDados == NULL)
	{
		return DADOP_CondRetNaoExisteDado;
	}
	
	if (jogador_da_vez != tgDados->jogador)
	{
		return DADOP_CondRetJogadorNaoPodeDobrar;
	}
	else
	{	
		if (tgDados->pontos != 64)
		{
			tgDados->pontos *= 2; // dobro os pontos
			return DADOP_CondRetOK;
		}
		return DADOP_CondRetValorMaximoDaPartida;
	}
}
// Fim Funcao Dobra Valor



/***************************************************************************
*
*  Fun��o: DADO  &Obtem Valor Partida
*  ****/

DADOP_tpCondRet DADOP_ObtemValorPartida (tpDadoP * tgDados,int *valor)
{
	if ( tgDados == NULL)
	{
		return DADOP_CondRetNaoExisteDado;
	}
	*valor = tgDados->pontos;

	return DADOP_CondRetOK;
}
// Fim Funcao ObtemValorPartida


/***************************************************************************
*
*  Fun��o: DADO  &ExcluirDadoPontos
*  ****/

DADOP_tpCondRet DADOP_ExcluiDadoPontos (tpDadoP * tgDados)
{
	if (tgDados == NULL)
	{
		return DADOP_CondRetNaoExisteDado;
	}

	tgDados = NULL;
	free(tgDados);
	return DADOP_CondRetOK;
}

// Fim Funcao ExcluirDadoPontos



/********** Fim do m�dulo de implementa��o: DADOP MANIPULACAO DE DADO PONTOS **********/

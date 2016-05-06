#if ! defined( DADOP_ )
#define DADOP_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo dado pontos
*
*  Arquivo gerado:              DADOPONTOS.H
*  Letras identificadoras:      DADOP
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Igor Duarte
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar uma estrutura.
*     Ao iniciar a execu��o do programa n�o existe nenhum ponto.
*     o ponto nao poder� estar vazio. .
*     os pontos podem ser de 1 ate 64, multiplicando sequenciamente por 2.
*		
***************************************************************************/

#if defined( DADOP_OWN )
   #define DADOP_EXT
#else
   #define DADOP_EXT extern
#endif

/* Tipo referencia para um dado ponto */

typedef struct tpDadoP * tppDadoP;



/***********************************************************************
*
*  $TC Tipo de dados: DADOP Condicoes de retorno
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do dado pontos
*
***********************************************************************/

   typedef enum {

        DADOP_CondRetOK = 0,
		/* executou corretamente */

		DADOP_CondRetDadoJaFoiCriado = 1,
		/* quando tenta criar dois dados */

		DADOP_CondRetFaltouMemoria = 2,
		/* quando nao aloca memoria corretamente */

		DADOP_CondRetNaoExisteDado = 3,
		/* quando tenta manipular um dado q nao foi criado */

		DADOP_CondRetJogadorNaoPodeDobrar = 4,
		/* quando nao e a vez do jogador */

		DADOP_CondRetValorMaximoDaPartida = 5
		/* quando ja esta em 64 e tenta dobrar mesmo assim */

   } DADOP_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: DADOP Criar dado pontos
*
*  $ED Descri��o da fun��o
*     Cria um novo dado pontos 
*    
*
*  $FV Valor retornado
*     DADOP_tpCondRetDadoJaFoiCriado
*     DADOP_tpCondRetFaltouMemoria
*	  DADOP_tpCondRetOK
***********************************************************************/

/* Assertivas de entrada DADOP_CriaDadoPontos
*  Tem que existir mem�ria para cria��o do dado pontos
*  vet[indice] == NULL para a cria��o do DadoP   
*
*
*  Fim Assertivas de Entrada DADOP_CriaDadoPontos */

DADOP_tpCondRet DADOP_CriaDadoPontos (tppDadoP * vet,int indice);

/* Assertivas de Saida DADOP_CriaDadoPontos
* A memoria referente ao vet tem que ser alocada 
* Para todo dado criado vet[indice]->jogador = 1 e vet[indice]->pontos = 1
* A fun��o retornara um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_CriaDadoPontos */

/***********************************************************************
*
*  $FC Fun��o: DADOP Dobra Valor
*
*  $ED Descri��o da fun��o
*    Dobra o valor da partida
*
*  $FV Valor retornado
*     DADOP_tpCondRetNaoExisteDado
*     DADOP_tpCondRetJogadorNaoPodeDobra
*	  DADOP_tpCondRetOK
*	  DADOP_tpCondRetValorMaximoDaPartida
***********************************************************************/

/* Assertivas de entrada DADOP_DobraValor
*  Existe um dado para armazenar o valor da partida (tgDados != NULL)
*  O jogador da vez � o que pode aumentar o valor da partida (jogador_da_vez == tgDados->jogador)
*
*  Fim Aseertivas de Entrada DADOP_DobraValor */


DADOP_tpCondRet DADOP_DobraValor (tppDadoP tgDados, int jogador_da_vez);

/* Assertivas de Saida DADOP_DobraValor
*  O valor foi dobrado
*  A fun��o retornara um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_DobraValor */

/***********************************************************************
*
*  $FC Fun��o: DADOP Obtem Valor da partida
*
*  $ED Descri��o da fun��o
*    Obtem o valor da partida
*
*  $FV Valor retornado
*     DADOP_tpCondRetNaoExisteDado
*	  DADOP_tpCondRetOK
***********************************************************************/

/*Assertivas de entrada DADOP_ObtemValorPartida
* Existe um dado armazenando o valor da partida (tgDados != NULL)
*
*Fim Aseertivas de Entrada DADOP_ObtemValorPartida */


DADOP_tpCondRet DADOP_ObtemValorPartida (tppDadoP tgDados,int *valor);

/* Assertivas de Saida DADOP_ObtemValorPartida
* O valor da partida � passado por parametro para a variavel valor
* A fun��o retorna um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_ObtemValorPartida */

/***********************************************************************
*
*  $FC Fun��o: DADOP ExcluiDadoPontos
*
*  $ED Descri��o da fun��o
*    Exclui os pontos
*
*  $FV Valor retornado
*     DADOP_tpCondRetNaoExisteDado
*	  DADOP_tpCondRetOK
***********************************************************************/

/*Assertivas de entrada DADOP_ExcluiDadoPontos
* Existe um dado para ser destru�do (tgDados != NULL)
*
* Fim Aseertivas de Entrada DADOP_ExcluiDadosPontos */


DADOP_tpCondRet DADOP_ExcluiDadoPontos (tppDadoP tgDados);

/* Assertivas de Saida DADOP_ExcluiDadoPontos
* O dado � excluido
* A fun��o retorna um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_ExcluiDadosPontos */



#undef DADOP_EXT

/********** Fim do m�dulo de defini��o: M�dulo dado pontos **********/

#else
#endif
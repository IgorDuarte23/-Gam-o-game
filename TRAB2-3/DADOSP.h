#if ! defined( DADOP_ )
#define DADOP_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo dado pontos
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
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar uma estrutura.
*     Ao iniciar a execução do programa não existe nenhum ponto.
*     o ponto nao poderá estar vazio. .
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
*  $ED Descrição do tipo
*     Condições de retorno das funções do dado pontos
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
*  $FC Função: DADOP Criar dado pontos
*
*  $ED Descrição da função
*     Cria um novo dado pontos 
*    
*
*  $FV Valor retornado
*     DADOP_tpCondRetDadoJaFoiCriado
*     DADOP_tpCondRetFaltouMemoria
*	  DADOP_tpCondRetOK
***********************************************************************/

/* Assertivas de entrada DADOP_CriaDadoPontos
*  Tem que existir memória para criação do dado pontos
*  vet[indice] == NULL para a criação do DadoP   
*
*
*  Fim Assertivas de Entrada DADOP_CriaDadoPontos */

DADOP_tpCondRet DADOP_CriaDadoPontos (tppDadoP * vet,int indice);

/* Assertivas de Saida DADOP_CriaDadoPontos
* A memoria referente ao vet tem que ser alocada 
* Para todo dado criado vet[indice]->jogador = 1 e vet[indice]->pontos = 1
* A função retornara um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_CriaDadoPontos */

/***********************************************************************
*
*  $FC Função: DADOP Dobra Valor
*
*  $ED Descrição da função
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
*  O jogador da vez é o que pode aumentar o valor da partida (jogador_da_vez == tgDados->jogador)
*
*  Fim Aseertivas de Entrada DADOP_DobraValor */


DADOP_tpCondRet DADOP_DobraValor (tppDadoP tgDados, int jogador_da_vez);

/* Assertivas de Saida DADOP_DobraValor
*  O valor foi dobrado
*  A função retornara um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_DobraValor */

/***********************************************************************
*
*  $FC Função: DADOP Obtem Valor da partida
*
*  $ED Descrição da função
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
* O valor da partida é passado por parametro para a variavel valor
* A função retorna um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_ObtemValorPartida */

/***********************************************************************
*
*  $FC Função: DADOP ExcluiDadoPontos
*
*  $ED Descrição da função
*    Exclui os pontos
*
*  $FV Valor retornado
*     DADOP_tpCondRetNaoExisteDado
*	  DADOP_tpCondRetOK
***********************************************************************/

/*Assertivas de entrada DADOP_ExcluiDadoPontos
* Existe um dado para ser destruído (tgDados != NULL)
*
* Fim Aseertivas de Entrada DADOP_ExcluiDadosPontos */


DADOP_tpCondRet DADOP_ExcluiDadoPontos (tppDadoP tgDados);

/* Assertivas de Saida DADOP_ExcluiDadoPontos
* O dado é excluido
* A função retorna um DADOP_CondRet
*
*  Fim Assertiva de Saida DADOP_ExcluiDadosPontos */



#undef DADOP_EXT

/********** Fim do módulo de definição: Módulo dado pontos **********/

#else
#endif
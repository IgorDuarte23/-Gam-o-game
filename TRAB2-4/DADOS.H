#if ! defined ( DADOS_ )
#define DADOS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Dados
*
*  Arquivo gerado:              DADOS.h
*  Letras identificadoras:      DADO
*
*  Nome da base de software:   Jogo de Gamao
*
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	  2.00	  idmv   15/09/2015  Finalizacao
*     1.00    idmv   15/09/2015  Inicio da implementacao
*
*  $ED Descrição do módulo
*     Cria uma estrutura com dois Dado.
*     Destroi uma estrutura com doi Dados.
*     Gera um valor de 1 a 6 para os dados.
*     Cada dado é homogêneo quanto ao tipo dos dados que armazena.
*     Uma estrutura dado armazena DOIS VALORES DE DADO, ou seja, sao
*     dois dados em apenas uma estrutura, isso porque no jogo de gamao,
*     SEMPRE serao jogados dois dados!
***************************************************************************/
 
#if defined( DADOS_OWN )
#define DADOS_EXT
#else
   #define DADOS_EXT extern
#endif



/* Tipo referência para um dado */

typedef struct DADO_tpDado * DADO_tppDado ; 


/***********************************************************************
*
*  $TC Tipo de dados: DADO Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do dado
*
***********************************************************************/
typedef enum	{
		DADO_tpCondRetOK = 0 ,
		// quando da tudo certo

	    DADO_tpCondRetFaltouMemoria   = 1,
		// quando nao aloca a memoria necessaria
   
		DADO_tpCondRetEstruturaVazia  = 2,
		// quando tenta destruir um dado q n existe
	
		DADO_tpCondRetDadoJaExiste    = 3
		// quando tenta criar um dado que ja existe
     
} DADO_tpCondRet;


/***********************************************************************
*
*  $FC Função: DADO  &Criar dado
*
*  $ED Descrição da função
*     Cria um dado de indice i dentro de um vetor
*
*  $EP Parâmetros
*  * vet - vetor de dados
*  indice - indice no qual o dado vai ser criado
*
*  $FV Valor retornado
*     DADO_tpCondRetOK - Se executou corretamente
*     DADO_tpCondRetFaltouMemoria - Se ocorreu falta de memoria
*     DADO_tpCondRetDadoJaExiste - Se ja houver elemento criado no indice dado
*
***********************************************************************/

/* Assertiva de Entrada DADO_CriaDado
*  Existir memoria suficiente para a estrutura DADO_tppDado
*  Para todo vet[indice], vet[indice] == NULL
* 
*  Fim Assertiva de Entrada DADO_CriaDado */

DADO_tpCondRet DADO_CriaDado(DADO_tppDado *  vet, int indice);

/* Assertiva de Saida DADO_CriaDado
*  Memoria foi alocada para vet[indice]
*  vet[indice] != NULL
*  A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_CriaDado */

/***********************************************************************
*
*  $FC Função: DADO  &Destruir dado
*
*  $ED Descrição da função
*     Destroi um dado de indice i dentro de um vetor
*
*  $EP Parâmetros
*  pDado - dado a ser destruido
*
*  $FV Valor retornado
*   DADO_tpCondRetOK - Se executou corretamente
*   DADO_tpCondRetEstruturaVazia - Se o indice dado no vetor for NULL
*
***********************************************************************/

/* Assertiva de Entrada DADO_DestroiDado
*  Tem que haver um dado alocado para ser destruido ( para todo pDado, pDado != NULL)
*
*  Fim Assertiva de Entrada DADO_DestroiDado */

DADO_tpCondRet DADO_DestroiDado (DADO_tppDado  pDado);

/* Assertiva de Saida DADO_DestroiDado
* O dado foi destruido (para todo pDado, pDado = NULL)
* A memoria alocada para pDado tem que ter sido liberada
* A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_DestoiDado */

/***********************************************************************
*
*  $FC Função: DADO  &Gera Valor Dado
*
*  $ED Descrição da função
*     Gera valor de 1 a 6 de um dado de indice i dentro de um vetor
*
*  $EP Parâmetros
*  pDado -  dado a ser excluido
*
*  $FV Valor retornado
*     DADO_tpCondRetEstruturaVazia - Se o dado for igual a null
*     DADO_tpCondRetOK - Se executou corretamente
*	  
*		
***********************************************************************/

/* Assertiva de Entrada DADO_GeraValorDado 
*  Tem que existir um dado criado ( pDado != NULL)
*  pDado->valorDado1 = NULL && pDado->valorDado2 = NULL
*
*  Fim Assertiva de Entrada DADO_GeraValorDado */

DADO_tpCondRet DADO_GeraValorDado (DADO_tppDado  pDado);

/* Assertiva de Saida DADO_GeraValorDado
*  pDado->valorDado1 e pDado->valorDado2 recebem valor aleatorio entre
   1 e 6
*  A funcao retorna um DADO_tpCondRet
*
*  Fim Assertiva de Saida DADO_GeraValorDado */


#undef DADOS_EXT
/********** Fim do módulo de definição: Módulo Dados **********/

#else
#endif

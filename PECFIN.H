#if ! defined( PECFIN_ )
#define PECFIN_
/***************************************************************************
*
*  $MCD Módulo de definição: PFN  Peças finalizadas
*
*  Arquivo gerado:              PECFIN.h
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00    idmv    20/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa as listas para armazenar as peças finalizadas
*     As listas de capturadas são estaticas no modulo, só podem existir duas listas.
*     A estrutura possui uma cabeça encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( PECFIN_OWN )
#define PECFIN_EXT
#else
#define PECFIN_EXT extern
#endif


#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: PFN Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do tabuleiro
*
***********************************************************************/

   typedef enum {

         PFN_CondRetOK = 0,
               /* Concluiu corretamente */

         PFN_CondRetListaVazia = 1,
               /* A lista não contém elementos */
		 
		 PFN_CondRetEstruturaNaoExiste = 2,
               /* A estrutura de peças finalizadas não foi criada */
		 
		 PFN_CondRetFaltouMemoria = 3, 
			   /* Faltou Memoria*/

		 PFN_CondRetJogadorNaoExiste = 4,
			   /* Jogador não existe */

		 PFN_CondRetQuantidadeErrada = 5,
			  /*Quantidade de peças contadas errada*/
		 
	     PFN_CondRetEstruturaJaExiste = 6,
			   
   } PFN_tpCondRet ;
   
/* Typedef para a estrutura encapsulada */

 typedef struct PFN_tpPecasFinalizadas * PFN_tppPecasFinalizadas ;
 

/***********************************************************************
*
*  $FC Função: PFN  &Criar estrutura de peças finalizadas
*
*  $ED Descrição da função
*     Cria uma estrutura para armazenar as peças finalizadas
*	  Ele pode armazenar peças de qualquer tipo
*
*  $FV Valor retornado
*     PFN_CondRetOK - Se executou corretamente a criaçao da estrutura
*	  PFN_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/
 /* Assertivas de Entrada PFN_CriarPecasFinalizadas
*  Ter memoria suficiente para criacao da estrutura de Listas
*  A Estrutura de Listas passada como parâmetro não existe (pPecasFinalizadas[indice] == NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas,int indice);

/* Assertivas de Saida PFN_CriarPecasFinalizadas
*  A memoria referente a estrutura de lista tem que ser alocada
*  Para todo pPecasFinalizadas[indice] criado, pPecasFinalizadas[indice]->pFinalizadasUm != NULL e pPecasFinalizadas[indice]->pFinalizadasDois != NULL
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_CriarPecasFinalizadas */

/***********************************************************************
*
*  $FC Função: PFN  &Destruir estrutura de peças finalizadas
*
*  $ED Descrição da função
*     Destrói a estrutura de peças finalizadas
*
*  $FV Valor retornado
*     PFN_CondRetOK    - destruiu a estrutura sem problemas
*     PFN_CondRetTabuleiroNaoExiste - estrutura nao foi criada
*
***********************************************************************/

   /* Assertivas de Entrada PFN_DestruirPecasFinalizadas
*  Existir uma estrutura de Listas ja criada
*  A Estrutura de Listas passada como parâmetro existe (pPecasFinalizadas[indice] != NULL)
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas,int indice);

   /* Assertivas de Saida PFN_DestruirPecasFinalizadas
*  A memoria referente a estrutura de lista tem que ser excluida ( free(pPecasFinalizadas[indice])
*  pPecasFinalizadas tem que ser NULL
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */


/***********************************************************************
*
*  $FC Função: PFN  &Inserir peca
*
*  $ED Descrição da função
*     insere uma peca na lista correspontente passada como parâmetro
*
*  $EP Parâmetros
*     jogador    - lista onde a peca sera inserida
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu inserir corretamente
*	  PFN_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     PFN_CondRetJogadorNaoExiste - se a lista passada nao faz parte da estrutura de pecas finalizadas
*     PFN_CondRetEstruturaNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*
***********************************************************************/
   /* Assertivas de Entrada PFN_InserirPecasFinalizadas
*  A Estrutura de Listas passada como parâmetro existe (pPecasFinalizadas[indice] != NULL)
*  jogador deve ter valor inteiro de 1 ou 2
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_CriarPecasFinalizadas */

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador);

   /* Assertivas de Saida PFN_InserirPecasFinalizadas
*  A lista referente ao jogador tem que ser incrementada. 
*  se for jogador 1, a lista sera um. se for jogador 2, sera a lista dois.
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */


/***********************************************************************
*
*  $FC Função: PFN  &Contar peca finalizada
*
*  $ED Descrição da função
*		conta quantas peças já foram finalizadas e retorna como parâmetro
*
*  $EP Parâmetros
*     jogador    - lista de onde a peca sera retirada
*	  finalizadas - retorno por referência de quantas peças há na lista
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu retirar corretamente
*     PFN_CondRetJogadorNaoExiste - se o jogador passado nao faz parte do jogo
*     PFN_CondRetEstruturaNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*     PFN_CondRetListaVazia       - se nao houver pecas na lista
*
***********************************************************************/
   /* Assertivas de Entrada PFN_ContarPecaFinalizada
*  A Estrutura de Listas passada como parâmetro existe (pPecasFinalizadas[indice] != NULL)
*  jogador deve ter valor inteiro de 1 ou 2
*  *finalizadas deve ser um ponteiro valido
*  Valem as assertivas estruturais de LDECC.
*
*  Fim Assertivas de Entrada PFN_ContarPecasFinalizadas */

   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador, int *finalizadas);
   
   /* Assertivas de Saida PFN_ContarPecasFinalizadas
*  A lista referente ao jogador tem que ser percorrida incrementando o ponteiro finalizadas. 
*  o ponteiro finalizadas deve conter o numero de pecas referentes a lista referente ao jogador.
*  A funcao retornara um PFN_tpCondRet
*
*  Fim Assertiva de Saida PFN_DestruirPecasFinalizadas */



#undef PFIN_EXT

   /********** Fim do módulo de definição: PFN  peças finalizadas **********/

#else
#endif
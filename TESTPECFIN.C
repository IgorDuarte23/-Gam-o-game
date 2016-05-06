/***************************************************************************
*  $MCI Modulo de implementação: TPFN Teste pecas finalizadas
*
*  Arquivo gerado:              TESPFIN.c
*  Letras identificadoras:      TPFN
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		01	   idmv	  20/10		Início do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"PECFIN.H"


#define     CRIAR_PECASFINALIZADAS_CMD       "=criarpecas"
#define     DESTRUIR_PECASFINALIZADAS_CMD    "=destruirpecas"
#define     INSERIR_PECAFINALIZADA_CMD		  "=inserirpeca"
#define     CONTAR_PECAFINALIZADA_CMD		  "=contarpecas"

#define     MAX_PECAS 1
/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPFN &Testar pecas finalizadas
*
*  $ED Descrição da função
*     a funçao tem objetivo de testar o modulo PECCAP.C
*
*     Comandos disponíveis:
*
*     =criarpecas			indice      condret		  
*     =destruirpecas		indice      condret         
*	  =inserirpeca   		indice		int		  condret
*	  =contarpecas			indice      int	      int	     condret
*
***********************************************************************/

static PFN_tppPecasFinalizadas pPecasFinalizadas[MAX_PECAS];
      

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  int indice,
		  numLidos = -1,
		  CondRetEsp = -1,
		  jogador,
		  finalizadas,
		  finalizadasEsperadas,
		  inxPeca = -1;
		  
	  PFN_tpCondRet CondRet ;
	  TST_tpCondRet Ret;
	     
	  /* testar criar estrutura de pecas finalizadas */

         if ( strcmp( ComandoTeste , CRIAR_PECASFINALIZADAS_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "ii",&inxPeca ,
                       &CondRetEsp) ;

            if  ( numLidos != 2 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PFN_CriarPecasFinalizadas(pPecasFinalizadas,inxPeca);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao criar estrutura de pecas finalizadas.");

         } /* Fim ativa: Testar criar estrutura de pecas finalizadas */

      /* Testar destruir estrutura de pecas finalizadas */

         else if ( strcmp( ComandoTeste , DESTRUIR_PECASFINALIZADAS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii",&inxPeca ,
                       &CondRetEsp) ;

            if (  numLidos != 2 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PFN_DestruirPecasFinalizadas(pPecasFinalizadas,inxPeca);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao destruir estrutura de pecas finalizadas.");

         } /* Fim ativa: Testar destruir estrutura de pecas finalizadas  */

	  /* Testar inserir peca na estrutura de pecas finalizadas*/

		 else if (strcmp(ComandoTeste, INSERIR_PECAFINALIZADA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",&inxPeca,
				  &jogador, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = PFN_InserirPecaFinalizada (pPecasFinalizadas[inxPeca],jogador);


			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao inserir peca na estrutura de pecas finalizadas.");

		 } /* Fim ativa: Testar inserir peca na estrutura de pecas finalizadas */

	  /* Testar retirar peca da estrutura de pecas finalizadas */

		 else if (strcmp(ComandoTeste, CONTAR_PECAFINALIZADA_CMD) == 0)
		 {	
			 
			 numLidos = LER_LerParametros("iiii",&inxPeca,
				 &jogador, &finalizadasEsperadas, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } /* if */

			 finalizadas = 0;
			 CondRet = PFN_ContarPecaFinalizada(pPecasFinalizadas[inxPeca],jogador, &finalizadas);

			 if(finalizadasEsperadas != finalizadas && CondRet == 0)
				 CondRet = PFN_CondRetQuantidadeErrada;

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao contar pecas da estrutura de pecas finalizadas.");

		 } /* Fim ativa: Testar retirar peca da estrutura de pecas finalizadas */

	 

      return TST_CondRetNaoConhec ;

   } /* Fim função: TPFN &Testar pecas finalizadas */


/*****  Código das funções encapsuladas no módulo  *****/


/********** Fim do módulo de implementação: TPFN Teste pecas finalizadas **********/
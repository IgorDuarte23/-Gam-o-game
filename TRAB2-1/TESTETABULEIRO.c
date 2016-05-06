/***************************************************************************
*  $MCI Modulo de implementação: TTAB Teste tabuleiro
*
*  Arquivo gerado:              TESTETABULEIRO.c
*  Letras identificadoras:      TTAB
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: idmv - Igor Duarte Milanez Vieira
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data         Observações
*     2.00    idmv     22/09/2015    finalizacao do modulo
*     1.00    idmv     20/09/2015    inicio da implementacao
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"TABULEIRO.H"


#define     CRIAR_TABULEIRO_CMD       "=criatabuleiro"
#define     DESTRUIR_TABULEIRO_CMD    "=destroitabuleiro"
#define     INSERIR_PECA_CMD		  "=inserepeca"
#define     RETIRAR_PECA_CMD		  "=retirapeca"
#define     MOVER_PECA_CMD		      "=movepeca"
#define     QUANTIDADE_PECA_CMD		  "=quantidadepeca"


#define  MAX_TABULEIROS 1 


/* VETOR DE TABULEIROS COM APENAS ESPACO PARA UM TABULEIRO*/

tppTabuleiro  pTabuleiro[MAX_TABULEIROS];



/***********************************************************************
*
*  $FC Função: TTAB &Testar tabuleiro
*
*  $ED Descrição da função
*     a funçao tem objetivo de testar o modulo TABULEIRO.C
*
*     Comandos disponíveis:
*
*     =criatabuleiro				int		condret  
*     =destroitabuleiro				int		condret     
*     =inserepeca				int		int		int		condret
*     =retirapeca				int		int		int		condret
*     =movepeca					int		int	        int		condret
*     =quantidadepeca				int		int		int		condret
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  int indice,
	      numLidos = -1,
	      CondRetEsp = -1,
	      indicePeca,
	      casa,
	      passos,
	      quantidadePecasEsp,
	      quantidadePecas,
	      inxTab = -1;

	  void * valorPeca;

	  int * vtPeca[10];

	  TST_tpCondRet Ret;
	  TAB_tpCondRet CondRet ;

	  for (indice = 0; indice < 10; indice++){

		  vtPeca[indice] = (int*)malloc(sizeof(int));
		  if (vtPeca == NULL)
		  {
			  return TST_CondRetMemoria;

		  } 

		  *vtPeca[indice] = indice;
		  

	  } 

      
      /* Testar Criar Tabuleiro */
         if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "ii" ,&inxTab, &CondRetEsp) ;

            if  ( numLidos != 2 ) {
               return TST_CondRetParm ;
            } 

			CondRet = TAB_CriaTabuleiro(pTabuleiro,inxTab);

           return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada ao criar tabuleiro.");

         } /* Fim ativa: Testar criar um tabuleiro */

      /* Testar Destroi Tabuleiro */
         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,&inxTab, &CondRetEsp) ;

            if (  numLidos != 2 ) {
               return TST_CondRetParm ;
            } 

			CondRet = TAB_DestroiTabuleiro(pTabuleiro,inxTab);
			free(pTabuleiro[inxTab]);
			pTabuleiro[inxTab] = NULL;

           return TST_CompararInt( CondRetEsp , CondRet , "Condicao de retorno errada ao destruir tabuleiro.");

         } /* Fim ativa: Destroi Tabuleiro */
		 
		 /* Testar inserir peca */
		 else if (strcmp(ComandoTeste, INSERIR_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iiii",&inxTab, &indicePeca, &casa, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } 

			 CondRet = TAB_InserePeca(pTabuleiro[inxTab],vtPeca[indicePeca], casa);

			 return TST_CompararInt(CondRetEsp, CondRet, "Condicao de retorno errada ao inserir peca.");
		 } /* Fim ativa: Testar inserir peca  */

	  /* Testar Retirar Peca */
		 else if (strcmp(ComandoTeste, RETIRAR_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iiii",&inxTab, &indicePeca, &casa, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } 

			 CondRet = TAB_RetiraPeca(pTabuleiro[inxTab],&valorPeca, casa);	

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao retirar peca.");
		 } /* Fim ativa: Testar Retirar Peca  */

	  /* Testar Mover Peca */
		 else if (strcmp(ComandoTeste, MOVER_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iiii",&inxTab, &casa, &passos, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } 

			 CondRet = TAB_MovePeca(pTabuleiro[inxTab],casa, passos);

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao mover peca.");
		 } /* Fim ativa: Testar Mover Peca  */

	  /* Testar Quantidade Peca */
		 else if (strcmp(ComandoTeste, QUANTIDADE_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iiii",&inxTab, &casa, &quantidadePecasEsp, &CondRetEsp);

			 if (numLidos != 4) {
				 return TST_CondRetParm;
			 } 

			 CondRet =TAB_QuantidadePecasCasa(pTabuleiro[inxTab],casa, &quantidadePecas);

			 Ret = TST_CompararInt(CondRetEsp, CondRet, "Condicao de retorno errada ao contar peca.");

			 if (Ret != TST_CondRetOK)
				 return Ret;

			 return TST_CompararInt(quantidadePecasEsp, quantidadePecas, "numero de pecas errado");

		 } /* Fim ativa: Testar Quantidade Peca  */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TTAB &Testar tabuleiro */

/********** Fim do módulo de implementação: TTAB Teste Modulo Tabuleiro **********/

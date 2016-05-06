/***************************************************************************
*  $MCI Módulo de implementação: TDADO Teste  dado pontos
*
*  Arquivo gerado:              TESTDADOPONTOS.c
*  Letras identificadoras:      DADOP
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: Igor Duarte
*
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    <stdlib.h>
#include    "DADOPONTOS.H"
#include    "TST_Espc.h"

#include    "GENERICO.H"

#include    "LERPARM.H"


static const char CRIAR_DADOP_CMD          [ ] = "=criardadop"     ;
static const char DESTRUIR_DADOP_CMD       [ ] = "=destruirdadop"  ;
static const char OBTER_VALOR_CMD          [ ] = "=obtervalor"     ;
static const char DOBRA_VALOR_CMD          [ ] = "=dobravalor"     ;

#define MAX_DADOS 1

/***********************************************************************
*
*  $FC Função: TDADO &Testar dado
*
*  $ED Descrição da função
*     Cria um dado ponto
*
*     Comandos disponíveis:
*
*     
*       
*     =criardadop                        CondRetEsp
*     =destruirdadop                     CondRetEsp
*     =obtervalor                        CondRetEsp
*	  =dobravalor						 NumJogador CondRetEsp
*
***********************************************************************/

/**********************************************************************
* 
*         Vetor de dados
*
***********************************************************************/
tppDadoP  vtDado[MAX_DADOS];


/***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	   
      int inxDado  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;
	  int CondRetObtido = -1;  
     int ValEsp = -1 ;
      int numElem = -1 ;
	  int * valor = 0;
	  int jogador = -1;
      /* Testar Criar */

          if ( strcmp( ComandoTeste , CRIAR_DADOP_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,&inxDado, &CondRetEsp) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            } 
            CondRetObtido = DADOP_CriaDadoPontos(vtDado,inxDado) ;
            
            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");
            

         } /* fim ativa: Testar Criar */

      /* Testar Destruir  */

         else if ( strcmp( ComandoTeste , DESTRUIR_DADOP_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,&inxDado, &CondRetEsp) ;

            if ( numLidos != 2 )
            {
               return TST_CondRetParm ;
            } 

            CondRetObtido = DADOP_ExcluiDadoPontos( vtDado[inxDado] ) ;
            vtDado[inxDado]= NULL;
			
            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");


         } /* fim ativa: Testar   */

      /* Testar obter valor */

         else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,&inxDado, &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = DADOP_ObtemValorPartida( vtDado[inxDado], valor ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao obter valor." ) ;

         } /* fim ativa: Testar obter valor */

		 /* testar dobrar valor */

         else if ( strcmp( ComandoTeste , DOBRA_VALOR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,&inxDado, &jogador , &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = DADOP_DobraValor( vtDado[inxDado] , jogador ) ;
			
            return TST_CompararInt( CondRetEsp , CondRetObtido ,
                     "Condicao de retorno errada ao dobrar valor." ) ;

         } /* fim ativa: Testar dobrar valor */


      return TST_CondRetNaoConhec ;

   } /* Fim função: TLIS &Testar dado pontos */

/********** Fim do módulo de implementação: TLIS Teste lista de símbolos **********/

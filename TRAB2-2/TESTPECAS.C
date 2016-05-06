/***************************************************************************
*  $MCI Módulo de implementação: TPEC Teste Pecas
*
*  Arquivo gerado:              TestePecas.c
*  Letras identificadoras:      TPEC
*
*  Nome da base de software:    Jogo de Gamão
*
*  Projeto: INF 1301 / 1628 
*  Gestor:  LES/DI/PUC-Rio
*  Autores: gac - Gabriel de Araujo Carvalho
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações 
*      2.0     gac   16/09/2015     finalizacao
*      1.0     gac   15/09/2015     inicio do modulo	
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>
#include    <stdlib.h>
#include    "PECAS.h"

#include	"TST_ESPC.H"

#include    "GENERICO.H"

#include    "LERPARM.H"


#define MAX_PECS 24


/***********************************************************************
*
*  $FC Função: TPEC &Testar PEC
*
*  $ED Descrição da função
*     Testar as funções do módulo Peça
*
*     Comandos disponíveis:
*     
*       
*     =criarPEC               VetorPECs      inxPEC    Cor	CondRetEsp
*     =destruirPEC            PEC            inxPEC         CondRetEsp
*     =obtercor               PEC	         inxPEC         CondRetEsp
*
***********************************************************************/


static const char CRIAR_PEC_CMD          [ ] = "=criarPEC"     ;
static const char DESTRUIR_PEC_CMD       [ ] = "=destruirPEC"  ;
static const char OBTER_COR_CMD          [ ] = "=obtercor"      ;


/**********************************************************************
* 
*         Vetor de PECAS
*
***********************************************************************/

 tppPeca  vtPEC[MAX_PECS];

  
/***********************************************************************/


TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
	   
      int inxPEC  = -1 ;
      int numLidos   = -1 ;
      int CondRetEsp = -1  ;
	  int CondRetObtido = -1;  
      int ObtemCor; 
	  int Cor;
      int ValEsp = -1 ;
      int numElem = -1 ;
      tppPeca *p; 
      
      /* Testar Criar PEC */
          if ( strcmp( ComandoTeste , CRIAR_PEC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" , &inxPEC , &Cor, &CondRetEsp) ; 

            if (  numLidos != 3 )
            {
               return TST_CondRetParm ;
            } 
            CondRetObtido =PEC_criaPEC(vtPEC, inxPEC, Cor) ;
	
            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");
         } /* fim ativa: Testar Criar PEC */


      /* Testar Destruir PEC */
         else if ( strcmp( ComandoTeste , DESTRUIR_PEC_CMD ) == 0 )
         {

            numLidos = LER_LerParametros("ii", &inxPEC, &CondRetEsp) ;  

            if ( numLidos != 2 ) 
            {
               return TST_CondRetParm ;
            } 

            CondRetObtido = PEC_DestroiPEC(vtPEC,inxPEC) ;
            p = NULL;

            return TST_CompararInt (CondRetEsp,CondRetObtido,"Retorno errado");
         } /* fim ativa: Testar Destruir PEC */


      /* Testar Obter Cor */
         else if ( strcmp( ComandoTeste , OBTER_COR_CMD ) == 0 )
         {

            numLidos = LER_LerParametros("ii", &inxPEC, &CondRetEsp ) ;

            if (  numLidos != 2 )
            {
               return TST_CondRetParm ;
            }


            CondRetObtido = PEC_Obtemcor(vtPEC[inxPEC], &ObtemCor) ;

            return TST_CompararInt( CondRetEsp , CondRetObtido , "Retorno Errado." ) ;
         } /* fim ativa: Testar obter cor */


      return TST_CondRetNaoConhec ;
   } /* Fim função: TPEC &Testar PEC */



/********** Fim do módulo de implementação: TPEC Teste PEC **********/


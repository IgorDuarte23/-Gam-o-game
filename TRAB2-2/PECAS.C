/***************************************************************************
*  $MCI Módulo de implementação: Módulo Peças
*
*  Arquivo gerado:              PECAS.C
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo De Gamão
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: gac - Gabriel de Araujo Carvalho
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações 
*      2.0     gac   16/09/2015     finalizacao
*      1.0     gac   15/09/2015     inicio do modulo	
*
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"PECAS.H"
#define PECAS_OWN
#undef PECAS_OWN


/***Estruturas***/
typedef struct peca{
	int cor;
}tpPec;


 
/***************************************************************************
*
*  Função: PEC  &Criar PEC
*  ****/
PEC_tpCondRet PEC_criaPEC(tpPec **p,int ind, int cor){

	if(p[ind]!=NULL)
		return PEC_CondRetPECJaExiste;

	p[ind] = (tpPec*)malloc(sizeof(tpPec));

	if(p[ind]==NULL){
		return PEC_CondRetFaltaMemoria;
	}

	if(cor!=0&&cor!=1)
		return PEC_CondRetCorNaoVale;

	p[ind]->cor=cor;

	return PEC_CondRetOK;
}
/**************** FIM FUNCAO Criar PEC ************************************/


/***************************************************************************
*
*  Função: PEC  &Destroi PEC
*  ****/
PEC_tpCondRet PEC_DestroiPEC(tpPec **p , int ind){

	if(p[ind]!=NULL)
	{
	  p[ind] = NULL;
	  free(p[ind]);
	}
	else
	    return PEC_CondRetPECNaoExiste;

	return PEC_CondRetOK;
}
/******************** FIM FUNCAO Destroi PEC ****************/


/***************************************************************************
*
*  Função: PEC  &Obtem Cor
*  ****/
PEC_tpCondRet PEC_Obtemcor(tpPec *p, int *obtemcor){

	if(p==NULL)
		return PEC_CondRetPECNaoExiste;

	*obtemcor=p->cor;

	return PEC_CondRetOK;
}
/*************** FIM FUNCAO Obtem Cor ***********************************/


/********** Fim do módulo de implementação: PEC Módulo PECAS **********/

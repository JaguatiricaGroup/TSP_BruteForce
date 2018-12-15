//gera cidades para o trabalho de Ia

#include "mapa.h"
#include <stdlib.h>
#include <stdio.h>
/*#include "leFila.h"*/
#include <math.h>
#define ModuloDist(x,x1,y,y1) (sqrt((pow(((x) - (x1)),(2))) + pow(((y) - (y1)),(2))))
#define temEstrada(x) rand()%x //funcao de probabilidade de ter caminho//tentar melhorar a cance de caminho entre proximas

static Mapa* alocaMapa(unsigned xTotal,unsigned yTotal,unsigned numeroCidades){
    Mapa* mapa = malloc(sizeof(Mapa));
    mapa->numeroCidades = numeroCidades;
    mapa->yTotal = yTotal;
    mapa->xTotal = xTotal;
    /*mapa->cidades = malloc(sizeof(Cidade)*numeroCidades);*/
    mapa->distancias = malloc(sizeof(double)*(numeroCidades-1));
    for (int i = 0; i < mapa->numeroCidades; ++i) {
        mapa->distancias[i]  = malloc(sizeof(double)*(i+1));
    }
    return mapa;
}

static Cidade geraCidade(Mapa* m){
    Cidade cidade ;//= alocaCidade();
    cidade.y = (rand())% m->yTotal;    
    cidade.x = (rand())% m->xTotal;
    return cidade;
}

Mapa* geraMapa(unsigned int xTotal, unsigned int yTotal, unsigned int numeroCidades){
    Mapa* L = alocaMapa(xTotal,yTotal,numeroCidades);
    L->numeroCidades = numeroCidades;
    L->yTotal = yTotal;
    L->xTotal = xTotal;
    Cidade *cidades = malloc(sizeof(Cidade)*numeroCidades);

    for (int i = 0; i < L->numeroCidades; ++i) {
        cidades[i] = geraCidade(L);
    }

    for (int i = 0; i < L->numeroCidades; ++i) {//parte superior ficam as distancias retas
        for (int j = 0; j <=i; ++j) { 
             L->distancias[i][j] = (double) ModuloDist(cidades[i].x,cidades[j].x,cidades[i].y,cidades[j].y);
        }
    }	
    free(cidades);
    return L;
}

void printDistancias(Mapa *L){
    printf("imprimindo matriz de distancias\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        printf("   %6d  ",i);//L->distancias[i][j]) ;
    }
    printf("\n");
    for (int i = 0; i < L->numeroCidades; ++i) {
        /*printf("Cidade %d :",i );*/
        printf("%3d ",i);
        for (int j = 0; j < L->numeroCidades; ++j) {
           printf("(%8.2d) ",distancia(L,i,j));//L->distancias[i][j]) ;
           /*printf("%d->(%.2f) ",j,L->distancias[i][j]) ;*/
        }
        printf("\n");
    }

}

unsigned distancia(Mapa *L,unsigned i, unsigned j){
    if(i > j)
	return L->distancias[i][j];
    else
	return L->distancias[j][i];
}

unsigned calculaCusto(Mapa* M, unsigned *permutacao, int gerandoInstancia){
	unsigned custo = 0;
	/*if (permutacao == NULL || M == NULL){*/
		/*printf("nad weqwea");*/
		/*exit(2);*/
	/*}*/
	for (int i = 1 ; i < M->numeroCidades; i++ ){
		custo+= distancia(M, permutacao[i-1]-1, permutacao[i]-1);
		/*printf("(%d->%d) %d -+- ", permutacao[i-1]-1,permutacao[i]-1, custo);*/
	}
	custo+= distancia(M, permutacao[0]-1, permutacao[M->numeroCidades-1]-1);
		/*printf("(%d->%d) %d \n ", permutacao[M->numeroCidades-1]-1,permutacao[0]-1, custo);*/
	/*if (gerandoInstancia){*/
		/*printf("custoCicloHam: %d\n", custo);*/
	/*}*/
	return custo;
}


/*void instanciaSat(Mapa* M, unsigned *permutacao, unsigned custoMin){*/
	/*FILE *fp= fopen("instancia", 'a');*/
	/*unsigned custo = 0;*/
	/*for (int i = 1 ; i < M->numeroCidades; i++ ){		*/
		/*[>custo+= distancia(M, permutacao[i-1]-1, permutacao[i]-1);<]*/
		/*[>printf(fp,"%d, %d", custo, custoMin);		<]*/
	/*}*/
	/*custo+= distancia(M, permutacao[0]-1, permutacao[M->numeroCidades-1]-1);*/

	/*fprintf(fp,"%d, %d", custo, custoMin);		*/
		/*[>printf("(%d->%d) %d \n ", permutacao[M->numeroCidades-1]-1,permutacao[0]-1, custo);<]*/


/*}*/

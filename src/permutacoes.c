// algoritmos para fazer a permutacao de vetores e calcular custo da solucao
//

#include <stdlib.h>
#include <stdio.h>
#include "permutacoes.h"

 
#define LEFT_TO_RIGHT  1
#define RIGHT_TO_LEFT  0
 

// encontra maior posicao movel no vetor de permutacoes
unsigned searchArr(unsigned permutacao[], unsigned n, unsigned mobile)
{
    for (unsigned i = 0; i < n; i++)
        if (permutacao[i] == mobile)
           return i + 1;
}

//funcao para fazer a troca entre inteiros do vetor
void swap(unsigned* a, unsigned* b){
	unsigned auxiliar = *a;
	*a = *b;
	*b = auxiliar;
}
 

// encontra maior valor movel
unsigned getMobile(unsigned permutacao[], unsigned dir[], unsigned n)
{
    unsigned mobile_prev = 0, mobile = 0;
    for (unsigned i = 0; i < n; i++)
    {
        // direction 0 represents RIGHT TO LEFT.
        if (dir[permutacao[i]-1] == RIGHT_TO_LEFT && i!=0)
        {
            if (permutacao[i] > permutacao[i-1] && permutacao[i] > mobile_prev)
            {
                mobile = permutacao[i];
                mobile_prev = mobile;
            }
        }
 
        // direction 1 represents LEFT TO RIGHT.
        if (dir[permutacao[i]-1] == LEFT_TO_RIGHT && i != n-1)
        {
            if (permutacao[i] > permutacao[i+1] && permutacao[i] > mobile_prev)
            {
                mobile = permutacao[i];
                mobile_prev = mobile;
            }
        }
    }
 
    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}




// acha uma permutacao a partir dos estados moveis e da permutacao
unsigned printOnePerm(unsigned permutacao[], unsigned dir[], unsigned n){
    unsigned mobile = getMobile(permutacao, dir, n);
    unsigned pos = searchArr(permutacao, n, mobile);
 
    // trocando de acordo com a direcao
    if (dir[permutacao[pos - 1] - 1] ==  RIGHT_TO_LEFT)
       swap(permutacao+(pos-1), permutacao+(pos-2));
 
    else if (dir[permutacao[pos - 1] - 1] == LEFT_TO_RIGHT)
       swap(permutacao+(pos), permutacao+pos-1);
 
    // trocando a direcao para elementos maiores do que o maior movel
    for (unsigned i = 0; i < n; i++)
    {
        if (permutacao[i] > mobile)
        {
            if (dir[permutacao[i] - 1] == LEFT_TO_RIGHT)
                dir[permutacao[i] - 1] = RIGHT_TO_LEFT;
            else if (dir[permutacao[i] - 1] == RIGHT_TO_LEFT)
                dir[permutacao[i] - 1] = LEFT_TO_RIGHT;
        }
    }
}

// calula a permutacao circular
unsigned fact(unsigned n)
{
    unsigned x = 1;
    for (unsigned i = 1; i <= n; i++)
        x = x * i;
    return x;
}

void printPerm(unsigned perm[], int n){
	
	for( int i =0; i<n ; i++ ){
		printf("%d ", perm[i]);
	}
	printf("\n");
}

//gera as permutacoes custo compara e devolve a melhor
void permutateAndReturnCost(Mapa* m, unsigned n, int gerandoInstancia)
{
    clock_t start = clock();
    // guarda permutacao
    unsigned permutacao[n];
    //salva melhor permytacao
    /*unsigned *melhorPermutacao = malloc(sizeof(unsigned)*n);*/
 
    // Guarda direcoes
    unsigned dir[n];
    double melhorCustoPerm = 0;	
    // gera primeira permutacao
    for (unsigned i = 0; i < n; i++)
    {
        permutacao[i] = i+1;

    }
    melhorCustoPerm = calculaCusto(m, permutacao, gerandoInstancia);
    unsigned k = 1;

    // poe todas direcoes para Right to Left
    for (unsigned i = 0; i < n; i++) // partindo do 1
        dir[i] =  RIGHT_TO_LEFT;
 
    unsigned numPerm =  fact(n-1);
    for (unsigned i = 1; i < numPerm; i++){
        printOnePerm(permutacao, dir, n-1); // mantem ultimo fixo para permutacao circular
	    /*printf("vou calcular custo");*/
	    /*fflush(stdout);*/
	/*printPerm(permutacao, n);*/
	    double custo = 0;
	 custo =calculaCusto(m, permutacao, gerandoInstancia); 
	    if (melhorCustoPerm > custo) {
	    	melhorCustoPerm = custo;
	    }
	/*printf("\n");*/
	k++;
    }
    clock_t diff = clock() - start;
    double msec =  (double) diff / CLOCKS_PER_SEC;
    printf("numero de nos: %d\nnumero permutacoes analisadas: %d\nmelhor custo: %f\ntempo decorrido: %f s\n", n, k, melhorCustoPerm, msec);
}


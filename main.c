#include <stdio.h>
/*#include "src/mapa.h"*/
/*#include <math.h>*/
#include <stdlib.h>
#include "src/permutacoes.h"

int main(int argc, char *argv[]){
	if (argc<3) {
		printf("help\n passe como argumento o numeroCidades e a seed");
		exit(1);
	}
	int n = atoi(argv[1]);	
	int gerandoInstancia = 0; 
	if (argc > 3 ){
		gerandoInstancia = atoi(argv[3]);// gerando ou nao instancia
	}
	srand(atoi(argv[2]));
	Mapa* m = geraMapa(5000, 5000, n);
//	printDistancias(m);
	permutateAndReturnCost(m, n, gerandoInstancia);
	/*printf("nada");*/
	return 0;
}

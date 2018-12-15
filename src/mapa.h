 /*Gera grafos para o trabalho de Ia*/
typedef struct {
    double x,y;//coordenadas da cidade
    //unsigned *indiceCidadesComCaminhoPara;
    //Fila *indicesCidadesComCaminhoPara;
}Cidade;

typedef struct {
    //Cidade **cidades;
    unsigned **distancias;//melhorar essa matriz na diagonal principal
    unsigned numeroCidades;//numero de Cidades presentes no problema Gerado
    unsigned xTotal,yTotal;// coordenada maxima possivel em x e y
}Mapa;


/*recebe mapa e imprime a matriz de heuristica de distancias*/
void printHeuristicas(Mapa *L);
//Gera uma matriz de adjacencia com todos os vertices conectados e com pesos
Mapa* geraMapa(unsigned int xTotal,unsigned int yTotal, unsigned int numeroCidades);
/*recebe mapa e imprime a matriz de distancias*/
void printDistancias(Mapa *L);
/*recebe cidades e mapa e devolve distancia*/
unsigned distancia(Mapa *L,unsigned i, unsigned j);
/*adaptacao para o problema do caixeiro viajante, calcula custo de um ciclo hamiltoniano*/
unsigned calculaCusto(Mapa* M, unsigned *permutacao, int gerandoInstancia);
//unsigned calculaCusto(Mapa* , unsigned*);
// gera instancias de permutacao para sat do caixeiro
void instanciaSat(Mapa* M, unsigned *permutacao, unsigned custoMin);

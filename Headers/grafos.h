
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <String.h>
#include <math.h>

#define FALSE 0
#define TRUE 1
#define MAIOR 9999999;
typedef int ** Estrutura;

typedef struct{
    int numeroVertices;
    Estrutura mAdjacencia;
}TipoGrafo;

typedef TipoGrafo * TipoApontador;

//AUXILIARES
void leituraArquivo(TipoApontador *apGrafo);
//GRAFOS
void inicializaGrafo(TipoApontador *apGrafo,int numeroVertices);
void exibirEstrutura(TipoApontador *apGrafo);

//Heuristicas de construção
void insercaoVizinhoMaisProximo(TipoApontador *apGrafo, int *caminho);
void insercaoAleatoria(TipoApontador *apGrafo, int *caminho);
int escolhaAleatoria(TipoApontador *apGrafo, int *visitados);

//heuristica de melhoria
void algoritmo2opt(TipoApontador *apGrafo, int *caminho, int * melhorCaminho);
int calculaCustoCaminho(TipoApontador *apGrafo, int *caminho);
void copiarCaminho(TipoApontador *apGrafo, int *caminho, int * melhorCaminho);


//Auxiliares
void exibirCaminho(TipoApontador *apGrafo, int *caminho);
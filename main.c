#include "Headers/grafos.h"


//gcc -o exec main.c ./Sources/grafos.c
//quando criar novos .c add no make
int main(int argc, char const *argv[])
{
    TipoApontador grafo;
    leituraArquivo(&grafo);
    int caminho[grafo->numeroVertices+1];
    int melhorCaminho[grafo->numeroVertices+1];
    exibirEstrutura(&grafo);
    //insercaoVizinhoMaisProximo(&grafo,caminho);
    printf("\n");

    insercaoAleatoria(&grafo,caminho);
    exibirCaminho(&grafo,caminho);
    printf("custo do caminho : %d \n",calculaCustoCaminho(&grafo,caminho));

    printf("\n");
    algoritmo2opt(&grafo,caminho,melhorCaminho);
    exibirCaminho(&grafo,melhorCaminho);

    printf("custo do caminho : %d \n",calculaCustoCaminho(&grafo,melhorCaminho));

    return 0;
}

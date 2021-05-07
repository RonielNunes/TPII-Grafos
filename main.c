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
    for (int i = 0; i < grafo->numeroVertices+1; i++)
    {
        printf("%d ",caminho[i] + 1);
    }

    printf("custo do caminho : %d \n",calculaCustoCaminho(&grafo,caminho));
    
    printf("\n");
    algoritmo2opt(&grafo,caminho,melhorCaminho);
    printf("\n");
    for (int i = 0; i < grafo->numeroVertices+1; i++)
    {
        printf("%d ",melhorCaminho[i] + 1);
    }

    printf("custo do caminho : %d \n",calculaCustoCaminho(&grafo,melhorCaminho));

    return 0;
}

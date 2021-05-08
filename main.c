#include "Headers/grafos.h"


//gcc -o exec main.c ./Sources/grafos.c
//quando criar novos .c add no make
int main(int argc, char const *argv[])
{
    TipoApontador grafo;
    leituraArquivo(&grafo);
 

    int caminho[grafo->numeroVertices+1];
    int melhorCaminho[grafo->numeroVertices+1];
    int melhor[grafo->numeroVertices+1], pior[grafo->numeroVertices+1];
    int custoInicial = 0, custoMelhor,custoMaior = 0;
    int custoTodosCaminhosIniciais[30],custoTodosCaminhosMelhorados[30];

    int desvioPadrao1;
    int desvioPadrao2;
    int desvioPadrao;


    int mediactci;
    int mediactcm;
    int media;


    int somatorio1;
    int somatorio2;

    int ctci;
    int ctcm;

    for (int i = 0; i < 30; i++)
    {
 
        //insercaoVizinhoMaisProximo(&grafo,caminho);
        insercaoAleatoria(&grafo,caminho);
        custoInicial = calculaCustoCaminho(&grafo,caminho);
        custoMaior = custoInicial;
        custoTodosCaminhosIniciais[i] = custoInicial;

        algoritmo2opt(&grafo,caminho,melhorCaminho);
        custoMelhor = calculaCustoCaminho(&grafo,melhorCaminho);
        custoTodosCaminhosMelhorados[i] = custoMelhor;

        if(custoInicial >= custoMaior){
 
            custoMaior = custoInicial;
            copiarCaminho(&grafo,caminho,pior);
        }
        if(custoMelhor >= custoMaior){
            custoMaior = custoMelhor;
            copiarCaminho(&grafo,melhorCaminho,pior);
        }

        if(custoMelhor < custoInicial){
            custoInicial = custoMelhor;
            copiarCaminho(&grafo,melhorCaminho,melhor);
        }
    }
    exibirCaminho(&grafo,melhor);
    escreveArquivo(&grafo,melhor);

    ctci = 0;
    ctcm = 0;

    for (int i = 0; i < 30; i++)
    {
        ctci += custoTodosCaminhosIniciais[i];
        ctcm += custoTodosCaminhosMelhorados[i];
    }

    mediactci = ctci/30;
    mediactcm = ctcm/30;
    media = (mediactcm + mediactci)/2;


    somatorio1 = 0;
    somatorio2 = 0;

    for (int i = 0; i < 30; i++)
    {
        somatorio1 += pow((custoTodosCaminhosIniciais[i] - mediactci),2);
        somatorio2 += pow((custoTodosCaminhosMelhorados[i] - mediactcm),2);
    }
    
    desvioPadrao1 = sqrt(somatorio1/30);
    desvioPadrao2 = sqrt(somatorio2/30);
    desvioPadrao = (desvioPadrao1+desvioPadrao2)/2;
    printf("\n==============================================================\n");
    printf("melhor: %d pior: %d media: %d desviopadrao: %d \n",calculaCustoCaminho(&grafo,melhor),calculaCustoCaminho(&grafo,pior), media, desvioPadrao);
    printf("==============================================================\n");



    return 0;
}

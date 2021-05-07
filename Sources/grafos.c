#include "../Headers/grafos.h"
/* -- IMPLEMENTAÇÃO DAS FUNÇÕES AUXILIARES -- */

//(testeda funcionando)
void leituraArquivo(TipoApontador *apGrafo){
    FILE *arquivo = NULL;
    char nomeArquivoEntrada[30], nomeArquivo[30];
    int numeroVertices;
    int v1,v2,distancia;

    printf("Digite o nome do arquivo: ");
    scanf("%s",nomeArquivoEntrada);

    strcpy(nomeArquivo,"./Arquivos/");
    strcat(nomeArquivo,nomeArquivoEntrada);
   // printf("%s",nomeArquivo);
    arquivo = fopen(nomeArquivo,"r");

    if(arquivo == NULL){
       // printf("Erro na abertura do arquivo.\n");
        return;
    }

    fscanf(arquivo,"%d",&numeroVertices);
 
    inicializaGrafo(&(*apGrafo), numeroVertices);
    
    while (!feof(arquivo))
    {
        fscanf(arquivo,"%d %d %d",&v1,&v2,&distancia);
        (*apGrafo)->mAdjacencia[v1-1][v2-1] = distancia;
       // printf("%d %d %d\n",v1,v2,distancia);
    }
    
    fclose(arquivo);

}

/* -- IMPLEMENTAÇÃOES DAS ESTRUTURA GRADOS -- */

//(testada fuincionado)
void inicializaGrafo(TipoApontador *apGrafo, int numeroVertices)
{
    (*apGrafo) = (TipoGrafo *)malloc(sizeof(TipoGrafo)); //Alocação da estrutura
    (*apGrafo)->numeroVertices = numeroVertices;
 

    (*apGrafo)->mAdjacencia = (int **)calloc(((*apGrafo)->numeroVertices+ 1),sizeof(int*));

    for (int i = 0; i < (*apGrafo)->numeroVertices; i++)
    {
        (*apGrafo)->mAdjacencia[i] = (int *)calloc(((*apGrafo)->numeroVertices+1),sizeof(int));
    }

    for (int i = 0; i < (*apGrafo)->numeroVertices; i++)
    {
        for (int j = 0; j < (*apGrafo)->numeroVertices; j++)
        {
            (*apGrafo)->mAdjacencia[i][j] = 0;
        }
    }
}

//(testada fuincionado)
void exibirEstrutura(TipoApontador *apGrafo)
{
    for (int i = 0; i < (*apGrafo)->numeroVertices; i++)
    {  
        for (int j = 0; j < (*apGrafo)->numeroVertices; j++)
        {
            printf("%d ",(*apGrafo)->mAdjacencia[i][j]);
        }
        puts("");
    }
}
/* -- IMPLEMENTAÇÕES DAS HEURÍSTICAS CONTRUTIVAS --*/

//a) Heurística construtiva Inserção do Vizinho mais Próximo (testado)
//https://www.youtube.com/watch?v=RQpFffcI-ZI lógica
void insercaoVizinhoMaisProximo(TipoApontador *apGrafo, int *caminho)
{
    int visitados[(*apGrafo)->numeroVertices];
    int quantidadeVizitados = (*apGrafo)->numeroVertices;
    int verticeSelecionado = 0;
    int auxVerticeSelecionado = 0;
    int menorDistancia = MAIOR;
    int i;
    int encontrouVerticeValido = FALSE;

    for (i = 0; i < (*apGrafo)->numeroVertices; i++)
    {
        visitados[i] = FALSE;
    }
    
    i = 0;
    while (quantidadeVizitados > 0)
    {
        visitados[verticeSelecionado] = TRUE;
        caminho[i] = verticeSelecionado;
        for (int j = 0; j < (*apGrafo)->numeroVertices; j++)
        {
            if( ((*apGrafo)->mAdjacencia[verticeSelecionado][j] < menorDistancia) && (j != verticeSelecionado) && (visitados[j] == FALSE) )
            {
                menorDistancia =  (*apGrafo)->mAdjacencia[verticeSelecionado][j];
                auxVerticeSelecionado = j;
                encontrouVerticeValido = TRUE;
            }
        }
        i++;
        if(encontrouVerticeValido)
        {
            verticeSelecionado = auxVerticeSelecionado;
        }else
        {
            caminho[i] = 0;
        }
        encontrouVerticeValido = FALSE;
        menorDistancia = MAIOR;
        quantidadeVizitados--;
    }
}

//b) Heurística construtiva Inserção da Aresta mais Barata 
void insercaoAleatoria(TipoApontador *apGrafo, int *caminho)
{
    int candidatos = (*apGrafo)->numeroVertices;
    int visitados[(*apGrafo)->numeroVertices];
    int verticeSelecionado;
    int i;
    for (i = 0; i < (*apGrafo)->numeroVertices; i++)
    {
        visitados[i] = FALSE;
    }
    
    i = 0;
    while (candidatos > 0)
    {

        verticeSelecionado  = escolhaAleatoria(&(*apGrafo),visitados);//Sorteia vertice candidato 
        if(visitados[verticeSelecionado] == FALSE){
            visitados[verticeSelecionado] = TRUE;
            caminho[i] = verticeSelecionado;
            i++;
            candidatos--;
        }
    }
    caminho[(*apGrafo)->numeroVertices] = caminho[0];
}
int escolhaAleatoria(TipoApontador *apGrafo, int *visitados)
{   
    int vertice;
    int achou = -1;
    while(achou == -1)
    {
        vertice = (rand() % ((*apGrafo)->numeroVertices));
        if(visitados[vertice] == FALSE)
        {
            achou = 1;
        }
    }
    return vertice;
}

/* -- IMPLEMENTÇÃO DA HEURÍSTICA DE MELHORIA --*/
void algoritmo2opt(TipoApontador *apGrafo, int *caminho, int * melhorCaminho){
    int caminhoAux[(*apGrafo)->numeroVertices + 1];
    int custoInicial = calculaCustoCaminho((apGrafo),caminho);
    int custoAux;
    int vertice;

    copiarCaminho(&(*apGrafo),caminho,melhorCaminho);
 
    for (int i = 0; i < (*apGrafo)->numeroVertices - 1; i++)
    {
        copiarCaminho(&(*apGrafo),caminho,caminhoAux);
        for (int j = i + 1; j < (*apGrafo)->numeroVertices; j++)
        {
            //permuta os pontos
            vertice = caminhoAux[i+1];
            caminhoAux[i+1] = caminhoAux[j];
            caminhoAux[j] = vertice;
            //exibirCaminho(&(*apGrafo),caminhoAux);
            custoAux = calculaCustoCaminho(&(*apGrafo),caminhoAux);

            if(custoAux < custoInicial){
                custoInicial = custoAux;
                copiarCaminho(&(*apGrafo),caminhoAux,melhorCaminho);
            } 
        }
    }
}
void exibirCaminho(TipoApontador *apGrafo, int *caminho){
    for (int i = 0; i < (*apGrafo)->numeroVertices + 1; i++)
    {
        printf("%d ",caminho[i]+1);
    }
    printf("\n");
}
int calculaCustoCaminho(TipoApontador *apGrafo, int *caminho)
{
    int custoTotal = 0;

    for (int i = 0; i < (*apGrafo)->numeroVertices; i++)
    {
        custoTotal += (*apGrafo)->mAdjacencia[caminho[i]][caminho[i+1]];
    }
    return custoTotal;
}

void copiarCaminho(TipoApontador *apGrafo, int *caminho, int * melhorCaminho){
    for (int i = 0; i < (*apGrafo)->numeroVertices +1; i++)
    {
        melhorCaminho[i] = caminho[i];
    }
}
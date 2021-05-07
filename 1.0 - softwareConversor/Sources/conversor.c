#include "../Headers/conversor.h"

//gcc -o exec main.c ./Sources/conversor.c
void converte(char *nomeArquivo){
    FILE *arquivo = NULL;
    FILE *arquivoSaida = NULL;
    char nomeArquivoEntrada[70], nomeArquivoSaida[70];
    int numeroDeCidades;
    int numeroCidades,verttice, distancia;
    float xi,xj,yi,yj;
    
    strcpy(nomeArquivoEntrada,"./arquivosOriginais/"); 
    strcat(nomeArquivoEntrada,nomeArquivo);
    strcat(nomeArquivoEntrada,".txt");
    printf("%s\n",nomeArquivoEntrada);

    strcpy(nomeArquivoSaida,"./arquivosSaida/");
    strcat(nomeArquivoSaida,nomeArquivo);
    strcat(nomeArquivoSaida,".txt");
    printf("%s\n",nomeArquivoSaida);

    arquivo = fopen(nomeArquivoEntrada,"r");//Abertura do arquivo para read
    arquivoSaida = fopen(nomeArquivoSaida,"w");//Abertura do arquivo para write

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo.\n");
        return;
    }else if(arquivoSaida == NULL){
        printf("Erro na criacao do arquivo de escrita.\n");
    }else{
        printf("Inicializacao de arquivos realizada.\n");
    }
 
    fscanf(arquivo,"%d",&numeroCidades);
    fprintf(arquivoSaida,"%d \n", numeroCidades);
    
    double matriz[numeroCidades][2];

    for (int i = 0; i < numeroCidades; i++)
    {
        fscanf(arquivo,"%d %f %f",&verttice,&xi,&yi);
        matriz[i][0] = xi;
        matriz[i][1] = yi;
    }
    
    for (int i = 0; i < numeroCidades; i++)
    {
        printf("%d %f %f \n",i+1,matriz[i][0],matriz[i][1]);
    }
    
    for (int i = 0; i < numeroCidades; i++)
    {
        for (int j = 0; j < numeroCidades; j++)
        {
            if(i != j){
                distancia = sqrt(pow(matriz[i][0] - matriz[j][0],2) + pow(matriz[i][1]- matriz[j][1],2));
                printf("Distancia de %d a %d = %d\n",i+1,j+1,distancia);
                fprintf(arquivoSaida,"%d %d %d\n",i+1,j+1,distancia);
            }   
        }
    }
    fclose(arquivoSaida);
    fclose(arquivo);
}
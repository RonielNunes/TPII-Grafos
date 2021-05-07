#include "../Headers/conversor.h"

//gcc -o exec main.c ./Sources/conversor.c
void converte(char *nomeArquivo){
    FILE *arquivo = NULL;
    FILE *arquivoSaida = NULL;
    char nomeArquivoEntrada[70], nomeArquivoSaida[70];
 
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

}
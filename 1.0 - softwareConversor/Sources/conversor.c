#include "../Headers/conversor.h"

//gcc -o exec main.c ./Sources/conversor.c
void converte(char *nomeArquivo){
    FILE *arquivo;
    FILE *arquivoSaida;
    char nomeArquivoEntrada[70], nomeArquivoSaida[70];
 
 
    strcpy(nomeArquivoEntrada,"../arquivosOriginais/");
    strcat(nomeArquivoEntrada,nomeArquivo);
    strcat(nomeArquivoEntrada,".txt");
    //printf("%s\n",nomeArquivoEntrada);

    strcpy(nomeArquivoSaida,"../arquivosSaida/");
    strcat(nomeArquivoSaida,nomeArquivo);
    strcat(nomeArquivoSaida,".txt");

    arquivo = fopen(nomeArquivoEntrada,"r");//Abertura do arquivo para read
    arquivoSaida = fopen(nomeArquivoSaida,"w");//Abertura do arquivo para write
}
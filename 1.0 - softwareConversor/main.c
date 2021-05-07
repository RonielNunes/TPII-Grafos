#include "./Headers/conversor.h"

int main(int argc, char const *argv[])
{
 
    char nomeArquivo[30];

    printf("+*-*-*-*-*-*-*-*-*-*-*-*-*-*-*+\n");
    printf("|        CONVERTE ARQUIVO     |\n");
    printf("+*-*-*-*-*-*-*-*-*-*-*-*-*-*-*+\n");

    printf("Digite o nome do arquivo sem extensao: ");
    scanf("%s",nomeArquivo);

    converte(nomeArquivo);
 
    return 0;
}

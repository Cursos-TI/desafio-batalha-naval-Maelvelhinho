#include <stdio.h>

int posicaoLivre(int tabuleiro[10][10], int linha, int coluna) {
    if (linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
        return 0; // Fora do tabuleiro
    }
    return tabuleiro[linha][coluna] == 0;
}

int main (){
    
    int tabuleiro [10][10] = {0};
    int tamanhoNavio = 3;
    int navio1Linha = 5, navio1Coluna = 1, navio2Linha = 7, navio2Coluna = 8,
        navio3Linha = 0, navio3Coluna = 0, navio4Linha = 6, navio4Coluna = 6;

    //Navio 1 horizontal
    for(int i=0; i<tamanhoNavio; i++){
        if(!posicaoLivre(tabuleiro, navio1Linha, navio1Coluna + i)){
            printf("Navio 1 não cabe nesta posição ou sobrepõe outro navio.\n");
            return 1;
        }
    }
    //Navio 2 vertical
    for (int i=0; i<tamanhoNavio; i++){
        if(!posicaoLivre(tabuleiro, navio2Linha +i, navio2Coluna)){
            printf("Navio 2 não cabe nesta posição ou sobrepõe outro navio.\n");
            return 1;
        }
    }
    // Navio 3 (diagonal)
    for (int i = 0; i < tamanhoNavio; i++) {
        if (!posicaoLivre(tabuleiro, navio3Linha + i, navio3Coluna + i)) {
            printf("Navio 3 nao cabe nesta posicao ou sobrepoe outro navio.\n");
            return 1;
        }
    }

    // Navio 4 (diagonal inversa)
    for (int i = 0; i < tamanhoNavio; i++) {
        if (!posicaoLivre(tabuleiro, navio4Linha - i, navio4Coluna + i)) {
            printf("Navio 4 nao cabe nesta posicao ou sobrepoe outro navio.\n");
            return 1;
        }
    }


    //preenchendo o navio 1
    for(int i = 0; i < 3; i++){
        tabuleiro [navio1Linha][navio1Coluna+i] = tamanhoNavio;
    }

    //preenchendo o navio 2
    for(int i = 0; i < 3; i++){
        tabuleiro [navio2Linha+i][navio2Coluna] = tamanhoNavio;
    }

    //preenchendo o navio 3
    for(int i=0; i<3; i++){
        tabuleiro[navio3Linha+i][navio3Coluna+i]=tamanhoNavio;
    }

    //preenchendo o navio 4
    for(int i=0; i<3; i++){
        tabuleiro[navio4Linha - i][navio4Coluna + i] = tamanhoNavio;
    }

    int ataqueCone[10][10]={{0,0,0,0,0,0,1,0,0,0}, {0,0,0,0,0,1,1,1,0,0}, {0,0,0,0,1,1,1,1,1,0},{0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}};
    int ataqueCruz [10][10]={{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,1,0,},
    {0,0,0,0,0,0,0,1,1,1}, {0,0,0,0,0,0,0,0,1,0,},{0,0,0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };
    int ataqueLosango [10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0}, {1,1,1,0,0,0,0,0,0,0}, {0,1,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}};
    int qtd = 0;

    
      
    for(int i=0; i<10; i++){
        for(int j=0;j<10;j++){
            tabuleiro[i][j] += ataqueCone[i][j];
            tabuleiro[i][j] += ataqueCruz[i][j];
            tabuleiro[i][j] += ataqueLosango[i][j];
            }
        }

    
    for(int i=0; i<10; i++){
        for(int j=0;j<10;j++){
            if(tabuleiro[i][j]>=4){
                qtd++;
                printf("Acertou em [%d][%d]\n", i,j); 
            }
        }
    }
    printf("\n");
    printf("Você acertou %d tiros. Confira como ficou o tabuleiro.\n\n", qtd);

    for(int i=0; i<10; i++){
        for(int j=0;j<10;j++){
            printf("%d ",tabuleiro[i][j]);
            }
        printf("\n");    
    }

    return 0;
}
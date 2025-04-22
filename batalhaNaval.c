#include <stdio.h>

int main (){
    
    int tabuleiro [10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    int valor = 3;
    int navio1Linha = 5, navio1Coluna = 1, navio2Linha = 7, navio2Coluna = 8;

    //preenchendo o navio 1
    for(int i = 0; i < 3; i++){
        tabuleiro [navio1Linha][navio1Coluna+i] = valor;
    }

    //preenchendo o navio 2
    for(int i = 0; i < 3; i++){
        tabuleiro [navio2Linha+i][navio2Coluna] = valor;
    }

   
    for(int i=0; i<10; i++){
        for(int j=0;j<10;j++){
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }

 
    return 0;
}
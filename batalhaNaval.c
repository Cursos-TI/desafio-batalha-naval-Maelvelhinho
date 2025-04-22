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
    int navio1Linha = 5, navio1Coluna = 1, navio2Linha = 7, navio2Coluna = 8,
    navio3Linha = 0, navio3Coluna = 0, navio4Linha = 6, navio4Coluna = 6;

    if(navio1Linha+valor>9||navio2Linha+valor>9){
        printf("Navio não cabe nesta posição. Digite um número menor.");
    }else if(navio1Coluna+valor>9||navio2Coluna+valor>9){
        printf("Navio não cabe nesta posição. Digite um número menor.");
    }

    //preenchendo o navio 1
    for(int i = 0; i < 3; i++){
        tabuleiro [navio1Linha][navio1Coluna+i] = valor;
    }

    //preenchendo o navio 2
    for(int i = 0; i < 3; i++){
        tabuleiro [navio2Linha+i][navio2Coluna] = valor;
    }

    //preenchendo o navio 3
    for(int i=0; i<3; i++){
        if((navio3Linha+i)==(navio3Coluna+i)){
            tabuleiro[navio3Linha+i][navio3Coluna+i]=3;
        }
    }

    //preenchendo o navio 4
    for(int i=0; i<3; i++){
        if((navio4Linha - i) >= 0 && (navio4Coluna + i) < 10) {
            tabuleiro[navio4Linha - i][navio4Coluna + i] = valor;
        }
    }


    for(int i=0; i<10; i++){
        for(int j=0;j<10;j++){
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("\n");
    }

 
    return 0;
}
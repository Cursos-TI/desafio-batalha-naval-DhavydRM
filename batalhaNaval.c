#include <stdio.h>

#define LINHA 10
#define COLUNA 10
#define LINHAH 3
#define COLUNAH 5

int main() {
    int tabuleiro[LINHA][COLUNA];
    char letras[LINHA] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    char numeros[COLUNA];
    int cone[LINHAH][COLUNAH], cruz[LINHAH][COLUNAH], octaedro[LINHAH][COLUNAH];

    for (int i = 0; i < LINHAH; i++){ // FOR para criação de Cone
        for (int j = 0; j < COLUNAH; j++){
            switch (i){ // Estrutura para formar o cone
            case 0:
                if (j == 2) {
                    cone[i][j] = 5;
                } else {
                    cone[i][j] = 0;
                }
                break;
            case 1:
                if (j >= 1 && j <= 3) {
                    cone[i][j] = 5;
                }
                break;
            case 2:
                cone[i][j] = 5;
                break;
            default:
                cone[i][j] = 0;
                break;
            }
            printf("%i ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < LINHAH; i++){ // FOR para criação de Cruz
        for (int j = 0; j < COLUNAH; j++){
            switch (i){ // Estrutura para formar a cruz
            case 0:
                if (j == 2) {
                    cruz[i][j] = 5;
                } else {
                    cruz[i][j] = 0;
                }
                break;
            case 1:
                cruz[i][j] = 5;
                break;
            case 2:
                if (j == 2) {
                    cruz[i][j] = 5;
                } else {
                    cruz[i][j] = 0;
                }
                break;
            default:
                cruz[i][j] = 0;
                break;
            }
            printf("%i ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < LINHAH; i++){ // FOR para criação do Octaedro
        for (int j = 0; j < COLUNAH; j++){
            switch (i){ // Estrutura para formar o octaedro
            case 0:
                if (j == 2) {
                    octaedro[i][j] = 5;
                } else {
                    octaedro[i][j] = 0;
                }
                break;
            case 1:
                if (j >= 1 && j <= 3) {
                    octaedro[i][j] = 5;
                }
                break;
            case 2:
                if (j == 2) {
                    octaedro[i][j] = 5;
                } else {
                    octaedro[i][j] = 0;
                }
                break;
            default:
                cruz[i][j] = 0;
                break;
            }
            printf("%i ", octaedro[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < LINHA; i++){ // Primeiro FOR para percorrer as linhas da matriz
        numeros[i] = i;
        if (i != 0) { // Exibe os números das colunas no lado esquerdo
            printf("%i ", numeros[i]);
        } else {
            printf("  ");
        }
        for (int j = 0; j < COLUNA; j++){ // Segundo FOR para percorrer as colunas da matriz
            if (i == 0){ 
                if (j == 0) {
                    for (int k = 0; k < LINHA; k++) { // FOR para adicionar as letras apenas em cima do tabuleiro primeiro
                        printf("%c ", letras[k]);
                }
                    printf("\n");
                    printf("%i ", numeros[i]);
                    tabuleiro[i][j] = 0;
                } else if (j >= 5){ // Condição para adicionar parte da cruz na Linha 0
                    tabuleiro[i][j] = cruz[i][j-5];
                } else {
                    tabuleiro[i][j] = 0;
                }
            } else if (i == 2) { // Difine que haverá um barco nos índices: 2,0 / 2,1 / 2,2
                if (j < 3){
                    tabuleiro[i][j] = 3;
                } else if (j >= 5){ // Condição para adicionar parte da Cruz na linha 2
                    tabuleiro[i][j] = cruz[i][j-5];
                } else {
                    tabuleiro[i][j] = 0;
                }
                
            } else if (i == 1 && j >= 5) {
                tabuleiro[i][j] = cruz[i][j-5]; // Condição para adicionar restante da Cruz na linha 1
            } else if (i >= 7){ // Define que haverá um barco nos índices: 7,9 / 8,9 / 9,9
                if (j == 9){
                    tabuleiro[i][j] = 3;
                } else if (j <= 4) { // Condição para adicionar o Cone do índice 7,0 até 9,4
                    tabuleiro[i][j] = cone[i-7][j];
                } else {
                    tabuleiro[i][j] = 0;
                }
            
            } else if (i >= 4 && i <= 6){
                if (j >= 3 && j <= 7) { // Condição para adicionar o Octaedro do índice 4,3 até 6,7
                    tabuleiro[i][j] = octaedro[i-4][j-3];
                } else {
                    tabuleiro[i][j] = 0;
                }
            } else { // Coloca "água" no restante do tabuleiro
                tabuleiro[i][j] = 0;
            }
            printf("%i ", tabuleiro[i][j]); // Printa o tabuleiro depois de passar pelas condicionais
        }
        printf("\n");
    }
    

    return 0;
}

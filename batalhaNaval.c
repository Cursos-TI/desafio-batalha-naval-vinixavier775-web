#include <stdio.h>

int main() {
    int board[10][10];
    int i, j;

    // Inicializa o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }

    // Posiciona um navio horizontalmente
    int horizontal_start_row = 2;
    int horizontal_start_col = 3;
    for (j = 0; j < 3; j++) {
        board[horizontal_start_row][horizontal_start_col + j] = 3;
    }

    // Posiciona um navio verticalmente
    int vertical_start_row = 5;
    int vertical_start_col = 6;
    for (i = 0; i < 3; i++) {
        board[vertical_start_row + i][vertical_start_col] = 3;
    }
    
    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

// Constantes para o tamanho do tabuleiro e das habilidades
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5

// Definicao das matrizes de habilidades (5x5)
// Area de efeito em forma de cone, apontando para baixo
const int CONE[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

// Area de efeito em forma de cruz
const int CRUZ[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

// Area de efeito em forma de octaedro
const int OCTAEDRO[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

// Matriz do tabuleiro de Batalha Naval
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// Função para inicializar o tabuleiro com zeros
void inicializar_tabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicar_habilidade(const int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    // Calcula o deslocamento do centro da habilidade
    int deslocamento = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                // Calcula as coordenadas do tabuleiro
                int tabuleiro_linha = linha - deslocamento + i;
                int tabuleiro_coluna = coluna - deslocamento + j;

                // Verifica se as coordenadas estao dentro dos limites do tabuleiro
                if (tabuleiro_linha >= 0 && tabuleiro_linha < TAMANHO_TABULEIRO &&
                    tabuleiro_coluna >= 0 && tabuleiro_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[tabuleiro_linha][tabuleiro_coluna] = 1;
                }
            }
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro() {
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == 1) {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Inicializa o tabuleiro
    inicializar_tabuleiro();

    // Define pontos de origem para cada habilidade
    int ponto_origem_cone_linha = 2;
    int ponto_origem_cone_coluna = 5;

    int ponto_origem_cruz_linha = 7;
    int ponto_origem_cruz_coluna = 2;

    int ponto_origem_octaedro_linha = 5;
    int ponto_origem_octaedro_coluna = 7;

    // Aplica as habilidades ao tabuleiro
    aplicar_habilidade(CONE, ponto_origem_cone_linha, ponto_origem_cone_coluna);
    aplicar_habilidade(CRUZ, ponto_origem_cruz_linha, ponto_origem_cruz_coluna);
    aplicar_habilidade(OCTAEDRO, ponto_origem_octaedro_linha, ponto_origem_octaedro_coluna);

    // Imprime o tabuleiro com as areas de efeito marcadas
    printf("Tabuleiro com areas de efeito das habilidades:\n");
    imprimir_tabuleiro();

    return 0;
}

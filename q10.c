#include <stdio.h>

#define FILEIRAS 5
#define CADEIRAS 8

void exibir_teatro(int teatro[FILEIRAS][CADEIRAS]) {
    printf("\n   Mapa do Teatro (0: Livre, 1: Ocupado):\n");
    printf("        Cadeiras: ");
    for (int j = 1; j <= CADEIRAS; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < FILEIRAS; i++) {
        printf("Fileira %d:        ", i + 1);
        for (int j = 0; j < CADEIRAS; j++) {
            printf("%d ", teatro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    /* Matriz 5x8 representando o teatro inicializada com alguns 0s e 1s */
    int teatro[FILEIRAS][CADEIRAS] = {
        {1, 1, 0, 0, 1, 0, 1, 1},
        {0, 1, 1, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0}
    };

    printf("--- Sistema de Reservas do Teatro ---\n");
    exibir_teatro(teatro);

    int qtd;
    printf("\nDigite a quantidade de assentos contiguos que deseja reservar: ");
    if (scanf("%d", &qtd) != 1) {
        return 1;
    }

    int encontrado = 0;
    int fileira_reserva = -1;
    int col_inicio_reserva = -1;

    if (qtd > 0 && qtd <= CADEIRAS) {
        /* Lacos aninhados para buscar a primeira fileira com assentos contiguos */
        for (int i = 0; i < FILEIRAS; i++) {
            int consecutivos = 0;
            int inicio_col = -1;

            for (int j = 0; j < CADEIRAS; j++) {
                if (teatro[i][j] == 0) {
                    if (consecutivos == 0) {
                        inicio_col = j;
                    }
                    consecutivos++;

                    if (consecutivos == qtd) {
                        encontrado = 1;
                        fileira_reserva = i;
                        col_inicio_reserva = inicio_col;
                        break; // sai do laco interno
                    }
                } else {
                    consecutivos = 0;
                    inicio_col = -1;
                }
            }

            if (encontrado) {
                break; // sai do laco externo
            }
        }
    }

    if (encontrado) {
        /* Reservar os assentos (mudar de 0 para 1) */
        for (int k = 0; k < qtd; k++) {
            teatro[fileira_reserva][col_inicio_reserva + k] = 1;
        }

        printf("\nReserva realizada com sucesso!\n");
        printf("Fileira: %d\n", fileira_reserva + 1);
        printf("Cadeiras reservadas: ");
        for (int k = 0; k < qtd; k++) {
            printf("%d ", col_inicio_reserva + k + 1);
        }
        printf("\n");

        exibir_teatro(teatro);
    } else {
        printf("Desculpe, não há assentos contíguos suficientes.\n");
    }

    return 0;
}

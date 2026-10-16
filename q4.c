#include <stdio.h>

int main() {
    int base, altura;

    if (scanf("%d %d", &base, &altura) != 2) {
        return 1;
    }

    if (altura < 2 || altura > 50) {
        printf("Altura inválida!\n");
        return 0;
    }

    /* Parte crescente da pirâmide (de 1 até altura) */
    for (int i = 1; i <= altura; i++) {
        for (int j = 0; j < i; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", base + j);
        }
        printf("\n");
    }

    /* Parte decrescente da pirâmide (de altura - 1 descendo até 1) */
    for (int i = altura - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", base + j);
        }
        printf("\n");
    }

    return 0;
}

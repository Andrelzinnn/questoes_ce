#include <stdio.h>

int main() {
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        int valor = 0;

        printf("\nInforme o valor para saque (inteiro positivo): R$ ");
        while (1) {
            if (scanf("%d", &valor) != 1) {
                return 0;
            }
            if (valor > 0) {
                break;
            }
            printf("Erro: Valor invalido! Digite um valor inteiro maior que zero: R$ ");
        }

        /* b) Determinar a quantidade de cada cedula usando lacos while */
        int resto = valor;
        int cedulas[6] = {100, 50, 20, 10, 5, 1};
        int qtd[6] = {0};

        int i = 0;
        while (i < 6) {
            while (resto >= cedulas[i]) {
                qtd[i]++;
                resto -= cedulas[i];
            }
            i++;
        }

        /* c) Exibir quantidade de cada cedula utilizada, inclusive as com 0 */
        printf("\nDistribuicao das cedulas para R$ %d:\n", valor);
        i = 0;
        while (i < 6) {
            printf("Cedulas de R$ %3d: %d\n", cedulas[i], qtd[i]);
            i++;
        }

        /* d) Perguntar se deseja realizar uma nova operacao */
        printf("\nDeseja realizar uma nova operacao? (S/N): ");
        scanf(" %c", &continuar);
    }

    printf("Programa de caixa eletronico encerrado.\n");
    return 0;
}

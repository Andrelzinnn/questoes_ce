#include <stdio.h>

int main() {
    float saldo = 1000.0f;
    int opcao = -1;

    while (opcao != 0) {
        printf("\n1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar saldo\n");
        printf("0 - Encerrar\n");
        printf("Opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            break;
        }

        if (opcao == 1) {
            float valor;
            printf("Informe o valor a depositar: R$ ");
            scanf("%f", &valor);
            if (valor > 0.0f) {
                saldo += valor;
                printf("Deposito de R$ %.2f realizado com sucesso!\n", valor);
            } else {
                printf("Erro: Deposito permitido somente para valores positivos.\n");
            }
        } else if (opcao == 2) {
            float valor;
            printf("Informe o valor a sacar: R$ ");
            scanf("%f", &valor);
            if (valor <= 0.0f) {
                printf("Erro: O valor do saque deve ser positivo.\n");
            } else if (valor <= saldo) {
                saldo -= valor;
                printf("Saque de R$ %.2f realizado com sucesso!\n", valor);
            } else {
                printf("Erro: Saldo insuficiente! Saldo disponivel: R$ %.2f\n", saldo);
            }
        } else if (opcao == 3) {
            printf("Saldo atual: R$ %.2f\n", saldo);
        } else if (opcao == 0) {
            printf("Programa encerrado.\n");
        } else {
            printf("Opcao invalida! Escolha uma opcao valida.\n");
        }
    }

    return 0;
}

#include <stdio.h>


int exibe_menu() {
    int opcao;
    printf("\n--- MENU ---\n");
    printf("1. Consultar saldo\n");
    printf("2. Fazer recarga via Pix\n");
    printf("3. Chamar corrida\n");
    printf("4. Sair do app\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &opcao) != 1) {
        return 4; // sair se entrada invalida
    }
    return opcao;
}

float fazer_recarga(float saldo_atual) {
    float valor;
    printf("Informe o valor da recarga via Pix: R$ ");
    scanf("%f", &valor);

    if (valor > 0.0f) {
        saldo_atual += valor;
        printf("Recarga realizada com sucesso! Novo saldo: R$ %.2f\n", saldo_atual);
    } else {
        printf("Valor de recarga invalido! O valor deve ser maior que zero.\n");
    }

    return saldo_atual;
}

float pagar_corrida(float saldo_atual) {
    float valor;
    printf("Informe o valor da corrida: R$ ");
    scanf("%f", &valor);

    if (valor <= 0.0f) {
        printf("Valor de corrida invalido!\n");
        return saldo_atual;
    }

    if (valor > saldo_atual) {
        printf("Erro: Saldo insuficiente!\n");
        return saldo_atual;
    } else {
        saldo_atual -= valor;
        printf("Corrida paga com sucesso! Novo saldo: R$ %.2f\n", saldo_atual);
        return saldo_atual;
    }
}

int main() {
    float saldo = 0.0;
    int opcao = 0;

    while (opcao != 4) {
        opcao = exibe_menu();

        switch (opcao) {
            case 1:
                printf("Saldo atual: R$ %.2f\n", saldo);
                break;
            case 2:
                saldo = fazer_recarga(saldo);
                break;
            case 3:
                saldo = pagar_corrida(saldo);
                break;
            case 4:
                printf("Saindo do app...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }

    return 0;
}

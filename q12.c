#include <stdio.h>

/* Funções Obrigatórias */

/* 1. Função para calcular o fatorial */
unsigned long long calcular_fatorial(int n) {
    unsigned long long fat = 1;
    for (int i = 2; i <= n; i++) {
        fat *= (unsigned long long)i;
    }
    return fat;
}

/* 2. Função para verificar se o número é primo */
int verificar_primo(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

/* 3. Função para calcular a soma dos algarismos */
int somar_algarismos(int n) {
    int soma = 0;
    int temp = n;
    while (temp > 0) {
        soma += temp % 10;
        temp /= 10;
    }
    return soma;
}

/* 4. Função para exibir a tabuada */
void exibir_tabuada(int n) {
    printf("\n--- Tabuada de %d ---\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %2d = %d\n", n, i, n * i);
    }
}

int main() {
    int numero = 0;
    int cadastrado = 0;
    int opcao = 0;

    while (opcao != 6) {
        printf("\n=== MENU DE OPERAÇÕES ===\n");
        printf("1. Cadastrar um número\n");
        printf("2. Calcular o fatorial do número cadastrado\n");
        printf("3. Verificar se o número cadastrado é primo\n");
        printf("4. Calcular a soma dos algarismos do número cadastrado\n");
        printf("5. Exibir a tabuada do número cadastrado\n");
        printf("6. Sair do programa\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }

        if (opcao == 1) {
            int novo_numero;
            printf("Digite um número inteiro positivo: ");
            scanf("%d", &novo_numero);

            if (novo_numero > 0) {
                numero = novo_numero;
                cadastrado = 1;
                printf("Número %d cadastrado com sucesso!\n", numero);
            } else {
                printf("Valor inválido! O número deve ser positivo (> 0).\n");
            }
        } else if (opcao >= 2 && opcao <= 5) {
            if (!cadastrado) {
                printf("Aviso: Nenhum número foi cadastrado ainda! Retornando ao menu...\n");
            } else {
                switch (opcao) {
                    case 2:
                        if (numero > 20) {
                            printf("Fatorial de %d excede o limite de precisao de 64 bits.\n", numero);
                        } else {
                            printf("Fatorial de %d: %llu\n", numero, calcular_fatorial(numero));
                        }
                        break;
                    case 3:
                        if (verificar_primo(numero)) {
                            printf("O número %d É primo.\n", numero);
                        } else {
                            printf("O número %d NÃO é primo.\n", numero);
                        }
                        break;
                    case 4:
                        printf("Soma dos algarismos de %d: %d\n", numero, somar_algarismos(numero));
                        break;
                    case 5:
                        exibir_tabuada(numero);
                        break;
                }
            }
        } else if (opcao == 6) {
            printf("Encerrando o programa...\n");
        } else {
            printf("Erro: Opção inexistente no menu! Tente novamente.\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
    int n;

    /* I. Validar a entrada no intervalo de 0 a 100 */
    do {
        printf("Digite a quantidade de valores a inserir (0 a 100): ");
        if (scanf("%d", &n) != 1) {
            return 1;
        }
        if (n < 0 || n > 100) {
            printf("Quantidade invalida! O valor deve estar no intervalo de 0 a 100.\n");
        }
    } while (n < 0 || n > 100);

    if (n == 0) {
        printf("Quantidade informada foi 0. Nenhum valor inserido.\n");
        return 0;
    }

    /* II. Ler os valores e armazenar em um vetor */
    double vetor[100];
    double soma = 0.0;

    printf("\nDigite os %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%lf", &vetor[i]);
        soma += vetor[i];
    }

    /* III. Determinar maior, menor, media e desvio padrao */
    double maior = vetor[0];
    double menor = vetor[0];

    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }

    double media = soma / n;

    double soma_quadrados = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = vetor[i] - media;
        soma_quadrados += diff * diff;
    }

    double desvio_padrao = sqrt(soma_quadrados / n);

    /* Exibição dos resultados */
    printf("\n--- Resultados ---\n");
    printf("Maior elemento: %.2f\n", maior);
    printf("Menor elemento: %.2f\n", menor);
    printf("Media aritmetica: %.2f\n", media);
    printf("Desvio padrao: %.4f\n", desvio_padrao);

    return 0;
}

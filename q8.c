#include <stdio.h>

int main() {
    int v[10];
    int contagem[10] = {0};
    int ja_contado[10] = {0};

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento [%d]: ", i);
        if (scanf("%d", &v[i]) != 1) {
            return 1;
        }
    }

    printf("\n--- Vetor Original ---\n[ ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");

    int max_freq = 0;
    for (int i = 0; i < 10; i++) {
        if (ja_contado[i]) {
            continue;
        }

        int freq = 1;
        for (int j = i + 1; j < 10; j++) {
            if (v[j] == v[i]) {
                freq++;
                ja_contado[j] = 1; // marca duplicata para nao reprocessar depois
            }
        }
        contagem[i] = freq;

        if (freq > max_freq) {
            max_freq = freq;
        }
    }

    printf("\n--- Valores Repetidos ---\n");
    int tem_repetidos = 0;
    for (int i = 0; i < 10; i++) {
        if (!ja_contado[i] && contagem[i] > 1) {
            printf("Valor %d: aparece %d vezes\n", v[i], contagem[i]);
            tem_repetidos = 1;
        }
    }

    if (!tem_repetidos) {
        printf("Nenhum valor apareceu mais de uma vez.\n");
    }

    printf("\n--- Valor(es) com Maior Ocorrencia ---\n");
    if (max_freq > 1) {
        printf("Maior frequencia de repeticao: %d vezes\n", max_freq);
        printf("Valor(es) que mais se repetiu(ram): ");
        for (int i = 0; i < 10; i++) {
            if (!ja_contado[i] && contagem[i] == max_freq) {
                printf("%d ", v[i]);
            }
        }
        printf("\n");
    } else {
        printf("Todos os elementos sao distintos (nenhum se repetiu).\n");
    }

    return 0;
}

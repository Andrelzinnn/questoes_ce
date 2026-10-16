#include <stdio.h>

int main() {
    int nota = -1;
    int total_participantes = 0;
    int contagem[6] = {0}; // índices 1 a 5

    printf("--- Pesquisa de Satisfacao dos Clientes ---\n");
    printf("Digite notas de 1 a 5 (ou 0 para encerrar):\n");

    while (nota != 0) {
        printf("Digite a nota: ");
        if (scanf("%d", &nota) != 1) {
            break;
        }

        if (nota == 0) {
            break;
        } else if (nota >= 1 && nota <= 5) {
            contagem[nota]++;
            total_participantes++;
        } else {
            printf("Nota invalida! Digite uma nota de 1 a 5 ou 0 para sair.\n");
        }
    }

    printf("\n--- Resultado Final ---\n");
    printf("Total de participantes: %d\n", total_participantes);

    int i = 1;
    while (i <= 5) {
        float porcentagem = 0.0f;
        if (total_participantes > 0) {
            porcentagem = ((float)contagem[i] / total_participantes) * 100.0f;
        }
        printf("Nota %d: %d voto(s) - %.2f%%\n", i, contagem[i], porcentagem);
        i++;
    }

    return 0;
}

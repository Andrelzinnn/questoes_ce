#include <stdio.h>

int main() {
    int respostas[3][5];
    int gabarito[5];
    int resultado[3] = {0};

    printf("--- Gabarito Oficial ---\n");
    for (int j = 0; j < 5; j++) {
        do {
            printf("Resposta correta da questao %d (1 a 4): ", j + 1);
            if (scanf("%d", &gabarito[j]) != 1) return 1;
            if (gabarito[j] < 1 || gabarito[j] > 4) {
                printf("Opcao invalida! Digite apenas 1, 2, 3 ou 4.\n");
            }
        } while (gabarito[j] < 1 || gabarito[j] > 4);
    }

    printf("\n--- Respostas dos Alunos ---\n");
    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            do {
                printf("Resposta da questao %d (1 a 4): ", j + 1);
                if (scanf("%d", &respostas[i][j]) != 1) return 1;
                if (respostas[i][j] < 1 || respostas[i][j] > 4) {
                    printf("Opcao invalida! Digite apenas 1, 2, 3 ou 4.\n");
                }
            } while (respostas[i][j] < 1 || respostas[i][j] > 4);
        }
    }

    for (int i = 0; i < 3; i++) {
        resultado[i] = 0;
        for (int j = 0; j < 5; j++) {
            if (respostas[i][j] == gabarito[j]) {
                resultado[i]++;
            }
        }
    }

    /* Exibir pontuacao de cada aluno */
    printf("\n--- Resultado dos Alunos ---\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d: %d acerto(s)\n", i + 1, resultado[i]);
    }

    /* v. Dizer quem foi o aluno com maior nota */
    int maior_nota = resultado[0];
    for (int i = 1; i < 3; i++) {
        if (resultado[i] > maior_nota) {
            maior_nota = resultado[i];
        }
    }

    printf("\nMaior nota obtida: %d acerto(s)\n", maior_nota);
    printf("Aluno(s) com a maior nota: ");
    for (int i = 0; i < 3; i++) {
        if (resultado[i] == maior_nota) {
            printf("Aluno %d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}

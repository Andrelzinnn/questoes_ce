#include <stdio.h>


float calcular_media() {
    float p1, p2, lista;
    printf("Digite a nota da Prova 1: ");
    scanf("%f", &p1);
    printf("Digite a nota da Prova 2: ");
    scanf("%f", &p2);
    printf("Digite a nota da Lista de Exercicios: ");
    scanf("%f", &lista);

    float media = (((p1 + p2) / 2.0f) * 0.8f) + (lista * 0.2f);
    return media;
}

float calcular_recuperacao(float media_antiga) {
    float nota_rec;
    printf("Digite a nota da prova de Recuperacao: ");
    scanf("%f", &nota_rec);

    float nova_media = (media_antiga + nota_rec) / 2.0f;
    return nova_media;
}

int main() {
    const char *disciplinas[4] = {
        "Feiticos",
        "Pocoes",
        "Defesa Contra as Artes das Trevas",
        "Herbologia"
    };

    float medias[4];
    float soma_cr = 0.0f;
    int todas_aprovadas = 1;

    for (int i = 0; i < 4; i++) {
        printf("\n--- Disciplina: %s ---\n", disciplinas[i]);
        medias[i] = calcular_media();
        printf("Media em %s: %.2f\n", disciplinas[i], medias[i]);
        soma_cr += medias[i];

        if (medias[i] < 7.0f) {
            todas_aprovadas = 0;
        }
    }

    float cr = soma_cr / 4.0f;

    if (todas_aprovadas) {
        printf("\nParabéns Harry, você passou! 100 pontos para a Grifinória!\n");
        printf("CR: %.2f\n", cr);
    } else {
        printf("\nRecuperação:\n");

        float soma_novo_cr = 0.0f;
        int aprovado_final = 1;

        for (int i = 0; i < 4; i++) {
            if (medias[i] < 7.0f) {
                printf("\nRecuperacao para %s (media anterior: %.2f):\n", disciplinas[i], medias[i]);
                medias[i] = calcular_recuperacao(medias[i]);
                printf("Nova media em %s: %.2f\n", disciplinas[i], medias[i]);
            }
            soma_novo_cr += medias[i];

            if (medias[i] < 5.0f) {
                aprovado_final = 0;
            }
        }

        float novo_cr = soma_novo_cr / 4.0f;
        printf("\nCR Final: %.2f\n", novo_cr);

        if (aprovado_final) {
            printf("Harry, após muito esforço você conseguiu passar! 50 pontos para a Grifinória!\n");
        } else {
            printf("Harry, você reprovou e terá que repetir o ano! -100 pontos para a Grifinória!\n");
        }
    }

    return 0;
}

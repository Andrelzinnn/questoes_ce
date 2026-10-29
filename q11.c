#include <stdio.h>

#define CATEGORIAS 4
#define FORNECEDORES 5

int main() {
    int estoque[CATEGORIAS][FORNECEDORES];
    int total_geral = 0;
    int total_categoria[CATEGORIAS] = {0};
    int total_fornecedor[FORNECEDORES] = {0};

    printf("--- Cadastro de Estoque (4 Categorias x 5 Fornecedores) ---\n");
    for (int i = 0; i < CATEGORIAS; i++) {
        printf("\nCategoria %d:\n", i + 1);
        for (int j = 0; j < FORNECEDORES; j++) {
            printf("Quantidade para Fornecedor %d: ", j + 1);
            if (scanf("%d", &estoque[i][j]) != 1) {
                return 1;
            }
            total_geral += estoque[i][j];
            total_categoria[i] += estoque[i][j];
            total_fornecedor[j] += estoque[i][j];
        }
    }

    printf("\n=== RELATORIO DE ESTOQUE ===\n");
    printf("Quantidade total de produtos em estoque: %d\n\n", total_geral);

    printf("--- Total por Categoria ---\n");
    for (int i = 0; i < CATEGORIAS; i++) {
        printf("Categoria %d: %d unidades\n", i + 1, total_categoria[i]);
    }

    printf("\n--- Total por Fornecedor ---\n");
    for (int j = 0; j < FORNECEDORES; j++) {
        printf("Fornecedor %d: %d unidades\n", j + 1, total_fornecedor[j]);
    }

    printf("\n--- Alertas de Reabastecimento ---\n");
    for (int j = 0; j < FORNECEDORES; j++) {
        if (total_fornecedor[j] < 10) {
            printf("Atencao: fornecedor %d precisa reabastecer.\n", j + 1);
        }
    }

    return 0;
}

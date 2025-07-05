#include <stdio.h>

struct Produto {
    int codigo;
    char tipo; 
    int vendas[6]; 
    double media_semana;
};

void ler_dados(struct Produto *produto) {
    printf("Digite o código do produto: ");
    scanf("%d", &produto->codigo);

    printf("Digite o tipo do produto (P, M ou G): ");
    scanf(" %c", &produto->tipo);

    printf("Digite as quantidades vendidas para cada dia da semana:\n");
    for (int i = 0; i < 6; ++i) {
        printf("Dia %d: ", i + 1);
        scanf("%d", &produto->vendas[i]);
    }
}

void calcular_media_semana(struct Produto *produto) {
    int soma = 0;
    for (int i = 0; i < 6; ++i) {
        soma += produto->vendas[i];
    }
    produto->media_semana = (double)soma / 6;
}

int main() {
    struct Produto produtos[50]; 

    printf("Digite os dados dos 50 produtos:\n");
    for (int i = 0; i < 50; ++i) {
        printf("Produto %d:\n", i + 1);
        ler_dados(&produtos[i]);
        calcular_media_semana(&produtos[i]);
    }

    printf("\nRelatório de Vendas:\n");
    for (int i = 0; i < 50; ++i) {
        printf("Produto %d (Código %d, Tipo %c):\n", i + 1, produtos[i].codigo, produtos[i].tipo);
        printf("Total vendido por dia: ");
        for (int j = 0; j < 6; ++j) {
            printf("%d ", produtos[i].vendas[j]);
        }
        printf("\nMédia da semana: %.2f\n\n", produtos[i].media_semana);
    }

    return 0;
}

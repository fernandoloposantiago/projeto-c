#include <stdio.h>
#include <string.h>

// Estrutura simples para item
typedef struct {
    char nome[30];
    int quantidade;
} Item;

// Inventário como vetor
#define MAX 10
Item mochila[MAX];
int tamanho = 0;

// Adiciona item no inventário

void adicionar(char nome[], int qtd) {
    if(tamanho < MAX) {
        strcpy(mochila[tamanho].nome, nome);
        mochila[tamanho].quantidade = qtd;
        tamanho++;
        printf("Item adicionado!\n");
    } else {
        printf("Mochila cheia!\n");
    }
}

// Lista itens
void listar() {
    if(tamanho == 0) {
        printf("Mochila vazia.\n");
    } else {
        printf("Itens na mochila:\n");
        for(int i=0; i<tamanho; i++) {
            printf("%d) %s - %d unidades\n", i+1, mochila[i].nome, mochila[i].quantidade);
        }
    }
}

int main() {
    int opcao;
    char nome[30];
    int qtd;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Adicionar item\n");
        printf("2. Listar itens\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if(opcao == 1) {
            printf("Nome do item: ");
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0; // tira \n
            printf("Quantidade: ");
            scanf("%d", &qtd);
            adicionar(nome, qtd);
        }
        else if(opcao == 2) {
            listar();
        }
    } while(opcao != 0);

    printf("Saindo do jogo...\n");
    return 0;
}

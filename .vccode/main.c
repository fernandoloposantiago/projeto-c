#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tarefa {
    int id;
    char descricao[256];
    int concluida;
    struct Tarefa *prox;
} Tarefa;

int gerarId(Tarefa *lista); // Protótipo da função gerarId

void adicionarTarefa(Tarefa **lista) {
    Tarefa *nova = malloc(sizeof(Tarefa));
    if (!nova) {
        printf("Erro de alocação de memória.\n");
        return;
    }
    nova->id = gerarId(*lista);
    printf("Descrição: ");
    fgets(nova->descricao, sizeof(nova->descricao), stdin);
    nova->descricao[strcspn(nova->descricao, "\n")] = '\0';
    nova->concluida = 0;
    nova->prox = *lista;
    *lista = nova;
    printf("Tarefa adicionada com ID %d!\n", nova->id);
}

void listarTarefas(Tarefa *lista) {
    if (!lista) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }
    printf("\nLista de Tarefas:\n");
    while (lista) {
        printf("ID: %d | [%c] %s\n", lista->id, lista->concluida ? 'X' : ' ', lista->descricao);
        lista = lista->prox;
    }
}

void concluirTarefa(Tarefa *lista) {
    int id;
    printf("Digite o ID da tarefa a concluir: ");
    scanf("%d", &id);
    getchar();

    while (lista) {
        if (lista->id == id) {
            lista->concluida = 1;
            printf("Tarefa ID %d marcada como concluída.\n", id);
            return;
        }
        lista = lista->prox;
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

void removerTarefa(Tarefa **lista) {
    int id;
    printf("Digite o ID da tarefa a remover: ");
    scanf("%d", &id);
    getchar();

    Tarefa *atual = *lista, *anterior = NULL;
    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->prox = atual->prox;
            } else {
                *lista = atual->prox;
            }
            free(atual);
            printf("Tarefa removida com sucesso.\n");
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Tarefa com ID %d não encontrada.\n", id);
}

void liberarTarefas(Tarefa *lista) {
    Tarefa *tmp;
    while (lista) {
        tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    return;
}

int gerarId(Tarefa *lista) {
    int maxId = 0;
    while (lista) {
        if (lista->id > maxId) {
            maxId = lista->id;
        }
        lista = lista->prox;
    }
    return maxId + 1;
}


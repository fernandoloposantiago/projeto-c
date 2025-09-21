#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//=====================DEFINIÇÕES=====================
#define MAX_FILA 5
#define MAX_PILHA 5

// ESTRUTURA DE PEÇAS
typedef struct {
    char tipo[10];   // EXEMPLO: "LINHA", "QUADRADO", "T", "L"
} PECA;

//ESTRUTURA DE FILA CIRCULAR
typedef struct {
    PECA itens[MAX_FILA];
    int frente, tras, quantidade;
} FILA;

// ESTRUTURA DE PILHA 
typedef struct {
    PECA itens[MAX_PILHA];
    int topo;
} PILHA;

//=====================FUNÇÕES DE FILA =====================
void inicializarfila(FILA *f) {
    f->frente = 0;
    f->tras = -1;
    f->quantidade = 0;
}

int enqueue(FILA *f, PECA p) {
    if (f->quantidade == MAX_FILA) {
        printf("FILA CHEIA!\n");
        return 0;
    }
    f->tras = (f->tras + 1) % MAX_FILA;
    f->itens[f->tras] = p;
    f->quantidade++;
    return 1;
}

int dequeue(FILA *f, PECA *p) {
    if (f->quantidade == 0) {
        printf("FILA VAZIA!\n");
        return 0;
    }
    *p = f->itens[f->frente];
    f->frente = (f->frente + 1) % MAX_FILA;
    f->quantidade--;
    return 1;
}

void exibirfila(FILA *f) {
    printf("\nFILA (peças futuras): ");
    if (f->quantidade == 0) {
        printf("[VAZIA]");
    } else {
        for (int i = 0, j = f->frente; i < f->quantidade; i++) {
            printf("[%s]", f->itens[j].tipo);
            j = (j + 1) % MAX_FILA;
        }
    }
    printf("\n");
}

//=====================FUNÇÕES DE PILHA =====================
void inicializarpilha(PILHA *p) {
    p->topo = -1;
}

int push(PILHA *p, PECA elem) {
    if (p->topo == MAX_PILHA - 1) {
        printf("PILHA CHEIA!\n");
        return 0;
    }
    p->itens[++p->topo] = elem;
    return 1;
}

int pop(PILHA *p, PECA *elem) {
    if (p->topo == -1) {
        printf("PILHA VAZIA!\n");
        return 0;
    }
    *elem = p->itens[p->topo--];
    return 1;
}

void exibirpilha(PILHA *p) {
    printf("\nPILHA (reserva): ");
    if (p->topo == -1) {
        printf("[VAZIA]");
    } else {
        for (int i = 0; i <= p->topo; i++) {
            printf("[%s]", p->itens[i].tipo);
        }
    }
    printf("\n");
}

//==================TRANSFERÊNCIAS ENTRE FILA E PILHA========================
void transferirfilaparapilha(FILA *f, PILHA *p) {
    PECA temp;
    if (dequeue(f, &temp)) {
        if (push(p, temp)) {
            printf("Peça [%s] transferida da fila para pilha (reserva)\n", temp.tipo);
        }
    }
}

void transferirpilhaparafila(PILHA *p, FILA *f) {
    PECA temp;
    if (pop(p, &temp)) {
        if (enqueue(f, temp)) {
            printf("Peça [%s] transferida da pilha para fila\n", temp.tipo);
        }
    }
}

//=================MENU PRINCIPAL =======================
int main() {
    FILA fila;
    PILHA pilha;
    inicializarfila(&fila);
    inicializarpilha(&pilha);

    int opcao;
    PECA nova, jogada;

    do {
        printf("\n=======TETRIS STACK======\n");
        printf("1. Adicionar peça na fila\n");
        printf("2. Jogar peça da fila\n");
        printf("3. Reservar peça (Fila -> Pilha)\n");
        printf("4. Recuperar peça (Pilha -> Fila)\n");
        printf("5. Exibir estado (Fila + Pilha)\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("Digite o nome da peça: ");
                fgets(nova.tipo, sizeof(nova.tipo), stdin);
                nova.tipo[strcspn(nova.tipo, "\n")] = 0;  // remover \n
                enqueue(&fila, nova);
                break;

            case 2:
                if (dequeue(&fila, &jogada)) {
                    printf("Peça jogada: [%s]\n", jogada.tipo);
                }
                break;

            case 3:
                transferirfilaparapilha(&fila, &pilha);
                break;

            case 4:
                transferirpilhaparafila(&pilha, &fila);
                break;

            case 5:
                exibirfila(&fila);
                exibirpilha(&pilha);
                break;

            case 0:
                printf("Encerrando o jogo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
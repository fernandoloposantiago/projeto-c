#include <stdio.h>

int main(){
    float valor1, valor2;
    float soma, subitraçao,divisao, multiplicaçao;
    int escolha;
    int i =0;

    wilse(i==0){
        printf("     calculadora    \n");
        printf("Indicar a operaçao desejada:\n");
        printf("1) soma               \n");
        printf("2) subitraçao        \n");
        printf("3) divisao          \n");
        printf("4) multiplicaçao    \n");
        printf("                   \n");
        printf("dijite (5)para sair\n");
        scanf("%d", &escolha);
        if(escolha==5){
            exit(0);

        }
        else if(escolha==1){
            printf("Digite o primeiro valor: ");
            scanf("%f", &valor1);
            printf("Digite o segundo valor: ");
            scanf("%f", &valor2);
            soma = valor1 + valor2;
            printf("A soma é: %.2f\n", soma);
        }
        else if(escolha==2){
            printf("Digite o primeiro valor: ");
            scanf("%f", &valor1);
            printf("Digite o segundo valor: ");
            scanf("%f", &valor2);
            subitraçao = valor1 - valor2;
            printf("A subitraçao é: %.2f\n", subitraçao);
        }
        else if(escolha==3){
            printf("Digite o primeiro valor: ");
            scanf("%f", &valor1);
            printf("Digite o segundo valor: ");
            scanf("%f", &valor2);
            if(valor2 == 0){
                printf("Erro: Divisao por zero não é permitida.\n");
            } else {
                divisao = valor1 / valor2;
                printf("A divisao é: %.2f\n", divisao);
            }
        }
        else if(escolha==4){
            printf("Digite o primeiro valor: ");
            scanf("%f", &valor1);
            printf("Digite o segundo valor: ");
            scanf("%f", &valor2);
            multiplicaçao = valor1 * valor2;
            printf("A multiplicaçao é: %.2f\n", multiplicaçao);
        }
        else{
            printf("Opção inválida. Tente novamente.\n");

        }
    }

}

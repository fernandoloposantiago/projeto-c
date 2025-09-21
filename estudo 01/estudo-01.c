#include <stdio.h>

int main(){

    char nome [32];
    char sobrenome[32];
    float altura;
    float peso;
    int idade;
    char sexo;
    double salario;
    
printf("digite seu nome:");
scanf("%s", nome);
printf("digite seu sobrinome:");
scanf("%s", sobrenome);
printf("digite sua altura:");
scanf("%f", &altura);
printf("digite seu peso:");
scanf("%f",&peso);
printf("digite sua idade:");
scanf("%d", &idade);
getcahr(); // consome o'\n' deixado no bluffer pelo scanf anterior
printf("digite seu sexo:");
scanf("%c",&sexo);
printf("dijite seu salario:");
scanf("%lf", &salario );

printf("nome: %s\n", nome);
printf("sobrenome: %s\n", sobrenome);   
printf("altura: %.2f\n", altura);
printf("peso: %.2f\n", peso);
printf("idade: %d\n", idade);
printf("sexo: %c\n", sexo);
printf("salario: %.2lf\n", salario);





    return 0;
}
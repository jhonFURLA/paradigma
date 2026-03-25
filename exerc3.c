#include <stdio.h>

int main() {
    float s1 = 2000, s2 = 3000, s3 = 2500;
    int h1 = 10, h2 = 5, h3 = 8;
    float bonus1, bonus2, bonus3;

    bonus1 = (h1 > 8) ? 200 : 100;
    float total1 = s1 + (h1 * 20) + bonus1;
    printf("Funcionario 1\n");
    printf("Salario base: %.2f\n", s1);
    printf("Horas extra: %d\n", h1);
    printf("Total: %.2f\n\n", total1);

    bonus2 = (h2 > 8) ? 200 : 100;
    float total2 = s2 + (h2 * 20) + bonus2;
    printf("Funcionario 2\n");
    printf("Salario base: %.2f\n", s2);
    printf("Horas extra: %d\n", h2);
    printf("Total: %.2f\n\n", total2);

    bonus3 = (h3 > 8) ? 200 : 100;
    float total3 = s3 + (h3 * 20) + bonus3;
    printf("Funcionario 3\n");
    printf("Salario base: %.2f\n", s3);
    printf("Horas extra: %d\n", h3);
    printf("Total: %.2f\n\n", total3);

    return 0;
}
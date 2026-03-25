
#include <stdio.h>

/*
 * ============================
 * 1) VERSÃO ITERATIVA (FOR)
 * ============================
 * Complexidade:
 *  - Tempo: O(n)
 *  - Espaço: O(1)
 *
 * Ideia:
 *  Calcula do termo 0 até o n acumulando resultados,
 *  evitando recomputações.
 */
long long fibonacci_iterativo(int n) {
    if (n <= 1) return n;

    long long a = 0, b = 1, temp;

    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    return b;
}

/*
 * ====================================
 * 2) VERSÃO RECURSIVA INGÊNUA (PURa)
 * ====================================
 *
 * Complexidade:
 *  - Tempo: O(2^n)  (exponencial)
 *  - Espaço: O(n)   (profundidade da pilha)
 *
 * Por que é exponencial?
 *  A função chama a si mesma duas vezes:
 *      fib(n) = fib(n-1) + fib(n-2)
 *
 *  Isso gera uma árvore de chamadas:
 *
 *              fib(5)
 *           /          \
 *      fib(4)        fib(3)
 *     /     \        /     \
 * fib(3) fib(2)  fib(2) fib(1)
 *
 *  Note que:
 *  - fib(3) é calculado várias vezes
 *  - fib(2) também é recalculado várias vezes
 *
 *  Ou seja: há SOBREPOSIÇÃO DE SUBPROBLEMAS.
 *
 * Impacto:
 *  - Número de chamadas cresce exponencialmente (~2^n)
 *  - Muitas chamadas de função → alto custo de CPU
 *  - Cada chamada cria um Stack Frame:
 *      parâmetros + variáveis locais + endereço de retorno
 *
 *  Para n = 40:
 *  - Milhões de chamadas são realizadas
 *  - Uso intenso da pilha (stack)
 */
long long fibonacci_recursivo(int n) {
    if (n <= 1) return n;

    return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int main() {
    int n = 40;

    long long resultado_iterativo = fibonacci_iterativo(n);
    long long resultado_recursivo = fibonacci_recursivo(n);

    printf("Fibonacci(%d) - Iterativo: %lld\n", n, resultado_iterativo);
    printf("Fibonacci(%d) - Recursivo: %lld\n", n, resultado_recursivo);

    return 0;
}
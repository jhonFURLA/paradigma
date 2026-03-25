#include <stdio.h>

/*
 * ==========================================
 * 1) PASSAGEM POR VALOR (IN MODE)
 * ==========================================
 *
 * Aqui, o parâmetro 'saldo' é uma CÓPIA do valor original.
 *
 * O que acontece internamente:
 *  - main possui: saldo_bancario = 1000
 *  - Ao chamar a função:
 *        alterar_por_valor(saldo_bancario);
 *  - O valor 1000 é COPIADO para o parâmetro formal 'saldo'
 *
 * Ou seja:
 *  - saldo (na função) ≠ saldo_bancario (no main)
 *  - Eles ocupam posições diferentes na memória
 *
 * Resultado:
 *  - Alterações afetam apenas a cópia local
 *  - O valor original permanece inalterado
 */
void alterar_por_valor(int saldo) {
    printf("\n[POR VALOR] Antes da alteracao: saldo = %d\n", saldo);

    saldo += 500;  // altera apenas a cópia local

    printf("[POR VALOR] Depois da alteracao: saldo = %d\n", saldo);

    /*
     * Ao sair da função:
     *  - A variável 'saldo' é destruída (stack frame removido)
     *  - Nenhuma alteração é refletida no main
     */
}

/*
 * ==========================================
 * 2) PASSAGEM POR REFERÊNCIA (INOUT MODE)
 * ==========================================
 *
 * Aqui usamos ponteiros para acessar o endereço da variável original.
 *
 * O que acontece:
 *  - main passa o ENDEREÇO de saldo_bancario:
 *        alterar_por_referencia(&saldo_bancario);
 *
 *  - A função recebe um ponteiro:
 *        int *saldo
 *
 *  - Agora:
 *        saldo -> aponta para saldo_bancario
 *
 *  - Usando *saldo, acessamos/modificamos o valor ORIGINAL
 */
void alterar_por_referencia(int *saldo) {
    printf("\n[POR REFERENCIA] Antes da alteracao: saldo = %d\n", *saldo);

    *saldo += 500;  // altera o valor original via ponteiro

    printf("[POR REFERENCIA] Depois da alteracao: saldo = %d\n", *saldo);

    /*
     * Aqui NÃO estamos alterando uma cópia,
     * mas sim o conteúdo do endereço original.
     */
}

int main() {
    /*
     * Variável nasce no escopo do main
     */
    int saldo_bancario = 1000;

    printf("Saldo inicial (main): %d\n", saldo_bancario);

    /*
     * ======================================
     * CHAMADA POR VALOR (NÃO ALTERA ORIGINAL)
     * ======================================
     */
    alterar_por_valor(saldo_bancario);

    printf("\nApos chamada por valor (main): %d\n", saldo_bancario);

    /*
     * ==========================================
     * CHAMADA POR REFERÊNCIA (ALTERA ORIGINAL)
     * ==========================================
     */
    alterar_por_referencia(&saldo_bancario);

    printf("\nApos chamada por referencia (main): %d\n", saldo_bancario);

    return 0;
}
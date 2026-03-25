#include <stdio.h>

/*
 * ==========================================
 * ❌ VERSÃO COM ERRO (SEM CASO BASE)
 * ==========================================
 *
 * Esta função causa recursão infinita.
 * Se descomentada, o programa irá:
 *  - imprimir números indefinidamente
 *  - consumir a pilha (stack)
 *  - terminar com erro:
 *
 * Linux/macOS:
 *   Segmentation fault (core dumped)
 *
 * Windows:
 *   Stack overflow / 0xC00000FD
 */
void contagem_sem_base(int n) {
    printf("[ERRO] n = %d\n", n);

    // ❌ Não há condição de parada!
    contagem_sem_base(n - 1);
}


/*
 * ==========================================
 * ✅ VERSÃO CORRETA (COM CASO BASE)
 * ==========================================
 *
 * Agora a recursão é controlada:
 *  - existe condição de parada
 *  - a pilha cresce e depois é liberada
 */
void contagem_com_base(int n) {

    // 🛑 CASO BASE (condição de parada)
    if (n < 0) {
        return;
    }

    printf("[OK] n = %d\n", n);

    // 🔁 PASSO RECURSIVO
    contagem_com_base(n - 1);
}


int main() {

    printf("==========\n");
    printf("TESTE 1: FUNCAO SEM CASO BASE\n");
    printf("============\n");

    /*
     * ⚠️ IMPORTANTE:
     * DESCOMENTE a linha abaixo para testar o erro.
     * O programa irá travar com stack overflow.
     */

    // contagem_sem_base(5);


    printf("\n=========\n");
    printf("TESTE 2: FUNCAO CORRIGIDA\n");
    printf("=========\n");

    contagem_com_base(5);

    printf("\nPrograma finalizado com sucesso.\n");

    return 0;
}
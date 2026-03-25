#include <stdio.h>

/*
 * ==========================================
 * FUNÇÃO PURA (SEM EFEITO COLATERAL)
 * ==========================================
 *
 * Responsabilidade:
 *  → Calcular uma nova altitude segura
 *
 * Características:
 *  - NÃO altera a variável original
 *  - NÃO usa ponteiros
 *  - Retorna um novo valor
 *
 * Segurança:
 *  - Limita a variação máxima de altitude
 */
int calcular_altitude_segura(int altitude_atual, int ajuste) {
    int nova_altitude = altitude_atual + ajuste;

    // Regra de segurança: altitude mínima e máxima
    if (nova_altitude < 0)
        nova_altitude = 0;

    if (nova_altitude > 12000)
        nova_altitude = 12000;

    return nova_altitude;
}

/*
 * ==========================================
 * PROCEDIMENTO COM EFEITO COLATERAL
 * ==========================================
 *
 * Responsabilidade:
 *  → FORÇAR a alteração da altitude original
 *
 * Características:
 *  - Recebe um ponteiro (endereço da variável)
 *  - Modifica diretamente o estado externo
 *
 * Efeito colateral:
 *  - Altera a variável que está no main
 */
void forcar_altitude(int *altitude, int nova_altitude) {
    printf("\n[Procedimento] Alterando altitude diretamente...\n");

    *altitude = nova_altitude;  // efeito colateral direto
}

int main() {
    /*
     * Variável nasce no escopo local do main
     */
    int altitude = 5000;

    printf("Altitude inicial: %d metros\n", altitude);

    /*
     * ==========================================
     * USO DA FUNÇÃO PURA (SEM ALTERAR ESTADO)
     * ==========================================
     */
    int altitude_calculada = calcular_altitude_segura(altitude, 3000);

    printf("\n[Funcao Pura]\n");
    printf("Altitude original (inalterada): %d metros\n", altitude);
    printf("Nova altitude sugerida: %d metros\n", altitude_calculada);

    /*
     * ==========================================
     * USO DO PROCEDIMENTO (COM EFEITO COLATERAL)
     * ==========================================
     */
    forcar_altitude(&altitude, altitude_calculada);

    printf("\n[Depois do efeito colateral]\n");
    printf("Altitude atual (main): %d metros\n", altitude);

    return 0;
}

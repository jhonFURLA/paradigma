/*
 * ==========================================
 * ANÁLISE CONCEITUAL
 * ==========================================
 *
 * Em sistemas complexos como um hospital, manter o estado completo em uma
 * única struct gigante (SistemaHospitalar) rapidamente se torna insustentável.
 * Cada função precisa saber a posição exata de cada array, quantos ponteiros
 * passar e como atualizar corretamente cada campo. Isso gera código frágil,
 * difícil de depurar e propenso a corrupção de dados. Separar funções
 * matemáticas do estado exige o conhecimento detalhado de toda a estrutura
 * interna, o que motiva o uso de encapsulamento (por exemplo structs com
 * funções associadas ou módulos) para proteger o estado e simplificar o
 * desenvolvimento.
 */

#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100
#define MAX_MEDICOS 50
#define MAX_LEITOS 80

typedef struct {
    char nome[50];
    int idade;
    int leito_alocado; // -1 se não estiver internado
} Paciente;

typedef struct {
    char nome[50];
    char especialidade[50];
} Medico;

typedef struct {
    Paciente pacientes[MAX_PACIENTES];
    int total_pacientes;

    Medico medicos[MAX_MEDICOS];
    int total_medicos;

    int leitos_disponiveis[MAX_LEITOS];
    int total_leitos;

    float caixa_financeiro;
} SistemaHospitalar;

// ==
// PROCEDIMENTO: REALIZAR INTERNAÇÃO
// ==
void realizar_internacao(SistemaHospitalar *sistema, int indice_paciente, int leito, float custo) {
    // Verifica limites
    if (indice_paciente < 0 || indice_paciente >= sistema->total_pacientes) {
        printf("Paciente inválido!\n");
        return;
    }
    if (leito < 0 || leito >= sistema->total_leitos) {
        printf("Leito inválido!\n");
        return;
    }
    if (sistema->leitos_disponiveis[leito] == 0) {
        printf("Leito já ocupado!\n");
        return;
    }

    // Atualiza paciente
    sistema->pacientes[indice_paciente].leito_alocado = leito;

    // Marca leito como ocupado
    sistema->leitos_disponiveis[leito] = 0;

    // Atualiza caixa financeiro
    sistema->caixa_financeiro += custo;

    printf("Paciente %s internado no leito %d. Caixa atualizado: %.2f\n",
           sistema->pacientes[indice_paciente].nome, leito, sistema->caixa_financeiro);
}

// ==
// FUNÇÃO PRINCIPAL (EXEMPLO DE USO)
// ==
int main() {
    SistemaHospitalar hospital;

    // Inicialização
    hospital.total_pacientes = 2;
    strcpy(hospital.pacientes[0].nome, "João");
    hospital.pacientes[0].idade = 30;
    hospital.pacientes[0].leito_alocado = -1;

    strcpy(hospital.pacientes[1].nome, "Maria");
    hospital.pacientes[1].idade = 25;
    hospital.pacientes[1].leito_alocado = -1;

    hospital.total_medicos = 1;
    strcpy(hospital.medicos[0].nome, "Dr. Silva");
    strcpy(hospital.medicos[0].especialidade, "Clínico Geral");

    hospital.total_leitos = 3;
    for (int i = 0; i < hospital.total_leitos; i++) {
        hospital.leitos_disponiveis[i] = 1; // 1 = disponível
    }

    hospital.caixa_financeiro = 10000.0;

    // ==
    // Exemplo de internação
    // ==
    realizar_internacao(&hospital, 0, 1, 500.0); // João no leito 1
    realizar_internacao(&hospital, 1, 2, 800.0); // Maria no leito 2

    return 0;
}
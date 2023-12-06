#include <stdio.h>

#define CONTAS 10

typedef struct {
    int numeroConta;
    float saldoDevedor;
} Conta;

int main() {
    Conta contas[CONTAS];

    for (int i = 0; i < CONTAS; ++i) {
        contas[i].numeroConta = i + 1;
        contas[i].saldoDevedor = 0.0;
    }


    int numeroContaEscolhida;
    printf("Informe o número da conta (1 a %d): ", CONTAS);
    scanf("%d", &numeroContaEscolhida);

    if (numeroContaEscolhida < 1 || numeroContaEscolhida > CONTAS) {
        printf("Número de conta inválido. Programa encerrado.\n");
        return 1;
    }

    int indiceConta = numeroContaEscolhida - 1;

    float cobrancas, creditos, limiteCredito, novoSaldo;

    printf("Informe o total de itens cobrados ao cliente no mês: ");
    scanf("%f", &cobrancas);

    printf("Informe o total de créditos aplicados à conta do cliente no mês: ");
    scanf("%f", &creditos);

    printf("Informe o limite de crédito permitido: ");
    scanf("%f", &limiteCredito);

    // Cálculo do novo saldo para a conta escolhida
    novoSaldo = contas[indiceConta].saldoDevedor + cobrancas - creditos;

    // Verificação se o novo saldo supera o limite de crédito
    if (novoSaldo > limiteCredito) {
        printf("\nNúmero da Conta: %d\n", contas[indiceConta].numeroConta);
        printf("Limite de Crédito: $%.2f\n", limiteCredito);
        printf("Mensagem: Limite de Crédito Excedido\n");
    } else {
        printf("\nO novo saldo não excede o limite de crédito.\n");
        printf("\nNúmero da Conta: %d\n", contas[indiceConta].numeroConta);
        printf("Limite de Crédito: $%.2f\n", limiteCredito);
        printf("Limite de Crédito Disponível: $%.2f\n", limiteCredito - novoSaldo);
    }

    return 0;
}

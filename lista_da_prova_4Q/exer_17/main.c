#include <stdio.h>

#define CONTAS 10

typedef struct {
    int numeroConta;
    double saldoDevedor;
} Conta;

int main() {
    Conta contas[CONTAS];

    for (int i = 0; i < CONTAS; ++i) {
        contas[i].numeroConta = i + 1;
        contas[i].saldoDevedor = 0.0;
    }


    int numeroContaEscolhida;
    printf("Informe o n�mero da conta (1 a %d): ", CONTAS);
    scanf("%d", &numeroContaEscolhida);

    if (numeroContaEscolhida < 1 || numeroContaEscolhida > CONTAS) {
        printf("N�mero de conta inv�lido. Programa encerrado.\n");
        return 1;
    }

    int indiceConta = numeroContaEscolhida - 1;

    float cobrancas, creditos, limiteCredito, novoSaldo;

    printf("Informe o total de itens cobrados ao cliente no m�s: ");
    scanf("%f", &cobrancas);

    printf("Informe o total de cr�ditos aplicados � conta do cliente no m�s: ");
    scanf("%f", &creditos);

    printf("Informe o limite de cr�dito permitido: ");
    scanf("%f", &limiteCredito);

    // C�lculo do novo saldo para a conta escolhida
    novoSaldo = contas[indiceConta].saldoDevedor + cobrancas - creditos;

    // Verifica��o se o novo saldo supera o limite de cr�dito
    if (novoSaldo > limiteCredito) {
        printf("\nN�mero da Conta: %d\n", contas[indiceConta].numeroConta);
        printf("Limite de Cr�dito: $%.2f\n", limiteCredito);
        printf("Mensagem: Limite de Cr�dito Excedido\n");
    } else {
        printf("\nO novo saldo n�o excede o limite de cr�dito.\n");
        printf("\nN�mero da Conta: %d\n", contas[indiceConta].numeroConta);
        printf("Limite de Cr�dito: $%.2f\n", limiteCredito);
        printf("Limite de Cr�dito Dispon�vel: $%.2f\n", limiteCredito - novoSaldo);
    }

    return 0;
}

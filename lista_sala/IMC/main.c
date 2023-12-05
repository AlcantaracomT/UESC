/*IMC*/

#include <stdio.h>

// Fun��o que calcula o IMC de uma pessoa
float calcular_imc(float peso, float altura) {
    return peso / (altura * altura);
}

// Fun��o que imprime o status do peso de uma pessoa
void imprimir_status(float imc) {
    if (imc < 18.5) {
        printf("Abaixo do peso.\n");
    } else if (imc < 25) {
        printf("Peso normal (ideal).\n");
    } else if (imc < 30) {
        printf("Acima do peso.\n");
    } else {
        printf("Obeso.\n");
    }
}

int main(void) {
    float peso, altura, imc;

    // Entrada: peso em quilogramas
    printf("Digite o peso em quilogramas: ");
    scanf("%f", &peso);

    // Entrada: altura em metros
    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    // C�lculo do IMC
    imc = calcular_imc(peso, altura);

    // Sa�da: valor do IMC
    printf("Seu IMC �: %.2f\n", imc);

    // Sa�da: status do peso
    imprimir_status(imc);

    return 0;
}

/*IMC*/

#include <stdio.h>

//calcula o IMC
float calcular_imc(float peso, float altura) {
    return peso / (altura * altura);
}

// imprime peso
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

    printf("Digite o peso em quilogramas: ");
    scanf("%f", &peso);

    printf("Digite a altura em metros: ");
    scanf("%f", &altura);

    imc = calcular_imc(peso, altura);

    printf("Seu IMC é: %.2f\n", imc);

    imprimir_status(imc);

    return 0;
}

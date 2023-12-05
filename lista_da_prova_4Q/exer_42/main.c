#include <stdio.h>
#define quantidade 10000

double estimativa_pi(int n) {
    double soma = 0.0;
    for (int i = 0; i < n; ++i) {
        double termo = 1.0 / (double)(1 << (4*i)) * (4.0/(8*i+1) - 2.0/(8*i+4) - 1.0/(8*i+5) - 1.0/(8*i+6));
        soma += termo;
    }
    return soma;
}

int main() {

    int N = quantidade;
    double resultado = estimativa_pi(N);
    printf("A estimativa de pi com %d termos é: %f\n", N, resultado);

    return 0;
}

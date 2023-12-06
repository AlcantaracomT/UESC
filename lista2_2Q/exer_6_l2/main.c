/*6 Para arrays 3 dimensionais, desenvolva:
➢ Array de inteiros com dimensões (10, 20, 5);
➢ Preencha com valores sequenciais;
➢ Apresente os valores.*/

#include <stdio.h>
#define primerio 10
#define segunda 20
#define terceria 5

int main() {
  /*int primerio,
  segunda,
  terceria;

  printf("Digite o tamanho da primeira dimensao: ");
  scanf("%d", &primerio);

  printf("Digite o tamanho da segunda dimensao: ");
  scanf("%d", &segunda);

  printf("Digite o tamanho da terceira dimensao: ");
  scanf("%d", &terceria);*/

  int arr[primerio][segunda][terceria];

  int cont = 1;
  for (int i = 0; i < primerio; i++) {
    for (int j = 0; j < segunda; j++) {
      for (int f = 0; f < terceria; f++) {
        arr[i][j][f] = cont;
        cont++;
      }
    }
  }

  //imprimir
  for (int i = 0; i < primerio; i++) {
    for (int j = 0; j < segunda; j++) {
      for (int f = 0; f < terceria; f++) {
        printf("%d ", arr[i][j][f]);
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}

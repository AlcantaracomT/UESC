#include <stdio.h>

#define LIMITE_1 1903.98
#define LIMITE_2 2826.65
#define LIMITE_3 3751.05
#define LIMITE_4 4664.68
#define IMPOSTO_2 7.5
#define IMPOSTO_3 15
#define IMPOSTO_4 22.5
#define IMPOSTO_5 27
#define SALARIO_MINIMO 1300

int main(void) {
  float salario_bruto = 0,
        vale_alimentacao = 0,
        salario_liquido;

  printf("Digite o seu sal�rio bruto: ");
  scanf("%f", &salario_bruto);

  printf("Digite o valor do vale alimenta��o: ");
  scanf("%f", &vale_alimentacao);

  if(salario_bruto < SALARIO_MINIMO){
    printf("Trabalho escravo");
  }
  else if (salario_bruto <= LIMITE_1) {
    salario_liquido = salario_bruto + vale_alimentacao;
  }
  else if (salario_bruto <= LIMITE_2) {
    salario_liquido = (1 - IMPOSTO_2/100) * salario_bruto + vale_alimentacao;
  }
  else if (salario_bruto <= LIMITE_3) {
    salario_liquido = (1 - IMPOSTO_3/100) * salario_bruto + vale_alimentacao;
  }
  else if (salario_bruto <= LIMITE_4) {
    salario_liquido = (1 - IMPOSTO_4/100) * salario_bruto + vale_alimentacao;
  }
  else {
    salario_liquido = (1 - IMPOSTO_5/100) * salario_bruto + vale_alimentacao;
  }

  if (salario_liquido < SALARIO_MINIMO) {
    salario_liquido += (SALARIO_MINIMO - salario_liquido);
  }

  printf("O seu sal�rio l�quido �: R$%.2f\n", salario_liquido);

  return 0;
}

/*2 Crie um array unidimensional e desenvolva:
➢ Utiliza funções quando possível;
➢ Array de inteiros para 10.000 elementos;
➢ Randomicamente insira valores, entre 0 e 1000 nos elementos;
➢ Descubra quais são os três maiores e menores valores;
➢ Calcule a média, mediana (ordenação obrigatória) e desvio padrão dos valores;
➢ Apresente as informações sobre os valores repetidos (qual valor, quantidade de vezes, etc);
➢ Insira os valores em um novo array com o tamanho exato dos elementos sem repetições;
➢ Calcule novamente a média, mediana (ordenação obrigatória) e desvio padrão dos valores, reutilizando função anteriormente desenvolvida;*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define arr 100

typedef struct
{
 int  number[arr];
}Number;

int main(void) {
  Number Numero;

  int guarda=0,
  repete = 0;

  float media=0, desvio, diferenca;

  srand(time(NULL)); //muda os números a cada segundo

  //cria números aleatorios
  for(int i = 0; i < arr; i++)
  {
    Numero.number[i] = rand() % 1000;
  }

  //ordena os números em ordem crescente
  for (int i = 0; i < arr - 1; i++) {
    for (int j = i + 1; j < arr; j++) {
      if (Numero.number[j] < Numero.number[i]) {
        guarda = Numero.number[i];
        Numero.number[i] = Numero.number[j];
        Numero.number[j] = guarda;
      }
    }
  }

  //pega os três maiores e imprime
  printf("Três maiores números\n");
  for(int i = arr - 1; i > arr - 4; i--)
  {
    printf("%d\n", Numero.number[i]);
  }

  //media
  for(int i = 0; i < arr; i++)
  {
    media += Numero.number[i];
  }


  //calcula a diferença
  for(int i = 0; i < arr; i++)
  {
    diferenca = pow(Numero.number[i] - media, 2);
  }

  //calcula o desvio padrão
  desvio = sqrt(diferenca/arr);

  printf("\n");
  printf("MEDIA %.1f e o Desvio-Padrão %.1f\n", media/arr, desvio);

  //Qual numero se repete
  for(int i = 0;i < arr - 1; i++)
  {
    for(int j = i+1; j< arr; j++)
    {
      if(Numero.number[i] == Numero.number[j])
      {
        printf("\nNúmero repetio %d\n", Numero.number[i]);
        repete = Numero.number[i];
      }
    }
  }

  //imprimindo array sem numero repetido
  int cont = 0;

  printf("\n\nLista Sem Números Repetidos\n");
  for (int i = 0; i < arr; i++) {
      if (i == 0 || Numero.number[i] != Numero.number[i - 1]) {
        printf("|%d|", Numero.number[i]);
        cont++;
      }
  }

  //--------
  float novaMedia = 0,
  novaDiferenca = 0,
  novoDesvio = 0;

  // Nova média
  for (int i = 0; i < cont; i++) {
      novaMedia += Numero.number[i];
  }

  novaMedia /= cont;

  // Nova diferença
  for (int i = 0; i < cont; i++) {
      novaDiferenca += pow(Numero.number[i] - novaMedia, 2);
  }

  // Nova desvio
  novoDesvio = sqrt(novaDiferenca / cont);

  printf("\n\nNova Média: %.1f e Novo Desvio-Padrão: %.1f\n", novaMedia, novoDesvio);

  return 0;
}

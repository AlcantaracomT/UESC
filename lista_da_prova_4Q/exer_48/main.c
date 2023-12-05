#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int escolha(int arga) {
  char letra;

  do {
    scanf("%d%*c", &arga);

    if (arga == -1) {

      do {
        letra = getchar();
      } while (letra != '\n');

    }

    else if (arga == 1 || arga == 0) {
      return arga;
    }
    else
    {
      printf("ERRO!!\n");
    }

  } while (arga != 1 && arga != 0);

  return arga;
}

int jogar(int jogadas) {
  char letra;

  do {
    printf("\n\tDigite 1 para Jogar\n");
    scanf("%d%*c", &jogadas);

    if (jogadas == -1)
    {
      do
      {
        letra = getchar();
      }
      while (letra != '\n');
    }
    else if (jogadas == 1)
    {
      return 1;
    }
    else
    {
      printf("ERRO!");
      return 0;
    }
  }
  while (jogadas != 1);
  return jogadas;
}

void aleatorio(int *x, int *y) {
  srand(time(NULL));

  *x = 1 + rand() % 6;
  *y = 1 + rand() % 6;
}

int main() {
  int voltar_menu = -1, jogar_dados = 0, x = 0, y = 0;

  int jogar_dnovo = 0, cont = 0, continua = -1;

  int ponto_jogador = 0, ponto_casa = 0;

  do {
    printf("Digite 1 ou 0\n\n\t1 Jogar Dados\n\t0 Sair do jogo\n");
    jogar_dados = escolha(jogar_dados);

    if (jogar_dados == 1) {
      aleatorio(&x, &y);
      cont++;
    }

    if (jogar_dados == 0) {
      voltar_menu = 0;
    }
    if (x + y == 2 || x + y == 3 || x + y == 12 && cont == 1) {
      printf("\tPrimeiro dado foi %d\n", x);
      printf("Segundo dado foi %d\n", y);
      printf("\n\t  Tirou o número da azar %d\n\t", (x + y));
      printf("YOU LOOSE!!\n\n");
    } else if (x + y == 7 || x + y == 11) {
      printf("\tPrimeiro dado foi %d\n\t", x);
      printf("Segundo dado foi %d\n", y);
      printf("\n\t_*_*_*    Tirou o número da sorte  %d _*_*_*_*_\n", (x + y));
      printf("\n\t     Você venceu \n");
    } else if (x + y >= 4 && x + y <= 6 ||
               x + y >= 8 && x + y <= 10 && cont == 1) {
      ponto_casa = x + y;
      continua = 1;
      system("cls||clear");
      printf("Faça %d para vencer\n", ponto_casa);
      jogar_dados = jogar(jogar_dados);

      if (jogar_dados == 1) {
        int voltar = -1;

        aleatorio(&x, &y);
        ponto_jogador = x + y;

        do {

          if (ponto_casa == ponto_jogador) {
            printf("\n\tPrimeiro dado foi %d\n\t", x);
            printf("Segundo dado foi %d\n", y);
            printf("você fez %d e é igual a %d\n\n\t", ponto_jogador,
                   ponto_casa);
            printf("\n\t_*_* *_*_\n");
            printf("\n\t     Você venceu \n");
            voltar = 0;
            break;
          } else if (ponto_casa < ponto_jogador) {
            printf("\n\tPrimeiro dado foi %d\n\t", x);
            printf("Segundo dado foi %d\n\t", y);
            printf("você fez %d e é maior que %d\n\n\t", ponto_jogador,
                   ponto_casa);
            printf("YOU LOOSE\n\n");
            voltar = 0;
            break;
          } else {
            printf("\n\tPrimeiro dado foi %d\n\t", x);
            printf("Segundo dado foi %d\n\n\t", y);
            printf("você fez %d e precisa de %d para vencer\n\n\t",
                   ponto_jogador, (ponto_casa - ponto_jogador));
            voltar = 1;
          }
          jogar_dados = jogar(jogar_dados);
          aleatorio(&x, &y);
          ponto_jogador += (x + y);

        } while (voltar != 1);
      }
    }

    printf("Digite\n 1 Para voltar ao menu \n 0 Para sair\n ");
    voltar_menu = escolha(voltar_menu);

    voltar_menu = -1;
    cont = 0;
    continua = -1;
    system("cls||clear");
  } while (voltar_menu != 0);

  return 0;
}

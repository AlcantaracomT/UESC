#include <stdio.h>

int verificar()
{
  int verifi = -1;
  char letra;

  do
  {
    scanf("%d%*c", &verifi);

    if(verifi == -1)
    {
      do
     {
       letra = getchar();
     }while(letra != '\n');
    }

  }while(verifi < 0 || verifi > 20);
  return verifi;
}

int main(void) {

  int rodadas = 0;

 printf("Digite um número de 0 a 20\n >> ");
 rodadas = verificar();


    for(int i = 1; i <= rodadas; i++)
    {
     for(int j = 1; j <= rodadas ; j++)
     {
      if(i == 1 || i== rodadas || j == 1 || j == rodadas)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
     }
    printf("\n");
  }
  return 0;
}

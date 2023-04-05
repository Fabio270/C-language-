#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


void Inserir(Lista *lista)
{
    int coef, expo;
    printf("\nDigite o coeficiente do termo N (Nx^e): ");
    scanf("%d",&coef);
    printf("\nDigite o expoente do termo e (Nx^e): ");
    scanf("%d",&expo);

    adicionaFim(lista, coef, expo);
}


int main()
{
    Lista *lista = criarLista();
    int op;
    int x;
    do{
      printf("\n1 - Adicionar termo ao polinomio");
      printf("\n2 - Avaliar polinomio");
      printf("\n3 - Sair");

      printf("\n\nEscolha sua opcao: ");
      scanf("%d", &op);

      switch(op)
      {
          case 1:
            Inserir(lista);
            break;
          case 2:
            printf("\nDigite um valor para x: ");
            scanf("%d", &x);
            printf("Resultado: %.0f: ",avalia(lista, x));
            break;
      }
    }while(op<3);

    return 0;
}

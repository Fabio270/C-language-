#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"
#include "veiculo.h"
#define MAXTAM 5

struct lista
{
    Veiculo *vetorVeiculos[MAXTAM];
    int ini, fim;
};

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
        printf("Não foi possível alocar memória");
    else
    {
        lista->ini = 0;
        lista->fim = 0;
    }
    return lista;
}

//verifica se a lista está vazia
int listaVazia(Lista *lista)
{
    return (lista->fim == 0) ? 1:0;
}

int listaCheia(Lista *lista)
{
    return (lista->fim == MAXTAM) ? 1:0;
}


//insere veiculo no inicio da lista
void inserirInicio(Lista *lista, Veiculo *v)
{
    int i=0;
    if(listaCheia(lista))
        printf("A lista esta cheia! \n");
    else
    {
        for(i = lista->fim; i >= lista->ini; i--)
            lista->vetorVeiculos[i] = lista->vetorVeiculos[i-1];
        lista->vetorVeiculos[lista->ini] = v;
        lista->fim++;
        printf("Inserido com sucesso \n");
    }
}

//insere veiculo no final da lista
void inserirFinal(Lista *lista, Veiculo *v)
{
    if(listaCheia(lista))
        printf("A lista esta cheia! \n");
    else
    {
        lista->vetorVeiculos[lista->fim] = v;
        lista->fim++;
        printf("Inserido com sucesso \n");
    }
}

//insere o veiculo na posicao desejada
void inserirPosicaoEspecifica(Lista *lista, Veiculo *v, int pos)
{
    if(listaCheia(lista))
        printf("A lista esta cheia! \n");
    else
    {
        if (pos < lista->ini || pos > lista->fim)
            printf("Posicao invalida \n");
        else
        {
            for(int i=lista->fim; i>pos; i--)
                lista->vetorVeiculos[i] = lista->vetorVeiculos[i-1];
            lista->vetorVeiculos[pos] = v;
            lista->fim++;
            printf("Inserido com sucesso \n");
        }
    }
}

//remove posicao desejada
void removerPosicao (Lista *lista, int pos)
{
    if (listaVazia(lista))
        printf("Lista Vazia \n");
    else
    {
        for (int i = pos; i < lista->fim-1; i++)
            lista->vetorVeiculos[i] = lista->vetorVeiculos[i+1];
        lista->fim--;
        printf("Removido com sucesso \n");
    }
}

//remove por placa
void removerPlaca (Lista *lista, char placa[])
  {
      int indice = achaIndex(lista, placa);
      if(indice!=-1)
          {
              removerPosicao(lista,indice);
          }
  }


  ////funcao que retorna o index da placa encontrada
  int achaIndex(Lista *lista, char placa[])
  {
      int i;
          for(i = lista->ini; i<lista->fim; i++)
              {
              if(strcmp(getPlaca(lista->vetorVeiculos[i]),placa)==0)
                  return i;
              }
      return -1;
  }


//funcao mostrar
void mostrar(Lista *lista)
{
    int i;
    if (listaVazia(lista))
        printf("Lista vazia \n");
    else
       for (i=lista->ini;i<lista->fim;i++)
       {
         mostrarPlaca(lista->vetorVeiculos[i]);
         mostrarMarca(lista->vetorVeiculos[i]);
         mostrarAnoFabrica(lista->vetorVeiculos[i]);
       }
}






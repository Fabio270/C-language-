#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <math.h>
struct no
{
    int expo;
    int coef;
    struct no *prox;
};

struct lista
{
    No *inicio;
    No *fim;
};

Lista *criarLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista == NULL)
        printf("\nNao foi possivel alocar memoria para a lista\n");
    else
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return lista;
}

No * alocarNo()
{
    No *no = (No*) malloc(sizeof(No));
    if (no==NULL)
    {
        printf("\nNao foi possivel alocar memoria para o no");
    }
    return no;
}

int listaVazia(Lista *lista)
{
    return lista->inicio==NULL?1:0;
}

void adicionaFim(Lista *lista, double coeficiente, int expo)
{
    No *no = alocarNo();
    no->coef = coeficiente;
    no->expo = expo;
    no->prox = NULL;
    if(listaVazia(lista)){
        lista->inicio = no;
        lista->fim =no;
        printf("Primeiro item inserido!");
    }
    else{
        lista->fim->prox=no;
        lista->fim = no;
        printf("Item inserido!");
    }
}

double avalia(Lista *lista, double x)
{
    No *aux = lista->inicio;
    double resultado = 0;
    while(aux!= NULL)
    {
        resultado = resultado + (aux->coef*pow(x,aux->expo));
        aux = aux -> prox;
    }
    return resultado;
}






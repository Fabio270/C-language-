#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "veiculo.h"

void menuInserir(Lista *lista)
{
    char placa[10];
    char marca[15];
    int anoFabrica;
    //cria o veiculo
    printf("\n Digite a placa do carro a ser inserido: ");
    scanf("%s", placa);
    printf("\n Digite a marca do carro a ser inserido: ");
    scanf("%s", marca);
    printf("\n Digite a data de fabricacao do carro a ser inserido: ");
    scanf("%d", &anoFabrica);
    printf("\n");
    Veiculo *v = criarVeiculo(placa, marca, anoFabrica);
    //verifica se a lista esta vazia, se sim, insere no inicio
    if (listaVazia(lista))
        inserirInicio(lista, v);
    //caso contrario da as opcoes de insercao
    else
    {
        int opt, pos;
        printf("\n1 - Inserir no inicio");
        printf("\n2 - Inserir no final");
        printf("\n3 - Inserir em posicao especifica");
        printf("\n4 - Voltar");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opt);
        printf("\n");

        //switch case para as opcoes
        switch (opt)
            {
            case 1:
                inserirInicio(lista, v);
                break;
            case 2:
                inserirFinal(lista, v);
                break;
            case 3:
                printf("\nDigite a posicao: ");
                scanf("%d", &pos);
                inserirPosicaoEspecifica(lista, v, pos);
            }
    }
}

void menuRemover(Lista *lista){
    int opt, pos;
    char placa[10];
        printf("\n1 - Remover posicao");
        printf("\n2 - Remover placa");
        printf("\n3 - Voltar");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opt);
        printf("\n");

        //switch case para as opcoes
        switch (opt)
            {
            case 1:
                printf("\nDigite a posicao para remocao: ");
                scanf("%d", &pos);
                removerPosicao(lista, pos);
                break;
            case 2:
                printf("\nDigite a placa para remocao: ");
                scanf("%s",placa);
                removerPlaca(lista, placa);
                break;
            }
}


int main()
{
    Lista *lista = criarLista();

    int op, pos;
     do
    {
        printf("\n 1- Inserir ");
        printf("\n 2 - Remover ");
        printf("\n 3 - Mostrar ");
        printf("\n 4 - Sair ");
        printf("\n Escolha a sua opcao: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            menuInserir(lista);
            break;
        case 2:
            menuRemover(lista);
            break;
        case 3:
            mostrar(lista);
            break;
        }

    } while (op <= 3);

    return 0;
}

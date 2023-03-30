#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "veiculo.h"

struct veiculo
{
    char placa[10];
    char marca[15];
    int anoFabrica;
};

Veiculo *criarVeiculo(char placa[], char marca[], int anoFabrica)
{
    Veiculo *v = (Veiculo *)malloc(sizeof(Veiculo));
    if(v==NULL) {
        printf("Nao foi possivel alocar memoria");
    } else {
        strcpy(v->placa, placa);
        strcpy(v->marca, marca);
        v->anoFabrica = anoFabrica;
    }
    return v;
}

void mostrarPlaca(Veiculo *v)
{
    printf("\nPlaca do Veiculo:%s \n", v->placa);
}

void mostrarMarca(Veiculo *v)
{
    printf("Marca do Veiculo:%s \n", v->marca);
}

void mostrarAnoFabrica(Veiculo *v)
{
    printf("Ano de fabricacao do Veiculo:%d \n", v->anoFabrica);
}

char *getPlaca(Veiculo *v){
    return v->placa;
}

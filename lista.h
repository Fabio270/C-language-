#include "veiculo.h"
typedef struct lista Lista;

Lista *criarLista();

void inserirInicio(Lista *lista, Veiculo *v);
void inserirFinal(Lista *lista, Veiculo *v);
void inserirPosicaoEspecifica(Lista *lista, Veiculo *v, int pos);
void removerPosicao (Lista *lista, int pos);
void removerPlaca (Lista *lista, char placa[]);
int achaIndex(Lista *lista, char placa[]);
void mostrar (Lista *lista);
int listaVazia(Lista *lista);
int listaCheia(Lista *lista);

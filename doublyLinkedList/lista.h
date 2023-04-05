typedef struct no No;

typedef struct lista Lista;

Lista * criarLista();
void adicionaFim(Lista *lista, double coeficiente, int expo);
double avalia(Lista *Lista, double x);
int listaVazia(Lista *lista);
No * alocarNo();

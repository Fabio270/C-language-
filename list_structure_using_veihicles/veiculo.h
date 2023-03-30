typedef struct veiculo Veiculo;

Veiculo *criarVeiculo(char placa[], char marca[], int anoFabrica);

void mostrarPlaca(Veiculo *v);
void mostrarMarca(Veiculo *v);
void mostrarAnoFabrica(Veiculo *v);
char *getPlaca(Veiculo *v);

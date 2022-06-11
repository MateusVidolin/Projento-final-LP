struct produto{
    int codigo;
    char descricao[61];
    char fornecedor[61];
    int quantidadeEstoque;
    double precoMedio;
    double precoCompra;
    double valorVenda;


};
typedef struct produto Produto;

void inicializar(Produto *p[], int tamanho);

int cadastrar(Produto *p[], int posicao);

void listar(Produto *p[], int tamanho);

void encontrar(Produto *p[],int tamanho, int codigo);

void comprar(Produto *p[], int tamanho, int codigo, int qtd, double valorCompra);

void vender(Produto *p[], int tamanho, int codigo, int qtd, double precoVenda);

void imprimir(Produto *p);

int mostraProduto(Produto *p[], int tamanho, int codigo);

void pulaLinha(qtdN);

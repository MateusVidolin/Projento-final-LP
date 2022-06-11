#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "produto.h"

float margemLucro = 1.3;

void inicializar(Produto *p[], int tamanho){
    setlocale (LC_ALL,"");
    for(int i=0; i<tamanho; i++){
        p[i] = NULL;
    }
}

int cadastrar(Produto *p[], int posicao){
char decideCompra;
int qtd, codproc, codigo;
double preco;
    p[posicao] = (Produto*) malloc(sizeof(Produto));
    fflush(stdin);
    printf(" Digite o código\n  do Produto >> ");
    scanf("%d", &codigo);
    for(int i=0; i<= posicao; i++){
        if(p[i]->codigo == codigo){
            system("cls");
            puts("\n CÓDIGO JÁ CADASTRADO\n");
            pulaLinha(6);
			puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
			getch();
            return -10;
        }
    }
	codproc = codigo;
	p[posicao]->codigo = codigo;

    fflush(stdin);
    printf(" Digite a Descrição\n  do Produto >> ");
    scanf("%[^\n]", p[posicao]->descricao);

    fflush(stdin);
    printf(" Digite o Fornecedor\n  do Produto >> ");
    scanf("%[^\n]", p[posicao]->fornecedor);

    do{
		fflush(stdin);
		printf("\n Será realizada a Compra do Produto? (S)im ou (N)ão: ");
		decideCompra = getchar();
    }while(decideCompra!='N' && decideCompra!='n' && decideCompra!='S' && decideCompra!='s');

    if (decideCompra=='S' || decideCompra=='s') return codproc;
    return 0;
}

void listar(Produto *p[], int tamanho){
    for(int i=0; i<tamanho; i++){
        imprimir(p[i]);
    }
    pulaLinha(6);
	puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
	getch();
}

void encontrar(Produto *p[],int tamanho, int codigo){
    for(int i=0; i<tamanho; i++){
        if(p[i]->codigo == codigo){
			imprimir(p[i]);
			pulaLinha(6);
			puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
			getch();
            return;
        }
    }
    printf(" Codigo Não Encontrado \n");
    pulaLinha(10);
	puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
	getch();
}

void comprar(Produto *p[], int tamanho, int codigo, int qtd, double valorCompra){

    for(int i=0; i<=tamanho; i++){
        if(p[i]->codigo == codigo){
			if(p[i]->quantidadeEstoque){
            p[i]->precoMedio = ((p[i]->quantidadeEstoque * p[i]->precoCompra) + (valorCompra * qtd)) / (qtd + p[i]->quantidadeEstoque);
            p[i]->quantidadeEstoque += qtd;
            p[i]->precoCompra = valorCompra;
            system("cls");
            printf("\n\n\n Compra Realizada com Sucesso\n");
            pulaLinha(10);
			puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
			getch();
            return;
			}
			p[i]->precoCompra = valorCompra;
			p[i]->precoMedio = valorCompra;
			p[i]->quantidadeEstoque += qtd;
			system("cls");
            printf("\n\n\n Compra Realizada com Sucesso\n");
            pulaLinha(10);
			puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
			getch();
			return;
        }
    }
    system("cls");
    printf(" Codigo não Encontrado \n");
    pulaLinha(6);
	puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
	getch();
    return;
}

void vender(Produto *p[], int tamanho, int codigo, int qtd, double precoVenda){

     for(int i=0; i<=tamanho; i++){
        if(p[i]->codigo == codigo){
            if(p[i]->quantidadeEstoque >= qtd){
                p[i]->quantidadeEstoque -= qtd;
                p[i]->valorVenda = precoVenda;
                system("cls");
                printf("\n\n\n Venda Concluída com Sucesso \n");
				pulaLinha(6);
				puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
                getch();
            return;
            }
            else{
				system("cls");
				puts(" Quantidade Insuficiente\n\n");
				pulaLinha(6);
				puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
				getch();
				return;
            }
        }
    }
    printf(" Codigo Não Encontrado \n");
}

void imprimir(Produto *p){
double valorVenda;

    printf("\n CÓDIGO >> %d ", p->codigo);
    printf(" DESCRIÇÃO >> %s \n", p->descricao);
    printf(" FORNECEDOR >> %s \n", p->fornecedor);
    printf(" QUANTIDADE EM ESTOQUE >> %d \n", p->quantidadeEstoque);
    printf(" PREÇO UNITÁRIO DA ULTIMA COMPRA >> R$ %.2f \n", p->precoCompra);
    printf(" PREÇO UNITÁRIO DA ULTIMA VENDA >> R$ %.2f", p->valorVenda);
    printf(" PREÇO MÉDIO >> R$ %.2f \n", p->precoMedio);
    printf(" PREÇO SUGERIDO PARA VENDA >> R$ %.2f \n", p->precoMedio * margemLucro );
    printf("\n-------------------------------------------------------\n");
}

int mostraProduto(Produto *p[], int tamanho, int codigo){

	for(int i=0; i<tamanho; i++){
        if(p[i]->codigo == codigo){
			printf(" DESCRIÇÃO >> %s \n", p[i]->descricao);
			printf(" ESTOQUE >> %d \n", p[i]->quantidadeEstoque);
			printf(" PREÇO SUGERIDO PARA VENDA >> R$ %.2f\n", p[i]->precoMedio * margemLucro);
			printf("\n-------------------------------------------------\n");
			return;
        }
	}
	printf(" Codigo não Encontrado \n");
	return 1;
}

void pulaLinha(qtdN){
	for(int i=0; i<qtdN; i++) puts("\n");
}

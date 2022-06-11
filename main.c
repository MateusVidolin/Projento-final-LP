#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#define T 1000
#include "produto.h"
// LINGUAGEM DE PROGRAMAÇAO
// ADS - NOITE
// ALUNOS:
// JOAO CARLOS FERREIRA FELIX - RA 163082123009
// MATEUS HENRIQUE VIDOLIN - RA 1630482123043
// Higor de Oliveira Gonçalves - Ra: 1630482213020
int main(){
    setlocale (LC_ALL,"");

    Produto * vetProd[T];
    inicializar(vetProd, T);
    int pos = 0;
    int opc = 0;
    int codproc = 0;
    int qtd = 0;
    double preco;
    double precoVenda;
    do{
		fflush(stdin);
		system("cls");
        printf(" =================================\n\tMENU PRINCIPAL\n\ =================================\n");
        printf("  >>>1. CADASTRAR\n\n");
        printf("  >>>2. LISTAR\n\n");
        printf("  >>>3. ENCONTRAR\n\n");
        printf("  >>>4. COMPRAR\n\n");
        printf("  >>>5. VENDER\n\n");
        printf("  >>>9. SAIR\n\n");
        printf("\n Digite uma das\n  opções acima >> ");
        scanf("%d", &opc);
        system ("cls");
        printf("\n");
        switch(opc){
            case 1:
                printf(" ====================================================\n");
                printf("\tCADASTRAR\n");
                codproc = cadastrar(vetProd, pos);
                        if(codproc == -10)break;
                        else if(codproc){
                                printf(" Digite a quantidade da Compra >> ");
                                scanf("%d", &qtd);
                                printf(" Digite o valor unitário do Produto >> ");
                                scanf("%lf", &preco);
                                comprar(vetProd, pos, codproc, qtd, preco);
                        }
                system("cls");
                printf("\n Produto Cadastrado com Sucesso\n");
                pulaLinha(10);
                puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
                getch();
                pos++;
                break;
            case 2:
                printf(" ====================================================\n");
                printf("\tLISTA DE PRODUTOS\n");
                listar(vetProd, pos);
                break;
            case 3:
                fflush(stdin);
               printf(" ====================================================\n");
                printf("\tENCONTRAR\n");
                printf(" Digite o codigo\n  do produto a Procurar >> ");
                scanf("%d", &codproc);
                encontrar(vetProd, pos, codproc);
                break;
            case 4:
                fflush(stdin);
                printf(" ====================================================\n");
                printf("\tCOMPRAR\n");
                printf(" Digite o codigo\n  do produto a Comprar >> ");
                scanf("%d", &codproc);
                if (mostraProduto(vetProd, pos, codproc)){
                        puts(" PRODUTO NÃO CADASTRADO\N Cadastre o produto primeiro\n");
                        pulaLinha(6);
                        puts(" Pressione qualquer tecla para voltar ao MENU INICIAL");
                        getch();
                        break;
                }
                printf("\n Digite a quantidade da Compra >> ");
                scanf("%d", &qtd);
                printf(" Digite o valor unitário do Produto >> ");
                scanf("%lf", &preco);
                comprar(vetProd, pos, codproc, qtd, preco);

                break;
            case 5:
                fflush(stdin);
                printf(" ====================================================\n");
                printf("\tVENDER\n");
                printf(" Digite o codigo\n  do produto a Vender >> ");
                scanf("%d", &codproc);
                fflush (stdin);
                        if(mostraProduto(vetProd, pos, codproc)){
                                puts(" Produto Não Cadastrado\n");
                                pulaLinha(6);
                                puts(" Pressione qualquer tecla para voltar ao MENU INICIL");
                                getch();
                                break;
                        }
                printf(" Digite a Quantidade da Venda >> ");
                scanf("%d", &qtd);
                printf(" Digite o Preço Unitário da Venda >> ");
                scanf("%lf", &precoVenda);
                vender(vetProd, pos, codproc, qtd, precoVenda);
                break;

            case 9:
                printf(" ====================================================\n");
                printf("\n\t FIM DO PROGRAMA \n");
                printf("\n");
                break;
            default:
                printf(" ====================================================\n");
                printf(" Opção Inválida \n");

        }
    }while(opc!=9);
    printf(" ====================================================\n");
    return 0;
}

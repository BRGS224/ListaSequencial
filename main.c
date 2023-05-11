#include <stdlib.h>
#include "main.h"

int main(){
    FILE *fp;
    Pessoa *clientes=NULL;
    int quant_clientes,op=-1;
    fp=fopen("NomeRG100M.txt","r");
    inicializa_lista(fp,&clientes,&quant_clientes);
    while (op!=0)
    {
        printf("Informe a sua opcao:\n");
        printf("1 - Inserir um cliente no inicio\n");
        printf("2 - Inserir um cliente no final da lista\n");
        printf("3 - Inserir um cliente na posicao desejada\n");
        printf("4 - Remover uma pessoa no inicio da lista\n");
        printf("5 - Remover uma pessoa no final da lista\n");
        printf("6 - Remover uma pessoa na posicao desejada\n");
        printf("7 - Procurar uma pessoa\n");
        printf("8 - Mostrar a lista na tela\n");
        printf("9 - Salvar a lista\n");
        printf("0 - Sair do Sistema\n");
        scanf("%d",&op);

        switch (op){
        case 0:{
            printf("Fim do programa  \n");
        }
            break;
        case 1:{
            insere_inicio(clientes,&quant_clientes);
        }
            break;
        case 2:{
            insere_fim(clientes,&quant_clientes);
        }
            break;
        case 3:{
            insere_n(clientes,&quant_clientes);
        }
            break;
        case 4:{
            remove_inicio(clientes,&quant_clientes);
        }
            break;
        case 5:{
            remove_fim(clientes,&quant_clientes);
        }
            break;
        case 6:{
            remove_n(clientes,&quant_clientes);
        }
            break;
        case 7:{
            procura_cliente(clientes,&quant_clientes);
        }
            break;
        case 8:{
            imprime_lista(clientes,&quant_clientes);
        }
            break;
        case 9:{
            salva_lista(clientes,"NomeRG10.txt",&quant_clientes);
        }
            break;
        default:
            break;
        }

    }
    free(clientes);
    return 0;
}


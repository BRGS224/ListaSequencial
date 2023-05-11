#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define TAM_LINE 100

typedef struct pessoa{
    char nome[30];
    int id;
}Pessoa;

void inicializa_lista(FILE *fp,Pessoa **pessoas,int *quant_pessoas){
    char line[TAM_LINE];
    int tam=0;
    *quant_pessoas = 0;
    if(fp==NULL){
        printf("Erro ao abri o arquivo\n");
        return;
    }
    while (fgets(line,TAM_LINE, fp) != NULL) {
          tam++;
        }
    rewind(fp);
    *pessoas = calloc(tam, sizeof(Pessoa));
    if(*pessoas == NULL){
        printf("Erro ao alocar memoria\n");
        return;
    }

    while(fgets(line,TAM_LINE,fp)!=NULL) {
        sscanf(line, "%[^,],%d", (*pessoas)[*quant_pessoas].nome, &(*pessoas)[*quant_pessoas].id);
        (*quant_pessoas)++;
    }
}

void insere_inicio(Pessoa pessoas[], int *quant_pessoas){
    Pessoa nova_pessoa;
    int c=0,m=0;
    clock_t inicio_execucao, fim_execucao;
    double tempo_execucao;

    printf("Digite os dads do cliente:\n");
    scanf("%s %d", nova_pessoa.nome, &nova_pessoa.id);
    inicio_execucao = clock();
    for(int i=*quant_pessoas; i >= 0; i--){
        pessoas[i] = pessoas[i-1];
        m++;
    }
    pessoas[0] = nova_pessoa;
    (*quant_pessoas)++;

    fim_execucao = clock();
    tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente adicionado com sucesso!\n");
    printf("%s %d\n",nova_pessoa.nome,nova_pessoa.id);
    printf("Tempo de execucao da funcao: %f segundos\n",tempo_execucao);
    printf("%d movimentacoes\n", m);
    printf("%d comparacoes\n",c);
    printf("Esta na posicao 1\n");
}
void insere_fim(Pessoa pessoas[], int *quant_pessoas){
    Pessoa nova_pessoa;
    int c=0,m=0;
    clock_t inicio_execucao,fim_execucao;

    printf("Digite os dados do cliente:\n");
    scanf("%s %d", nova_pessoa.nome, &nova_pessoa.id);

    inicio_execucao = clock();
    pessoas[*quant_pessoas] = nova_pessoa;
    fim_execucao = clock();

    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
    m++;

    printf("Cliente adicionado com sucesso!\n");
    printf("%s %d\n",nova_pessoa.nome,nova_pessoa.id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d movimentacoes\n",m);
    printf("%d comparacoes\n",c);
    (*quant_pessoas)++;
    printf("Esta na posicao %d\n",*quant_pessoas);

}

void insere_n(Pessoa pessoas[], int *quant_pessoas){
    Pessoa nova_pessoa;
    int posicao,c=0,m=0;
    clock_t inicio_execucao,fim_execucao;

    printf("Digite a posicao desejada:\n");
    scanf("%d",&posicao);

    inicio_execucao = clock();

    if(posicao < 1 || posicao > *quant_pessoas + 1){
        printf("Posi��o inv�lida\n");
        return;
    }
    c++;
    printf("Digite os dados do cliente:\n");
    scanf("%s %d",nova_pessoa.nome, &nova_pessoa.id);

    for(int i=*quant_pessoas; i >= posicao; i--){
        pessoas[i] = pessoas[i-1];
        m++;
        c++;
    }
    pessoas[posicao-1] = nova_pessoa;
    m++;
    fim_execucao = clock();
    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente adicionado com sucesso!\n");
    printf("%s %d\n",nova_pessoa.nome,nova_pessoa.id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d movimentacoes\n",m);
    printf("%d comparacoes\n",c);
    printf("Esta na posicao %d\n",posicao);
    (*quant_pessoas)++;

}
void remove_inicio(Pessoa pessoas[], int *quant_pessoas){
    int c=0,m=0,i=0;
    clock_t inicio_execucao,fim_execucao;
    inicio_execucao=clock();
    if(*quant_pessoas == 0){
        printf("Lista vazia\n");
    return;
    }
    c++;
    Pessoa removido=pessoas[i];
    for(i=0; i < *quant_pessoas - 1; i++){
        pessoas[i] = pessoas[i+1];
        m++;
    }
    (*quant_pessoas)--;

    fim_execucao=clock();
    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente removido com sucesso!\n");
    printf("%s %d\n",removido.nome,removido.id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d movimentacoes\n",m);
    printf("%d comparacoes\n",c);
    printf("Estava na posicao 1\n");
}

void remove_fim(Pessoa pessoas[], int *quant_pessoas){
    int c=0,m=0;
    clock_t inicio_execucao,fim_execucao;
    inicio_execucao=clock();
    Pessoa removido=pessoas[*quant_pessoas-1];

    c++;
    if(*quant_pessoas == 0){
        printf("Lista vazia\n");
        return;
    }
    (*quant_pessoas)--;
    fim_execucao=clock();
    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente removido com sucesso!\n");
    printf("%s %d\n",removido.nome,removido.id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d movimentacoes\n",m);
    printf("%d comparacoes\n",c);
    printf("Estava na posicao %d\n",*quant_pessoas+1);
}

void remove_n(Pessoa pessoas[], int *quant_pessoas){
    int posicao,c=0,m=0;
    clock_t inicio_execucao,fim_execucao;
    inicio_execucao=clock();

    Pessoa removido;
    printf("Escolha a posicao:\n");
    scanf("%d",&posicao);
    inicio_execucao=clock();
    c++;
    if (posicao < 0 || posicao > *quant_pessoas) {
        printf("Posicao invalida\n");
        return;
    }
    removido=pessoas[posicao-1];
    for (int i = posicao-1; i < *quant_pessoas-1; i++) {
        pessoas[i] = pessoas[i+1];
        m++;
    }
    (*quant_pessoas)--;
    fim_execucao=clock();
    double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;

    printf("Cliente removido com sucesso!\n");
    printf("%s %d\n",removido.nome,removido.id);
    printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
    printf("%d movimentacoes\n",m);
    printf("%d comparacoes\n",c);
    printf("Estava na posicao %d\n",posicao+1);
}

void procura_cliente(Pessoa pessoas[],int* quant_pessoas){
    int i,rg,c=0,m=0;
    clock_t inicio_execucao,fim_execucao;


    printf("Digite o Rg a ser procurado:\n");
    scanf("%d",&rg);
    inicio_execucao=clock();
    for(i=0;i<*quant_pessoas;i++){
        c++;
        if(pessoas[i].id==rg){
             fim_execucao=clock();
             double tempo_execucao = (double)(fim_execucao - inicio_execucao) / CLOCKS_PER_SEC;
             printf("%s %d\n",pessoas[i].nome,pessoas[i].id);
             printf("Cliente encontrado!\n");
             printf("Tempo de execucao: %lf segundos\n", tempo_execucao);
             printf("%d movimentacoes\n",m);
             printf("%d comparacoes\n",c);
             printf("Estava na posicao %d\n",i+1);
             return;
        }
    }
    printf("Cliente nao encontrado!\n");
}

void salva_lista(Pessoa pessoas[], char *arquivo,int *quant_pessoas) {
    FILE *fp = fopen(arquivo, "w");
    if (fp == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }
    for(int i=0;i<*quant_pessoas;i++){
        fprintf(fp,"%s,%d\n",pessoas[i].nome,pessoas[i].id);
    }
    fclose(fp);
    printf("Lista salva com sucesso!\n");
}

void imprime_lista(Pessoa pessoas[], int *quant_pessoas){
    for(int i=0; i < *quant_pessoas; i++){
        printf("%s,%d\n", pessoas[i].nome, pessoas[i].id);
    }
}







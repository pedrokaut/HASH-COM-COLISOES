#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_TABELA 10//definindo o tamanho da tabela
#define TAM_CHAVE  50

typedef struct No {
    char chave[TAM_CHAVE];
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* lista[TAM_TABELA];
} TabelaHash;


//area dos prototipos das funcao
void inicializar(TabelaHash* th);
void inserir(TabelaHash* th, const char* chave, int valor);
int hashDobra(const char* chave);
int buscar(TabelaHash* tabela, const char* chave, int* valor);
int remover(TabelaHash* tabela, const char* chave);
void imprimirTabela(TabelaHash* tabela);
void liberarTabela(TabelaHash* tabela);


int main() {
    setlocale(LC_ALL, "portuguese");
    TabelaHash th;
    inicializar(&th);

    inserir(&th, "ana", 10);
    inserir(&th, "aan", 20);
    inserir(&th, "nan", 30);
    inserir(&th, "mar", 40);
    inserir(&th, "ram", 50);
    
    imprimirTabela(&th);

    int valor;
    if (buscar(&th, "aan", &valor))
        printf("Valor de 'aan': %d\n", valor);
    else
        printf("Chave 'aan' não encontrada.\n");

    remover(&th, "ana");
    printf("\nApós remover 'ana':\n");
    imprimirTabela(&th);

    liberarTabela(&th); 
    return 0;
}

void inserir(TabelaHash* th, const char* chave, int valor) {
    int indice = hashDobra(chave);//alteração da variavel antes chamada de "hash" agora "hashDobra"
    No* atual = th->lista[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            atual->valor = valor;
            printf("Atualizando chave '%s' no índice %d com valor %d\n", chave, indice, valor);
            return;
        }
        atual = atual->prox;
    }
    
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(novo->chave, chave, TAM_CHAVE - 1);
    novo->chave[TAM_CHAVE - 1] = '\0';
    novo->valor = valor;

    if (th->lista[indice] != NULL) {
        printf("Colisão detectada ao inserir chave '%s' no índice %d\n", chave, indice);
    }

    novo->prox = th->lista[indice];
    th->lista[indice] = novo;

    printf("Inserindo chave '%s' no índice %d com valor %d\n", chave, indice, valor);
}

void inicializar(TabelaHash* th) {
    for (int i = 0; i < TAM_TABELA; i++)
        th->lista[i] = NULL;
    }

int hashDobra(const char* chave) {
        int soma = 0;
        int agrupado = 0;
        int contador = 0;
    
        for (int i = 0; chave[i] != '\0'; i++) {
            agrupado = agrupado * 100 + (int)chave[i];
            contador++;
    
            if (contador == 2) {
                soma += agrupado;
                agrupado = 0;
                contador = 0;
            }
        }
    
        if (contador > 0) {
            soma += agrupado;
        }
    
        return soma % TAM_TABELA;
    }

int buscar(TabelaHash* tabela, const char* chave, int* valor) {
    int indice = hashDobra(chave);
    No* atual = tabela->lista[indice];// troca da variavel antes chamada "elementos" agora "lista"

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            *valor = atual->valor;
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

int remover(TabelaHash* tabela, const char* chave) {
    int indice = hashDobra(chave);
    No* atual = tabela->lista[indice];
    No* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela->lista[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return 1;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return 0;
}

void imprimirTabela(TabelaHash* tabela) {
    printf("Tabela Hash (método da dobra):\n");
    for (int i = 0; i < TAM_TABELA; i++) {
        printf("[%d]:", i);
        No* atual = tabela->lista[i];
        while (atual != NULL) {
            printf(" (%s, %d)", atual->chave, atual->valor);
            atual = atual->prox;
        }
        printf("\n");
    }
}

void liberarTabela(TabelaHash* tabela) {
    for (int i = 0; i < TAM_TABELA; i++) {
        No* atual = tabela->lista[i];
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        tabela->lista[i] = NULL;
    }
}

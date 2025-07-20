#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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


int main() {
    TabelaHash th;
    inicializar(&th);

    inserir(&th, "ana", 10);
    
    
    imprimir(&th);

    int valor;
    if (buscar(&th, "ana", &valor))
        printf("Valor de ana: %d\n", valor);

    remover(&th, "ana");
    imprimir(&th);

    liberar(&th); 
    return 0;
}

void inserir(TabelaHash* th, const char* chave, int valor) {
    int indice = hash(chave);
    No* atual = th->lista[indice];
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            atual->valor = valor;
            return;
        }
        atual = atual->prox;
    }
    No* novo = (No*)malloc(sizeof(No));
    strncpy(novo->chave, chave, TAM_CHAVE - 1);
    novo->chave[TAM_CHAVE - 1] = '\0';
    novo->valor = valor;
    novo->prox = th->lista[indice];
    th->lista[indice] = novo;
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
    No* atual = tabela->elementos[indice];

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            *valor = atual->valor;
            return 1;
        }
        atual = atual->prox;
    }
    return 0;
}

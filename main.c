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

int hash(const char* chave) {
unsigned long hash = 0;
for (int i = 0; chave[i] != '\0'; i++) {
hash = hash * 31 + chave[i];
}
return (int)(hash % TAM_TABELA);
}

//area dos prototipos das funcao
void inicializar(TabelaHash* th);
void inserir(TabelaHash* th, const char* chave, int valor);

int main() {
    TabelaHash th;
    inicializar(&th);

    inserir(&th, "joao", 10);


    imprimir(&th);

    int valor;
    if (buscar(&th, "ana", &valor))
        printf("Valor de ana: %d\n", valor);

    remover(&th, "maria");
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

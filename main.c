#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TABELA 10
#define TAM_CHAVE  50

typedef struct No {
    char chave[TAM_CHAVE];
    int valor;
    struct No* prox;
} No;

typedef struct {
    No* lista[TAM_TABELA];
} TabelaHash;
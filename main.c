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
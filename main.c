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

int hash(const char* chave) {
unsigned long hash = 0;
for (int i = 0; chave[i] != '\0'; i++) {
hash = hash * 31 + chave[i];
}
return (int)(hash % TAM_TABELA);
}
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
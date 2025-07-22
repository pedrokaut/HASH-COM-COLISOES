# IMPLEMENTAÇÃO DE TABELA HASH COM COLISÕES

![Linguagem C](https://img.shields.io/badge/Linguagem-C-blue.svg?logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Concluído-brightgreen)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green.svg)
![Suporte](https://img.shields.io/badge/Suporte-Windows%20%7C%20Linux-blue)


# Estrutura de Dados: Tabela Hash em C

Este repositório contém a implementação de **tabelas hash** em linguagem **C**, incluindo as principais técnicas de **A definir**, como **A definir** e **A definir**, utilizando duas abordagens distintas de código para fins didáticos e comparativos.

---

## Descrição

Uma **tabela hash** é uma estrutura de dados eficiente que permite armazenar e acessar dados em tempo próximo de **O(1)**. Ela utiliza uma **função hash** para mapear chaves a índices de um vetor. Como o número de chaves é geralmente maior que o tamanho da tabela, ocorrem **colisões**, que são tratadas por técnicas específicas.

---

## Conceitos Essenciais

- **Tabela Hash**: Estrutura de dados que associa chaves a valores, permitindo buscas rápidas através de uma função hash que calcula o índice onde os dados serão armazenados.

- **Função Hash (Hashing)**: Função que transforma uma entrada (chave) em um índice numérico, distribuindo uniformemente os dados na tabela para otimizar o acesso.

- **Método da Dobra**: Técnica de hashing que divide a chave em partes (grupos de caracteres), soma essas partes e aplica o módulo pelo tamanho da tabela para gerar o índice.

- **Tratamento de Colisões**: Quando duas chaves diferentes geram o mesmo índice, o método da dobra usa encadeamento (listas ligadas) para armazenar múltiplos elementos nesse índice.

- **Lista Encadeada**: Estrutura dinâmica onde cada nó aponta para o próximo, permitindo armazenar múltiplos elementos em um mesmo índice da tabela.

- **Alocação Dinâmica de Memória**: Uso de `malloc` para criar nós da lista ligados em tempo de execução, permitindo flexibilidade no tamanho da tabela.

- **Liberação de Memória**: Importante para evitar vazamentos, consiste em desalocar a memória alocada dinamicamente após o uso, com a função `free`.

- **Complexidade**: Busca, inserção e remoção geralmente são feitas em tempo constante O(1), mas podem ser O(n) no pior caso devido a colisões.


---

## Funcionalidades
- Inserção de pares chave-valor  
- Busca de valores por chave  
- Remoção de chaves  
- Impressão da tabela hash  
- Liberação da memória alocada 

## integrantes

Pedro Victor Soares Gonçalo

Pablo Ryan Lopes Vieira

Jennefhy Saiury de Lima Pontes

Samuel Sarmento Ferreira


---

## Como Compilar e Executar

### Pré-requisitos

- Compilador C instalado (ex: GCC)


## 🪟 Windows

1. Abra o PowerShell ou Prompt de Comando (cmd)
2. Navegue até a pasta do projeto:

   ```powershell
   cd C:\Users\seunome\HASH-COM-COLISOES
   ```
3. Compile o projeto:

   ```powershell
   gcc main.c -o main.exe
   ```
4. Execute o programa:

   ```powershell
   .\main.exe
   ```

---

## 🐧 Linux

1. Abra o terminal
2. Navegue até a pasta do projeto:

   ```bash
   cd ~/HASH-COM-COLISOES
   ```
3. Compile o projeto:

   ```bash
   gcc main.c -o main
   ```
4. Execute o programa:

   ```bash
   ./main
   ```

<br>

---


### Clonar o repositório

```bash
git clone https://github.com/pedrokaut/HASH-COM-COLISOES.git
cd HASH-COM-COLISOES

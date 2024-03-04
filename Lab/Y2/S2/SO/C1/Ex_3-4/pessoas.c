#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if (argc < 3) {
    printf("Usage:\n");
    printf("Add new person: ./pessoas -i [name] [age]\n");
    printf("List N persons: ./pessoas -l [N]\n");
    printf("Change person age: ./pessoas -u [name] [age]\n");
    printf("Change person age (v2): ./pessoas -o [position] [age]\n");
    return 1;
  }

  const char *filename = "pessoas.txt";

  if (strcmp(argv[1], "-i") == 0) {
    Pessoa pessoa;
    strcpy(pessoa.nome, argv[2]);
    pessoa.idade = atoi(argv[3]);
    adicionarPessoa(filename, &pessoa);
  }

  if (strcmp(argv[1], "-l") == 0) {
    int n = atoi(argv[2]);
    listarPessoas(filename, n);
  }

  if (strcmp(argv[1], "-u") == 0) {
    const char *nome = argv[2];
    int novaIdade = atoi(argv[3]);
    atualizarIdade(filename, nome, novaIdade);
  }

  if (strcmp(argv[1], "-o") == 0) {
    int offset = atoi(argv[2]);
    int novaIdade = atoi(argv[3]);
    atualizarIdadeF(filename, offset, novaIdade);
  }

  return 0;
}

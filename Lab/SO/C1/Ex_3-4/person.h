#ifndef PERSON_H
#define PERSON_H

typedef struct {
  char nome[50];
  int idade;
} Pessoa;

void adicionarPessoa(const char *filename, Pessoa *pessoa);
void listarPessoas(const char *filename, int n);
void atualizarIdade(const char *filename, const char *nome, int novaIdade);
void atualizarIdadeF(const char *filename, int offset, int novaIdade);

#endif

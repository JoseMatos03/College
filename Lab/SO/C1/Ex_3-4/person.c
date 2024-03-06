#include "person.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void adicionarPessoa(const char *filename, Pessoa *pessoa) {
  int fd = open(filename, O_CREAT | O_WRONLY, 0644);
  off_t offset = lseek(fd, 0, SEEK_END);
  write(fd, pessoa, sizeof(Pessoa));

  printf("registo %lld\n", offset);
  close(fd);
}

void listarPessoas(const char *filename, int n) {
  int count = 0;
  Pessoa pessoa;

  int fd = open(filename, O_RDONLY, 0644);
  while (read(fd, &pessoa, sizeof(Pessoa)) != 0 && count < n) {
    printf("Nome: %s, Idade: %d\n", pessoa.nome, pessoa.idade);
    count++;
  }

  close(fd);
}

void atualizarIdade(const char *filename, const char *nome, int novaIdade) {
  Pessoa pessoa;

  int fd = open(filename, O_RDWR, 0644);
  while (read(fd, &pessoa, sizeof(Pessoa)) != 0) {
    if (strcmp(pessoa.nome, nome) == 0) {
      pessoa.idade = novaIdade;
      lseek(fd, -sizeof(pessoa), SEEK_CUR);
      write(fd, &pessoa, sizeof(Pessoa));
      break;
    }
  }

  close(fd);
}

void atualizarIdadeF(const char *filename, int offset, int novaIdade) {
  Pessoa pessoa;

  int fd = open(filename, O_RDWR, 0644);
  lseek(fd, offset, SEEK_SET);
  read(fd, &pessoa, sizeof(Pessoa));

  pessoa.idade = novaIdade;
  lseek(fd, offset, SEEK_SET);
  write(fd, &pessoa, sizeof(Pessoa));

  close(fd);
}

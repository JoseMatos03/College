#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define ROWS 10
#define COLS 1000

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Uso: %s <numero>\n", argv[0]);
    return 1;
  }

  int target = atoi(argv[1]);
  int matrix[ROWS][COLS];
  pid_t pid;
  int found[ROWS] = {0};

  // Inicializa a semente para gerar números aleatórios
  srand(time(NULL));

  // Preenche a matriz com números aleatórios
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      matrix[i][j] = rand() % 1000; // Números aleatórios de 0 a 999
    }
  }

  // Cria processos para procurar o número na matriz
  for (int i = 0; i < ROWS; i++) {
    pid = fork();

    if (pid == 0) {
      // Código executado pelo processo filho
      for (int j = 0; j < COLS; j++) {
        if (matrix[i][j] == target) {
          found[i] = 1;
          break;
        }
      }
      // Saída do processo filho
      exit(0);
    } else if (pid < 0) {
      fprintf(stderr, "Erro ao criar processo filho\n");
      return 1;
    }
  }

  // Código executado pelo processo pai
  for (int i = 0; i < ROWS; i++) {
    int status;
    wait(&status);
    if (found[i]) {
      printf("Numero %d encontrado na linha %d\n", target, i);
    }
  }

  return 0;
}

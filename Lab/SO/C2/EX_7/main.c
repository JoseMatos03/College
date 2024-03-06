#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define ROWS 10
#define COLS 1000

void writeMatrixToFile(int matrix[ROWS][COLS], const char *filename) {
  FILE *file = fopen(filename, "wb");
  if (!file) {
    perror("Erro ao abrir arquivo");
    exit(1);
  }

  fwrite(matrix, sizeof(int), ROWS * COLS, file);

  fclose(file);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Uso: %s <numero> <arquivo_matriz>\n", argv[0]);
    return 1;
  }

  int target = atoi(argv[1]);
  const char *filename = argv[2];
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

  // Escreve a matriz em um arquivo binário
  writeMatrixToFile(matrix, filename);

  // Abre o arquivo para leitura
  int file_descriptor = open(filename, O_RDONLY);
  if (file_descriptor == -1) {
    perror("Erro ao abrir arquivo para leitura");
    return 1;
  }

  // Cria processos para procurar o número na matriz
  for (int i = 0; i < ROWS; i++) {
    pid = fork();

    if (pid == 0) {
      // Código executado pelo processo filho
      int row[COLS];
      lseek(file_descriptor, i * COLS * sizeof(int), SEEK_SET);
      read(file_descriptor, row, COLS * sizeof(int));

      for (int j = 0; j < COLS; j++) {
        if (row[j] == target) {
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

  // Fecha o arquivo
  close(file_descriptor);

  return 0;
}

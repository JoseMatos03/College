#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int num_filhos = 10;
  int i;

  for (i = 1; i <= num_filhos; i++) {
    pid_t pid = fork();

    if (pid < 0) {
      // Erro ao criar o processo filho
      fprintf(stderr, "Erro ao criar o processo filho\n");
      return 1;
    } else if (pid == 0) {
      // Código executado pelo processo filho
      printf("Filho %d - PID: %d, PPID: %d\n", i, getpid(), getppid());
      exit(i); // Termina com o valor do número de ordem
    } else {
      // Código executado pelo processo pai
      int status;
      waitpid(pid, &status, 0);

      if (WIFEXITED(status)) {
        // Filho terminou com sucesso
        printf("Pai - Filho %d terminou com código de saída: %d\n", i,
               WEXITSTATUS(status));
      } else {
        // Filho terminou com erro
        printf("Pai - Filho %d terminou com erro\n", i);
      }
    }
  }

  return 0;
}

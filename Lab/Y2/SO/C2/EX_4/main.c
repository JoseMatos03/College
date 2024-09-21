#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int i, status;

  for (i = 1; i <= 10; i++) {
    pid = fork();

    if (pid < 0) {
      // Erro ao criar o processo filho
      fprintf(stderr, "Erro ao criar o processo filho\n");
      return 1;
    } else if (pid == 0) {
      // Código executado pelo processo filho
      printf("Filho %d - PID: %d, PPID: %d\n", i, getpid(), getppid());
      return i;
    }
  }

  // Código executado pelo processo pai
  for (i = 1; i <= 10; i++) {
    pid_t terminated_pid = wait(&status);
    if (WIFEXITED(status)) {
      printf("Pai - Filho %d terminou com código de saída: %d\n",
             terminated_pid, WEXITSTATUS(status));
    }
  }

  return 0;
}

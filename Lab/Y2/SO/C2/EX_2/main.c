#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;

  // Criando o processo filho
  pid = fork();

  if (pid < 0) {
    // Erro ao criar o processo filho
    fprintf(stderr, "Erro ao criar o processo filho\n");
    return 1;
  } else if (pid == 0) {
    // Código executado pelo processo filho
    printf("Filho - PID: %d, PPID: %d\n", getpid(), getppid());
  } else {
    // Código executado pelo processo pai
    printf("Pai - PID: %d, PPID: %d\n", getpid(), getppid());
    printf("Pai - PID do filho: %d\n", pid);
  }

  return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid, ppid;

  // Obtem o PID (identificador de processo) atual
  pid = getpid();
  // Obtem o PID do processo pai
  ppid = getppid();

  // Imprime os PIDs
  printf("PID do processo atual: %d\n", pid);
  printf("PID do processo pai: %d\n", ppid);

  return 0;
}

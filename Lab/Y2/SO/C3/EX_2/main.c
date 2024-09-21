#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = fork();

  if (pid == 0) {
    execlp("ls", "ls", "-l", NULL);
  } else {
    wait(NULL);
  }

  return 0;
}

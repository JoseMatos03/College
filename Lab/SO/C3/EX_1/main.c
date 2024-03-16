#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  execlp("ls", "ls", "-l", NULL);

  return 0;
}

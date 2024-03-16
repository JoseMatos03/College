#include "mysystem.h"
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int mysystem(const char *command) {

  // Copy the command to a new string so we can modify it
  char *cmd = strdup(command);
  if (cmd == NULL) {
    return -1;
  }

  // Split the command into arguments
  int i = 0;
  char *args[100];
  while ((args[i] = strsep(&cmd, " ")) != NULL) {
    i++;
  }
  args[i] = NULL;

  // Fork and execute the command
  pid_t pid = fork();

  if (pid == 0) {
    int ret = execvp(args[0], args);
    _exit(ret);
  } else {
    int status;
    wait(&status);
    if (WIFEXITED(status)) {
      free(cmd);
      return WEXITSTATUS(status);
    }
  }

  return -1;
}

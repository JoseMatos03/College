#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024 * 1024

int main(int argc, char *argv[]) {
  if (argc != 3)
    return 1;

  char *buffer = malloc(sizeof(char) * BUF_SIZE);

  int origin = open(argv[1], O_RDONLY);
  int dest = open(argv[2], O_CREAT | O_WRONLY);

  ssize_t read_bytes = 0;
  while ((read_bytes = read(origin, buffer, BUF_SIZE)) != 0) {
    write(dest, buffer, BUF_SIZE);
  }

  return 0;
}

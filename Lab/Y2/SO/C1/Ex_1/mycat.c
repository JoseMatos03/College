#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(void) {
  char *buffer = malloc(sizeof(char) * BUF_SIZE);

  size_t bytes_read = 0;
  while ((bytes_read = read(0, buffer, BUF_SIZE)) != 0)
    write(1, buffer, bytes_read);
}

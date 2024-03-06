#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int i = 3;
  int j = 5;
  int h;

  int fd = open("teste", O_RDWR | O_CREAT | O_TRUNC, 0600);

  write(fd, &i, sizeof(int));
  write(fd, &j, sizeof(int));

  ssize_t res = read(fd, &h, sizeof(int));
  printf("res %zu, h = %d\n", res, h);
}

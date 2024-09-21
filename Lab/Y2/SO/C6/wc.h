#ifndef WC
#define WC

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int wc_run(char *input_file, char *output_file);

#endif
#include "wc.h"

#define BUFFER_LENGTH 16

int wc_run(char *input_file, char *output_file) {

    /* Building workplace */

    int in_fd = open(input_file, O_RDONLY);
    if (in_fd == -1) {
        perror("Error opening input file!\n");
        return -1;
    }

    int stdin = dup2(in_fd, 0);
    if (stdin == -1) {
        perror("Error redirecting stdin to input file...\n");
        return -1;
    }

    int out_fd = open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (out_fd == -1) {
        perror("Error opening output file!\n");
        return -1;
    }

    int stdout = dup2(out_fd, 1);
    if (stdout == -1) {
        perror("Error redirecting stout to output file...\n");
    }

    /* Executing `wc` */

    if (!fork()) {
        char buffer[2];

        if (read(stdin, buffer, sizeof(char) * 2) == -1) {
            _exit(0);
            perror("Error reading stdin file...\n");
            return -1;
        }
        lseek(stdin, 0, SEEK_SET);

        write(stdout, buffer, sizeof(char) * 2);
        write(stdout, "\n", sizeof(char));

        execlp(buffer, buffer, (char *) NULL);
        /* In case of error */
        write(stdout, "Error executing wc...\n", sizeof(char) * 22);
        _exit(0);
    }

    /* Closing */

    wait(NULL);
    close(in_fd);
    close(out_fd);

    return 0;
}
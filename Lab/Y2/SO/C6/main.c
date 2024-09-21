#include "wc.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(0,
              "Invalid arguments...\n./a.out [input file] [output file]\n",
              sizeof(char) * 21);

        return -1;
    }

    if (wc_run(argv[1], argv[2]))
        return 1;

    return 0;
}
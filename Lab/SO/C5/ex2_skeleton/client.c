#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Missing argument.\n");
		_exit(1);
	}

	// Send message to server
	msg_t m;
	m.needle = atoi(argv[1]);
	m.pid = getpid();
	m.occurrences = 0;

	char fifo_client[30];
	sprintf(fifo_client, "fifo_client_%d", m.pid);
	if (mkfifo(fifo_client, 0666) == -1)
	{
		perror("mkfifo client");
		_exit(2);
	}

	int server_fd = open(SERVER, O_WRONLY);
	if (server_fd == -1)
	{
		perror("open server");
		_exit(3);
	} else {
		printf("Connected to server\n");
	}

	if (write(server_fd, &m, sizeof(msg_t)) == -1)
	{
		perror("write server");
		_exit(4);
	}

	close(server_fd);

	// Receive message from server
	int client_fd = open(fifo_client, O_RDONLY);
	if (client_fd == -1)
	{
		perror("open client");
		_exit(5);
	}

	if (read(client_fd, &m, sizeof(msg_t)) == -1)
	{
		perror("read client");
		_exit(6);
	}

	printf("Occurrences: %d\n", m.occurrences);
	close(client_fd);

	unlink(fifo_client);
	return 0;
}

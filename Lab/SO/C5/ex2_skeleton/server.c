#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "defs.h"
#include "vector.h"

// FIFO criado pelo servidor
// Cliente pode receber um sigpipe (concorrência!)

int main(void)
{
	init_vector();
	print_vector();

	int fds_read = open(SERVER, O_RDONLY);
	if (fds_read == -1)
	{
		perror("open server");
		_exit(3);
	}
	else
	{
		printf("[DEBUG] Opened %d for reading\n", fds_read);
	}

	int fds_write = open(SERVER, O_WRONLY);
	if (fds_write == -1)
	{
		perror("open server");
		_exit(3);
	}
	else
	{
		printf("[DEBUG] Opened %d for writing\n", fds_write);
	}

	msg_t m;
	int bytes_read;
	while ((bytes_read = read(fds_read, &m, sizeof(m))) > 0)
	{
		if (bytes_read == sizeof(m))
		{
			if (m.needle == -1)
			{
				printf("[DEBUG] Server will shutdown on EOF\n");
				close(fds_write);
			}
			else
			{
				sleep(3);
				m.occurrences = count_needle(m.needle);
				printf("[DEBUG] Found needle %d - %d times\n", m.needle, m.occurrences);
			}

			// open FIFO client for writing response
			char fifo_client[30];
			sprintf(fifo_client, "fifo_client_%d", m.pid);
			int client_fd = open(fifo_client, O_WRONLY);
			if (client_fd == -1)
			{
				perror("open client");
				_exit(5);
			}
			else
			{
				printf("[DEBUG] Opened %d for writing\n", client_fd);
			}

			if (write(client_fd, &m, sizeof(msg_t)) == -1)
			{
				perror("write client");
				_exit(4);
			}

			close(client_fd);
		}
		else
		{
			printf("[DEBUG] Read %d bytes\n", bytes_read);
		}
	}
	return 0;
}

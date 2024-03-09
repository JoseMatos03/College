#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int serverSocket, newSocket;
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  char buffer[1024];

  // Create socket
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);

  // Configure server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  // Bind socket
  bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

  // Listen for incoming connections
  listen(serverSocket, 5);

  // Accept connection from client
  addr_size = sizeof(serverStorage);
  newSocket =
      accept(serverSocket, (struct sockaddr *)&serverStorage, &addr_size);

  // Receive command from client
  recv(newSocket, buffer, 1024, 0);
  printf("Received command from client: %s\n", buffer);

  // Process command (execute tasks)
  // ...

  // Send response to client
  char response[] = "Tasks executed successfully!";
  send(newSocket, response, strlen(response), 0);

  // Close sockets
  close(newSocket);
  close(serverSocket);

  return 0;
}

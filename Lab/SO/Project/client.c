#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int clientSocket;
  struct sockaddr_in serverAddr;
  char buffer[1024];

  // Create socket
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);

  // Configure server address
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

  // Send command to server
  char command[] = "execute 10 -p \"prog-a arg1 | prog-b arg2\"";
  send(clientSocket, command, strlen(command), 0);

  // Receive response from server
  recv(clientSocket, buffer, 1024, 0);
  printf("Response from server: %s\n", buffer);

  // Close socket
  close(clientSocket);

  return 0;
}

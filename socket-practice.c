#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

// struct Animal
// {
//   int num_legs;
// };

// struct Dog
// {
//   int legs;
//   int tail_length;
// };

// int get_legs(struct Animal *an)
// {
//   printf("%d", an->num_legs);
//   return an->num_legs;
// }

int main(int argc, char const *argv[])

{ // Create socket
  // attach local IP and port to socket (bind)
  // announce abillity to accept conn (listen)
  // Block incoming conn until con request arrives (accept)
  // Establish connection (connect )
  struct sockaddr_in addr = {0}; //  IP and PORT struct
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY); // Unit conversion
  addr.sin_port = htons(12345);             // Unit conversion

  int remote = socket(AF_INET, SOCK_STREAM, 0);         // Create socket (IPv4 and TCP)
  bind(remote, (struct sockaddr *)&addr, sizeof(addr)); // Bind socket to ADDR and PORT
  listen(remote, 3);                                    // Listen for conn

  while (1)
  {
    printf("%s", "Waiting for incoming connections...\n");
    char buffer[1024];

    int clientLen = sizeof(struct sockaddr_in *); // IDK max input size
    int new_socket = accept(remote, (struct sockaddr *)&addr, &clientLen);

    ssize_t valread = read(new_socket, buffer, 2024 - 1);
    send(new_socket, "hello", strlen("hello"), 0);
    printf("%s", buffer);
  }
}
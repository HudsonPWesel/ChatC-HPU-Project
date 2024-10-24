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
  struct sockaddr_in addr = {0};
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(12345);

  int remote = socket(AF_INET, SOCK_STREAM, 0);
  bind(remote, (struct sockaddr *)&addr, sizeof(addr));
  listen(remote, 3);

  while (1)
  {
    printf("%s", "Waiting for incoming connections...\n");
    char buffer[1024];
    int clientLen = sizeof(struct sockaddr_in *);
    int new_socket = accept(remote, (struct sockaddr *)&addr, &clientLen);

    ssize_t valread = read(new_socket, buffer, 1024 - 1);
    printf("%s", buffer);
  }
}
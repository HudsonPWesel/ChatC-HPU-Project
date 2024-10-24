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

  // struct Dog rover = {0};

  // rover.legs = 10;
  // rover.tail_length = 10;

  // get_legs((struct Animal *)&rover);

  struct sockaddr_in remote = {0};
  int clientPort = 12345;

  remote.sin_family = AF_INET;
  remote.sin_addr.s_addr = htonl(INADDR_ANY);
  remote.sin_port = htons(clientPort);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(sockfd, (struct sockaddr *)&remote, sizeof(remote));
  listen(sockfd, 3);

  while (1)
  {
    printf("%s", "Waiting for incoming connections...\n");
    char buffer[1024];
    int clientLen = sizeof(struct sockaddr_in *);
    int new_socket = accept(sockfd, (struct sockaddr *)&remote, &clientLen);

    ssize_t valread = read(new_socket, buffer, 1024 - 1);
    printf("%s", buffer);
  }
}
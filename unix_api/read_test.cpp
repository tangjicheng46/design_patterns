#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 4096

int main(int argc, char** argv) {
  exit(0); // for ci
  int n;
  char buff[BUFF_SIZE];
  while((n = read(STDIN_FILENO, buff, BUFF_SIZE)) > 0) {
    if (write(STDOUT_FILENO, buff, n) != n) {
      printf("Error\n");
      exit(0);
    }
  }
  return 0;
}
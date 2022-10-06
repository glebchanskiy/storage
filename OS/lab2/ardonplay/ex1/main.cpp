#include <iostream>
#include <unistd.h>

int main() {
  pid_t pid;
  std::cout << "1 процесс..." << std::endl;
  pid = fork();
  std::cout << "наверно уже 2 прцоесса" << std::endl;
  if (pid==0) {
    printf("Это Дочерний процесс, его pid=%d\n", getpid());
    printf("А pid его Родительского процесса=%d\n", getppid());
  } else if (pid > 0)
    printf("Это Родительский процесс pid=%d\n", getpid());
  else
    printf("Ошибка вызова fork, потомок не создан\n");
}


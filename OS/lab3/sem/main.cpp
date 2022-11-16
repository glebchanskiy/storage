#include <iostream>
#include <string>
#include <vector>

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <semaphore.h>
#include <ctime>

#include "Philosopher.h"

void init(Philosopher *ph, sem_t *forks) {
  ph->say("has come");
  int count = 0;
  while (count < 10) {
    ph->say("I want to eat");
    ph->takeForks(forks);
    ph->say("I take two forks and start eating!");
    ph->eat();
    ph->putForks(forks);
    ph->say("I put the forks back down and start thinking");
    ph->think();

    count++;
  }
}

int main() {
  pid_t pid;
  int status = 0;

  std::vector<Philosopher *> list;

  list.push_back(new Philosopher("Saruman"));
  list.push_back(new Philosopher("Gandalf"));
  list.push_back(new Philosopher("Radagast"));
  list.push_back(new Philosopher("Alatar"));
  list.push_back(new Philosopher("Pallando"));

  for (auto &ph : list) {
    pid = fork();

    sem_t *forks = sem_open("/forks", O_CREAT, 0600, 0);

    if (pid == 0) {
      init(ph, forks);
      return 0;
    } else {
      sem_post(forks);
    }

    int time = rand() % 3;
    sleep(time);
  }

  waitpid(pid, nullptr, 0);
}

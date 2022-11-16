#include <string>
#include <iostream>
#include <unistd.h>
#include <semaphore.h>

class Philosopher {
 public:
  Philosopher(std::string name) : name(move(name)) {}

  void say(std::string message);
  void eat();
  void think();
  void takeForks(sem_t *forks);
  void putForks(sem_t *forks);

 private:
  std::string name;
};
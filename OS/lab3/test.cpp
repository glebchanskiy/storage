#include <semaphore.h>
#include <unistd.h>

#include <iostream>

using namespace std;

void child(sem_t *sem) {
		cout << "child sem wait" << endl;
		sem_wait(sem);

		cout << "child start after waiting" << endl;
  exit(0);
}

int main() {

  pid_t pid = fork();

		sem_t *sem = sem_open("/sem", O_CREAT, 0644, 0);


  if (pid == 0) {
    child(sem);
  }
		cout << "now child wait" << endl;
		sleep(3);
		cout << "main post semaphore" << endl;
		sem_post(sem); 
  cout << "the end of main." << endl;

  return 0;
}

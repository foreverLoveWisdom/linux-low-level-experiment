#include <pthread.h>
#include <stdio.h>

void *thread_function(void *arg) {
  // Simulate some work
  for (volatile int i = 0; i < 1000000; i++)
    ;
  return NULL;
}

int main() {
  int err = 0, count = 0;
  pthread_t tid;

  // Loop to create threads until an error occurs.
  while (err == 0) {
    err = pthread_create(&tid, NULL, thread_function, NULL);
    if (err == 0) {
      count++;
      printf("Current number of threads within a process is: %d\n", count);
    }
  }

  printf("Maximum number of threads within a process is: %d\n", count);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LENGTH 1024

int main() {
  char command[MAX_CMD_LENGTH];

  while (1) {
    // Display a prompt
    printf("simple_shell> ");
    fflush(stdout); // Ensure prompt is displayed immediately

    // Read user input
    if (fgets(command, MAX_CMD_LENGTH, stdin) == NULL)

      // Read user input
      if (fgets(command, MAX_CMD_LENGTH, stdin) == NULL) {
        if (feof(stdin)) {
          // Handle EOF gracefully
          break; // Exit the loop on EOF
        } else {
          perror("fgets failed");
          continue; // Handle other errors gracefully
        }
      }

    // Remove newline character from input
    command[strcspn(command, "\n")] = 0;

    // Exit command
    if (strcmp(command, "exit") == 0) {
      break; // Exit the shell loop
    }

    // Execute the command
    int ret = system(command); // Use system call to execute command
    if (ret == -1) {
      perror("Command execution failed");
    }
  }

  return 0;
}

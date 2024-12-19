#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid; // Variable to hold the process ID

    printf("Main Process: PID = %d\n", getpid());

    // Create a child process
    printf("Main Process: Attempting to fork a new process...\n");
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        // This block is executed by the child process
        printf("Child Process: PID = %d\n", getpid());
        printf("Child Process: Executing 'ls' command...\n");

        // Execute the 'ls' command
        char *args[] = {"ls", NULL}; // Arguments for exec
        execvp(args[0], args); // Use execvp for better argument handling

        // If execvp fails
        perror("execvp failed");
        return EXIT_FAILURE;
    } else {
        // This block is executed by the parent process
        printf("Parent Process: PID = %d, waiting for child to complete...\n", getpid());

        // Wait for the child process to finish
        int status;
        waitpid(pid, &status, 0); // Wait for the specific child process

        if (WIFEXITED(status)) {
            printf("Parent Process: Child exited with status %d.\n", WEXITSTATUS(status));
            printf("Parent Process: Command executed successfully.\n");
        } else {
            printf("Parent Process: Child terminated abnormally.\n");
        }

        printf("Parent Process: Child completed.\n");

        // Delay to allow observation of processes
        sleep(1); // Sleep for 1 second

        // Log running processes to verify execution
        printf("\nCurrent processes:\n");
        system("ps -f"); // List all processes with full format
    }

    return EXIT_SUCCESS;
}

// After compiling, run this `strace -f -e trace=execve ./a.out` to verify the ouptut

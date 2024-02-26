#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * infinite_while - Function that runs an infinite loop.
 *
 * Return: Always returns 0.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always returns 0.
 */
int main(void)
{
    pid_t child_pid;
    int i;

    for (i = 0; i < 5; i++)
    {
        child_pid = fork();

        if (child_pid > 0)
        {
            // Parent process
            printf("Zombie process created, PID: %d\n", child_pid);
            sleep(1); // Give child process some time to become a zombie
        }
        else if (child_pid == 0)
        {
            // Child process
            exit(0);
        }
        else
        {
            // Fork error
            perror("Fork failed");
            exit(1);
        }
    }

    infinite_while(); // Calls the provided infinite_while function

    return (0);
}

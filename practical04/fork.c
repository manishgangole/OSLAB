// file3.c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child Process:\nPID: %d\nPPID: %d\n", getpid(), getppid());
    } else {
        printf("Parent Process:\nPID: %d\n", getpid());
    }

    return 0;
}

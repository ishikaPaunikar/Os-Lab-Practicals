#include <unistd.h>
#include <stdio.h>

int main() {
    int cpr1, cpr2;

    cpr1 = fork();

    if (cpr1 < 0) {
        printf("First fork failed\n");
    } else if (cpr1 == 0) {
        printf("First child process created\n");
        printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        cpr2 = fork();
        
        if (cpr2 < 0) {
            printf("Second fork failed\n");
        } else if (cpr2 == 0) {
            printf("Second child process created\n");
            printf("Child PID: %d, Parent PID: %d\n", getpid(), getppid());
        } else {
            printf("In parent process (PID: %d)\n", getpid());
        }
    }

    return 0;
}

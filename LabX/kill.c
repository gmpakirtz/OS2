#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
        printf("Child process recieved signal %d\n", sig);
}

int main() {
        pid_t pid;

        signal(SIGUSR1, signal_handler);

        pid = fork();

        if (pid == 0) {
                pause();
        } else {
                sleep(1);
                kill(pid, SIGUSR1);
                printf("Parent process sent signal to child\n");
        }
	return 0;
}

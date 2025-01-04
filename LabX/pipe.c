#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int pipefd[2];
	pid_t pid;
	char message[] = "Hi, parent to child";

	pipe(pipefd);

	pid = fork();

	if (pid == 0) {
		char buffer[100];
		close(pipefd[1]);
		read(pipefd[0], buffer, sizeof(buffer));
		printf("Child recieved: %s\n", buffer);
		close(pipefd[0]);
	} else {
		close(pipefd[0]);
		write(pipefd[1], message, strlen(message) + 1);
		close(pipefd[1]);
	}
	return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid;
	FILE *file = fopen("pids.txt", "W");

	if (file == NULL) {
		perror("Unable to open file");
		return 1;
	}

	pid = fork();

	if (pid == 0) {
		fprintf(file, "Child PID: %d\n", getpid());
	} else {
		fprintf(file, "Parent PID: %d\n", getpid());
	}

	fclose(file);
	return 0;
}

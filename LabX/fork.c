#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t pid;

	pid = fork();
	if (pid == 0){
		printf("child process, PID: %d\n", getpid());
	} else {

		pid = fork();
		if (pid == 0) {
			printf("child process, PID: %d\n", getpid());
		} else {

			pid = fork();
			if (pid = 0){
				printf("child process, PID: %d\n", getpid());
			}else {
				printf("parent process, PID: %d\n", getpid());
			}
		}
	}
	return 0;
}

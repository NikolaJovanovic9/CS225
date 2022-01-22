#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
	pid_t p;
	printf("Prije fork-a\n");
	p = fork();
	if (p == 0) { //dijete proces
		printf("Dijete proces. ID djeteta: %d\n", getpid());
		printf("ID roditelja: %d\n", getppid());
	} else { //roditelj proces
		wait(NULL);
		printf("ID djeteta: %d\n", p);
		printf("Roditelj proces. ID roditelja: %d\n", getpid());

	}

	return 0;
}
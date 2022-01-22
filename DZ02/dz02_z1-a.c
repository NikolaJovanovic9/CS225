#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {

	printf("Pocetak roditelja\n");
	if (fork() == 0) {
		printf("Pocetak prvog djeteta\n");
		printf("Kraj prvog djeteta\n");
	}

	if (fork == 0) {
		printf("Pocetak prvog djeteta\n");
		printf("Kraj drugog djeteta\n");

	}
	wait(NULL);
	wait(NULL);
	printf("Kraj roditelja\n");

	return 0;
}

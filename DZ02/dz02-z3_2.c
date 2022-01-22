#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
	int res, n;
	res = open("fifo1", O_WRONLY);
	write(res, "Poruka", 7);
	printf("Proces posiljalac (ID) -> %d je poslao podatke\n", getpid());

	return 0;
}
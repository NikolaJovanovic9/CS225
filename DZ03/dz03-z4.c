#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {

	int n;
	int fd1;
	int fd2;
	int i;
	char buff[50];

	fd1 = open("test.txt", O_RDONLY);

	n = read(fd1, buff, 10);

	fd2 = open("check.txt", O_WRONLY | O_CREAT, 0642);

	i = write(fd2, buff, n);

	printf("Ukupan broj znakova -> %d. ", i);

	return 0;
}
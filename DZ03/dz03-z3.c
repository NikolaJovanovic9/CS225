#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

	int n;
	int fd1;
	int fd2;
	char buff[50];

	fd1 = open("test.txt", O_RDONLY);

	n = read(fd1, buff, 10);

	fd2 = open("check.txt", O_WRONLY | O_CREAT, 0642);

	write(fd2, buff, n);

	return 0;
}
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int res, n;
    char buffer[100];
    res = open("fifo1", O_RDONLY);
    n = read(res, buffer, 100);
    printf("Proces citalac (ID) -> %d je pokrenut\n", getpid());
    printf("Podaci su primljeni od strane primaoca (ID) -> (%d) su: %s\n", getpid(), buffer);

    return 0;
}
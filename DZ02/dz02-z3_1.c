#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
	int res;
	res = mkfifo("fifo1", 0777);
	printf("Imenovani PIPE je uspjesno kreiran\n");

	return 0;
}
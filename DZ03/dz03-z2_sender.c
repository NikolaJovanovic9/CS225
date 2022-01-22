#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/ipc.h>

int main() {
    int i;
    void* shared_memory;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345, 2048, 0666 | IPC_CREAT); 

    printf("Kljuc dijeljene memorije je -> %d\n", shmid);
    shared_memory = shmat(shmid, NULL, 0);
    printf("Proces prilozen na -> %p\n", shared_memory);
    printf("Unesite podatke za zapisivanje u dijeljenu memoriju\n");
    read(0, buff, 100);
    strcpy(shared_memory, buff);
    printf("Napisali ste ->  %s\n", (char*)shared_memory);

    return 0;
}
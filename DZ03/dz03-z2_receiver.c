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

    shmid = shmget((key_t)2345, 2048, 0666);

    printf("Kljuc dijeljene memorije je -> %d.\n", shmid);
    
    shared_memory = shmat(shmid, NULL, 0); 
    
    printf("Proces dostavljen na -> %p.\n", shared_memory);
    
    printf("Procitani podaci iz dijeljene memorije ->  %s\n", (char*)shared_memory);

    return 0;
}
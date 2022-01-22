#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fun1();
void* fun2();
void* fun3();
void* fun4();

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;
pthread_mutex_t mutex3;
pthread_mutex_t mutex4;

int main() {

	pthread_mutex_init(&mutex1, NULL);
	pthread_mutex_init(&mutex2, NULL);
	pthread_mutex_init(&mutex3, NULL);
	pthread_mutex_init(&mutex4, NULL);

	pthread_t one, two, three, four;
	pthread_create(&one, NULL, fun1, NULL);
	pthread_create(&two, NULL, fun2, NULL);
	pthread_create(&three, NULL, fun3, NULL);
	pthread_create(&four, NULL, fun4, NULL);

	pthread_join(one, NULL);
	pthread_join(two, NULL);
	pthread_join(three, NULL);
	pthread_join(four, NULL);

	printf("Thread joined! \n");

	return 0;
}

void* fun1() {
	pthread_mutex_lock(&mutex1);
	printf("Thread1 acq mutex1. \n");
	sleep(1);
	pthread_mutex_lock(&mutex2);
	printf("Thread1 acq mutex2. \n");
}

void* fun2() {
	pthread_mutex_lock(&mutex4);
	printf("Thread2 acq mutex4. \n");
	sleep(1);
	pthread_mutex_lock(&mutex2);
	printf("Thread2 acq mutex2. \n");
}

void* fun3() {
	pthread_mutex_lock(&mutex3);
	printf("Thread3 acq mutex3. \n");
	sleep(1);
	pthread_mutex_lock(&mutex1);
	printf("Thread3 acq mutex1. \n");
}

void* fun4() {
	pthread_mutex_lock(&mutex2);
	printf("Thread4 acq mutex2. \n");
	sleep(1);
}

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t room;
sem_t cs[5];
void *Philosopher(void *);
void eat(int);
int main(){
	int i,a[5];
	pthread_t tid[5];
	sem_init (&room,0,4);
	for(i=0;i<5;i++){
		sem_init(&cs[i],0,1);
	}
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,Philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++){
		pthread_join(tid[i],NULL);
	}}
void * Philosopher(void * num){
	int phil=*(int *)num;
	sem_wait(&room);
	printf("\nPhilosopher %d has entered the room",phil);
	sem_wait(&cs[phil]);
	sem_wait(&cs[(phil+1)%5]);
	
	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);
	
	sem_post(&cs[(phil+1)%5]);
	sem_post(&cs[phil]);
	sem_post(&room);
}
void eat(int phil){
	printf("\nPhilosopher %d is eating",phil);
}
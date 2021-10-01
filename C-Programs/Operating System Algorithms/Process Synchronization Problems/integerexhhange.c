#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define buffersize 100
pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full,empty;
int count;
int buffer[buffersize];
int lt=0,c=0;
void display(){
	int f, e;
	sem_getvalue(&full, &f);
	sem_getvalue(&empty, &e);
	printf("\nInputues semaphore: \nfull=%d\t\tempty=%d\n",f,e);
}
void initialize(int n)
{
	pthread_mutex_init(&mutex,NULL);
	count=0;
	sem_init(&full, 0, 0);
	sem_init(&empty, 0, n);
	display();
}
void writer(int input)
{
	buffer[count++]=input;
	printf("%d\t",input);
	empty;
}
int reader()
{
	sem_post(&full);
	return buffer[--count];
}
void * producer (void * param)
{
	int input;
	input=lt++;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	writer(input);
	c++;
	if(c==5){
		printf("\n");
		c=0;
	}
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
	return(0);
}
void * consumer (void * param)
{
	int input;
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	input=reader();
	printf("%d\t",input);
	c++;
	if(c==5){
		printf("\n");
		c=0;
	}
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
	return(0);
}
int main()
{
	int n,i;
	printf("\nEnter the total integers to be produced: ");
	scanf("%d",&n);
	if(n>buffersize){
		printf("\n\n\n\n");
		exit(0);
	}
	initialize(n);
	printf("\nProducer produced integers\n");
	for(i=0;i<n;i++)
		pthread_create(&tidP[i],NULL,producer,NULL);
	sleep(5);
	display();
	printf("\nConsumers produced integers:\n");
	for(i=0;i<n;i++)
		pthread_create(&tidC[i],NULL,consumer,NULL);
	for(i=0;i<n;i++)
		pthread_join(tidP[i],NULL);
	for(i=0;i<n;i++)
		pthread_join(tidC[i],NULL);
	display();
	exit(0);
}

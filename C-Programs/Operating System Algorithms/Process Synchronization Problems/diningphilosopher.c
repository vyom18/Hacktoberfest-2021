#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define L (phnum+4)%5
#define R (phnum+1)%5
int state[5];
int phil[5]={0,1,2,3,4};
sem_t mutex;
sem_t S[5];
void test(int phnum)
{
        if(state[phnum]==1 && state[L]!=0 && state[R]!=0)
        {
                state[phnum]=0;
                sleep(2);
                printf("Philosopher %d takes fork %d and %d\n",phnum + 1, L + 1, phnum + 1);
                printf("Philosopher %d is Eating\n", phnum + 1);
                sem_post(&S[phnum]);
        }
}
void take_fork(int phnum)
{
        sem_wait(&mutex);
        state[phnum]=1;
        printf("Philosopher %d is Hungry\n", phnum + 1);
        test(phnum);
        sem_post(&mutex);
        sem_wait(&S[phnum]);
        sleep(1);
}
void put_fork(int phnum)
{
        sem_wait(&mutex);
        state[phnum]=2;
        printf("Philosopher %d putting fork %d and %d down\n",phnum + 1, L + 1, phnum + 1);
        printf("Philosopher %d is thinking\n", phnum + 1);
        test(L);
        test(R);
        sem_post(&mutex);
}
void* philospher(void* num)
{

            while (1) {
                 int* i = num;
                 sleep(1);
                 take_fork(*i);
                 sleep(0);
                 put_fork(*i);
            }
}
int main()
{
        int i;
        pthread_t thread_id[5];
        sem_init(&mutex,0,1);
        for(i=0;i<5;i++)
                sem_init(&S[i],0,0);
        for(i=0;i<5;i++){
                pthread_create(&thread_id[i], NULL,philospher, &phil[i]);
                printf("Philosopher %d is thinking\n", i + 1);
        }
        for(i=0;i<5;i++)
                pthread_join(thread_id[i], NULL);

}


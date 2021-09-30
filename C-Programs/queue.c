#include<stdio.h>
#include<stdlib.h>
#define size 3

int q[size],i,item, front=-1,rear=-1;

void enqueue(int x);
void dequeue();
void display();

int main() {
    int ch;
    while(1) {
        printf("1. insert \n 2. delete \n 3. display \n 4. exit");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("Enter item to insert: ");
                    scanf("%d", &item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid");
            
        }
}
}

void enqueue(int x) {
    if(rear==size-1) { printf("Queue is full\n");
} else {
    if(front==-1) front++;
    rear++;
    q[rear]=x;
}
}

void dequeue() {
    if(rear==-1) {
        printf("Queue is empty\n");} else {
            printf("Item deleted: %d",q[front]);
            front++;
        }
    }
    
void display() {
        if(rear==-1) {
        printf("Queue is empty\n");} else {
            printf("elements are : ");
            for(i=front;i<=rear;i++) {
                printf("%d", q[i]);
            }
        }
    }
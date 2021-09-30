#include<stdio.h>
#include<stdlib.h>
#define size 3

int stack[size],top=-1,i,item;

void push(int x);
void pop();
void display();

int main() {
int c;
while(1) {
	printf("1. insert \n 2. pop \n 3. display \n 4.exit\n");
	printf("Enter your choice: ");
	scanf("%d", &c);
	switch(c){
		case 1: printf("\nEnter value to insert: ");
				scanf("%d", &item);
				push(item);
				break;
		case 2: pop();
				break;
		case 3: display();
				break;
		case 4: exit(0);
		break;
		default: exit(0);
	}
}
return 0;	
}

void push(int x) {
	if(top==size-1) { printf("Stack is full\n"); } else {
	top++;
	stack[top]=x;
}
}

void pop() {
	if(top==-1) {
		printf("Stack is empty\n");
	}
	else {
		printf("Item deleted: %d", stack[top]);
		top--;
	}
}

void display() {
		if(top==-1) {
		printf("Stack is empty\n");
	}
	else {
		printf(" Elements are: ");
		for (i=top;i>=0;i--) {
			printf("%d\t", stack[i]);
		}
	}
}

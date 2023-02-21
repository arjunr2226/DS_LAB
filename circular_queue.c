#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N], front=-1, rear=-1;

void enqueue()
{
	int data;
	printf("ENTER ELEMENT: ");
	scanf("%d", &data);
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = data;
	}
	else if(((rear+1)%N) == front)
	{
		printf("\nOVERFLOW\n");
	}
	else
	{
		rear = (rear+1)%N;
		queue[rear] = data;
	}
}

void dequeue()
{
	if(front == rear)
	{
		printf("\nDEQUEUED: %d\n", queue[front]);
		front = rear = -1;
	}
	else if(front == -1)
	{
		printf("\nUNDERFLOW\n");
	}
	else
	{
		printf("\nDEQUEUED: %d\n\n", queue[front]);
		front = (front+1)%N;
	}
}

void display()
{
	int i = front;
	if(front == -1)
		printf("\nQUEUE EMPTY\n");
	else
	{
		printf("\nQUEUE ELEMENTS: ");
		while(i != rear)
		{
			printf("%d ", queue[i]);
			i = (i+1)%N;
		}
		printf("%d\n", queue[rear]);
	}
	printf("\n");
}

void main()
{
	int ch;
	while(1)
	{
		printf("ENTER\n1:ENQUEUE\n2:DEQUEUE\n3:DISPLAY\nCHOICE: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 0:
				exit(0);
			default:
				printf("\nWRONG CHOICE!\n");
		}
	}
}

#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N], front=-1, rear=-1;

void enqueue()
{
	int data;
	printf("\nENTER THE ELEMENT: ");
	scanf("%d", &data);
	if(front == -1 && rear == -1)
	{
		front = rear = 0;
		queue[rear] = data;
	}
	else if(rear == N-1)
		printf("\nOVERFLOW\n");
	else
	{
		queue[++rear] = data;
	}
}

void dequeue()
{
	if(front == -1)
		printf("\nUNDERFLOW\n");
	else if(front == rear)
	{
		printf("\nDEQUEUED: %d\n", queue[front]);
		front = rear = -1;
	}
	else
	{
		printf("\nDEQUEUED: %d\n", queue[front]);
		front++;
	}
}

void display()
{
	if(front == -1)
		printf("\nQUEUE EMPTY\n");
	else
	{
		printf("\nQUEUE ELEMENTS: ");
		for(int i=front; i<=rear; i++)
			printf("%d ", queue[i]);
	}
	printf("\n");
}

void main()
{
	int ch;
	while(1)
	{
		printf("\nENTER\n1:ENQUEUE\n2:DEQUEUE\n3:DISPLAY\nCHOICE: ");
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

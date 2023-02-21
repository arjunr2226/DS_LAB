#include<stdio.h>
#include<stdlib.h>
#define N 5
int stack[N], top=-1;

void push()
{
	int data;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &data);
	if(top == N-1)
		printf("\nOVERFLOW\n");
	else
	{
		stack[++top] = data;
	}
}

void pop()
{
	if(top == -1)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nPOPPED: %d\n", stack[top]);
		top--;
	}
}

void display()
{
	if(top == -1)
		printf("\nSTACK EMPTY\n");
	else
	{
		printf("\nSTACK: ");
		for(int i=top; i>=0; i--)
			printf("%d ", stack[i]);
		printf("\n\n");
	}
}

void main()
{
	int ch;
	while(1)
	{
		printf("\nENTER\n1:PUSH\n2:POP\n3:DISPLAY\nCHOICE: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
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

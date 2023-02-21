#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL, *rear=NULL;

void enqueue()
{
	struct node *newnode;
	newnode= (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(front == NULL && rear == NULL)
	{
		front = rear = newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}

void dequeue()
{
	if(front == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nPOPPED: %d\n", front->data);	
		struct node *temp = front;
		front = front->next;
		free(temp);
	}
}

void display()
{
	if(front == NULL)
		printf("\nQUEUE EMPTY\n");
	else
	{
		struct node *temp = front;
		printf("\nQUEUE ELEMENTS: \n");
		while(temp != rear)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
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

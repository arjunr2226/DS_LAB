#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*top=NULL;

void push()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER THE ELEMENT: ");
	scanf("%d", &newnode->data);
	if(top == NULL)
		top = newnode;
	else
	{
		newnode->next = top;
		top = newnode;
	}
}

void pop()
{
	if(top == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		printf("\nPOPPED: %d", top->data);
		top = top->next;
	}
}

void display()
{
	struct node *temp=top;
	if(top == NULL)
		printf("\nSTACK EMPTY\n");
	else
	{
		printf("\nSTACK ELEMENTS: ");
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n\n");
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
				printf("\nWRONG OPTION!\n");
		}
	}
}

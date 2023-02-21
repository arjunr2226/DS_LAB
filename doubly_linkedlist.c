#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev, *next;
}*start=NULL;

void create()
{
	struct node *newnode, *current;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
		start = current = newnode;
	else
	{
		newnode->prev = current;
		current->next = newnode;
		current = newnode;
		
	}
}

void insert_beg()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		newnode->next = start;
		start->prev = newnode;
		start = newnode;
	}
}

//Insert at end
void insert_end()
{
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp=start;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}
}

//Inserting at middle
int insert_mid()
{
	struct node *newnode, *temp;
	int pos;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->prev = newnode->next = NULL;
	printf("\nENTER POSITION: ");
	scanf("%d", &pos);
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		temp=start;
		while(temp->data != pos)
		{
			if(temp->next == NULL)
			{
				printf("\nNOT FOUND\n");
				return 0;
			}
			else
			{
				temp = temp->next;
			}
		}
		if(temp->next == NULL)
		{
			temp->next = newnode;
			newnode->prev = temp;
		}
		else
		{
			newnode->next = temp->next;
			newnode->prev = temp;
			temp->next->prev = newnode;
			temp->next = newnode;
		}
			
	}
}

//Deleting at beginning
void del_beg()
{
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else if(start->next == NULL)
	{
		free(start);
		start = NULL;
	}
	else
	{
		struct node *temp;
		printf("\nDELETED: %d\n", start->data);
		temp = start;
		start = start->next;
		start->prev = NULL;
		free(temp); 
	}
}

//Deleting at end
void del_end()
{
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else if(start->next == NULL)
	{
		printf("\nDELETED: %d\n", start->data);
		start = NULL;
	}
	else
	{
		struct node *temp=start;
		while(temp->next != NULL)
			temp = temp->next;
		printf("\nDELETED: %d\n", temp->data);
		temp->prev->next = NULL;
		free(temp);
	}
}

//Deleting at middle
int del_mid()
{
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		int pos;
		struct node *temp=start;
		printf("\nENTER POSITION: ");
		scanf("%d", &pos);
		while(temp->data != pos)
		{
			if(temp->next == NULL)
			{
				printf("\nNOT FOUND\n");
				return 0;
			}
			else
				temp = temp->next;
		}
		if(temp->next == NULL && temp->prev == NULL)
		{
			start = NULL;
			free(temp);
		}
		else if(temp == start)
		{
			start = start->next;
			start->prev = NULL;
			free(temp);
		}
		else if(temp->next == NULL)
		{	
			temp->prev->next = NULL;
			free(temp);
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
		}
	}
}

//Display Function
void display()
{
	struct node *temp=start;
	if(start == NULL)
		printf("\nLINKEDLIST IS EMPTY\n");
	else
	{
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n\n");
}

//Main function
int main()
{
	int choice;
	while(1)
	{
		printf("1:INSERT \n2:DISPLAY \n3:INSERT_AT_BEG \n4:INSERT_END \n5:INSERT_MID \n6:DELETE_BEG \n7:DELETE_END \n8:DELETE_MID \n0:EXIT \nENTER CHOICE: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
				break;
			case 3:
				insert_beg();
				break;
			case 4:
				insert_end();
				break;
			case 5:
				insert_mid();
				break;
			case 6:
				del_beg();
				break;
			case 7:
				del_end();
				break;
			case 8:
				del_mid();
				break;
			case 0:
				exit(0);
			default:
				printf("WRONG CHOICE! \n");
		}
	}
}

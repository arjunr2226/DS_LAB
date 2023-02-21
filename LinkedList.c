#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*start=NULL;


//Creating LinkedList
void create()
{
	struct node *newnode, *current;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = current = newnode;
	}
	else
	{
		current->next = newnode;
		current = newnode;
	}
}

//insert at beginning

void insert_beg()
{
	struct node *newnode, *current;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = current = newnode;
	}
	else
	{
		newnode->next = start;
		start = newnode;
	}
}

//insert at end

void insert_end()
{
	struct node *newnode, *temp=start, *current;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = current = newnode;
	}
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}

//insert at middle

int insert_mid()
{
	struct node *newnode, *temp=start, *current;
	int pos;
	printf("\nENTER THE POSITION: ");
	scanf("%d", &pos);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("\nENTER ELEMENT: ");
	scanf("%d", &newnode->data);
	if(start == NULL)
	{
		start = current = newnode;
	}
	else
	{
		while(temp->data != pos)
		{
			if(temp->next == NULL)
			{
				printf("\nPOSITION NOT FOUND\n");
				return 0;
			}	
			else
				temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
}

//Deleting at beginning
void del_beg()
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
		printf("\nDELETED: %d\n", temp->data);
		start = start->next;
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
		struct node *temp=start, *prev;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		printf("\nDELETED: %d\n", temp->data);
		prev->next = NULL;
		free(temp);
	}
}

//Deleting at middle
int del_mid()
{
	int pos;
	printf("\nENTER POSITION: ");
	scanf("%d", &pos);
	
	if(start == NULL)
		printf("\nUNDERFLOW\n");
	else
	{
		struct node *temp=start, *prev;
		while(temp->data != pos)
		{
			if(temp->next == NULL)
			{
				printf("\nNOT FOUND\n");
				return 0;
			}
			else
			{
				prev = temp;
				temp = temp->next;
			}
		}
		if(temp == start)
		{
			start = start->next;
			free(temp);
			printf("\nDELETED SUCCESSFULLY\n\n");
		}
		else
		{
			prev->next = temp->next;
			free(temp);
			printf("\nDELETED SUCCESSFULLY\n");
		}
	}
}

//Displaying LinkedList
void display()
{
	struct node *temp=start;
	if(start == NULL)
		printf("\nLINKED LIST IS EMPTY\n");
	else
	{
		printf("\nLINKED LIST: ");
		while(temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n\n");
}


//Main Function
void main()
{
	int ch;
	while(1)
	{
		printf("ENTER\n0:EXIT\n1:INSERT\n2:DISPLAY\n3:INSERT_AT_BEG\n4:INSERT_END\n5:INSERT_MID\n6:DELETE_BEG\n7:DELETE_END\n8:DELETE_MID\nCHOICE:");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
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

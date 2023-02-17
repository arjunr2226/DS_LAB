#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *prev, *next;
}*start;

//Creating 

void create()
{
	struct node *newnode, *current;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("ENTER ELEMENT :");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	if(start == NULL)
	{
		start = newnode;
		current = newnode;
	}
	else
	{
		current->next = newnode;
		newnode->prev = current;
		current = newnode;
	}
	printf("\n");
}

//Displaying

void display()
{
	struct node *temp;
	temp = start;
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n\n");
}

//Inserting at beginning

void insert_beg()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("ENTER ELEMENT :");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		start->prev = newnode;
		newnode->next = start;
		start = newnode;
	}
	printf("\n");
}

//Inserting at end

void insert_end()
{
	struct node *newnode, *temp;
	temp = start;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("ENTER ELEMENT :");
	scanf("%d", &newnode->data);
	newnode->prev = NULL;
	newnode->next = NULL;
	if(start == NULL)
	{
		start = newnode;
	}
	else
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
	}
	printf("\n");
}

//Inserting at middle

int insert_mid()
{
	struct node *newnode, *temp;
	int key;
	temp = start;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("ENTER THE POSITION TO BE INSERTED AFTER :");
	scanf("%d", &key);
	printf("ENTER THE ELEMENT :");
	scanf("%d", &newnode->data);
	newnode->next = NULL;
	newnode->prev = NULL;
	while(temp->data != key)
	{
		if(temp->next == NULL)
		{
			printf("NOT FOUND \n");
			return 0;
		}
		else
			temp = temp->next;
	}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
		printf("\n");
}

//Deleting at Beg

void del_beg()
{
	struct node *temp;
	temp = start;
	if(start == NULL)
		printf("EMPTY");
	else if(start->next == NULL)
		start = NULL;
	else
	{
		start = start->next;
		start->prev = NULL;
		free(temp);
		printf("ELEMENT POPPED \n");
	}
	printf("\n");
}

//Deleting at mid

int del_mid()
{
	struct node *temp;
	int key;
	temp = start;
	printf("ENTER THE POSTION TO BE DELETED : ");
	scanf("%d", &key);
	while(temp->data != key)
	{
		if(temp->next == NULL)
		{
			printf("NOT FOUND\n");
			return 0;
		}
		temp = temp->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	printf("\n");
}

//Deleting at end

void del_end()
{
	struct node *temp;
	temp = start;
	while(temp->next != NULL)
		temp = temp->next;
	temp->prev->next = NULL;
	free(temp);
	printf("\n");
}

void main()
{
	int choice;
	do
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
				break;
			default:
				printf("WRONG CHOICE! \n");
		}
	}while(choice!=0);
}

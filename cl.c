#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*tail=NULL;


//Display

void display()
{
	struct node *temp;
	temp = tail->next;
	if(tail == NULL)
		printf("UNDERFLOW\n");
	else
	{
		do
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}while(temp != tail->next);
	}
	printf("\n");
}

//Inserting at beg

void insert_beg()
{
	struct node *newnode, *temp;
	temp = tail;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("ENTER THE ELEMENT :");
	scanf("%d", &newnode->data);
	if(tail == NULL)
	{
		tail = newnode;
		tail->next = newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
	}
}

//Inserting at mid

void insert_end()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("ENTER THE ELEMENT :");
	scanf("%d", &newnode->data);
	if(tail == NULL)
	{
		tail = newnode;
		tail->next = newnode;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = tail->next;
	}
}

//Inserting at mid

int insert_mid()
{
	struct node *newnode, *temp = tail->next;
	int pos;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("ENTER POSITION TO INSERT AFTER :");
	scanf("%d", &pos);
	printf("ENTER THE ELEMENT :");
	scanf("%d", &newnode->data);
	while(pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	newnode->next = temp->next;
	temp->next = newnode;
	if(temp == tail)
	{
		tail = tail->next;
	}
}

//Deleting at beg

void del_beg()
{
	struct node *temp;
	temp = tail->next;
	if(tail == NULL)
		printf("UNDERFLOW\n");
	else
	{
		
		tail->next = temp->next;
		free(temp);
	}
}

//Deleting at end

void del_end()
{
	struct node *temp, *head;
	temp = tail->next;
	if(tail == NULL)
		printf("UNDERFLOW\n");
	else
	{
		while(temp->next != tail)
		{
			temp = temp->next;
		}
		temp->next = tail->next;
		free(tail);
		tail = temp;
	}
}

//Deleting at mid

int del_mid()
{
	struct node *temp = tail->next, *temp2;
	int pos;
	printf("ENTER POSITION TO DELETE AFTER :");
	scanf("%d", &pos);
	while(pos > 2)
	{
		temp = temp->next;
		pos--;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
}

void main()
{
	int choice;
	do
	{
		printf("\n");
		printf("ENTER \n0:EXIT\n1:DISPLAY\n2:INSERT_BEG\n3:INSERT_END\n4:INSERT_MID\n5:DEL_BEG\n6:DEL_END\n7:DEL_MID\nCHOICE:");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\n");
				display();
				break;
			case 2:
				printf("\n");
				insert_beg();
				break;
			case 3:
				printf("\n");
				insert_end();
				break;
			case 4:
				printf("\n");
				insert_mid();
				break;	
			case 5:
				printf("\n");
				del_beg();
				break;		
			case 6:
				printf("\n");
				del_end();
				break;
			case 7:
				printf("\n");
				del_mid();
				break;											
			case 0:
				break;
			default:
				printf("WRONG CHOICE! \n");
		}
		printf("\n");
	}while(choice!=0);
}

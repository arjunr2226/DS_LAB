#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*tail=NULL;

void insert_beg()
 {
 	struct node *newnode;
 	newnode = (struct node*)malloc(sizeof(struct node));
 	newnode->next = NULL;
 	printf("ENTER THE DATA: ");
 	scanf("%d", &newnode->data);
 	if(tail == NULL)
 	{
 		tail = newnode;
 		tail->next = tail;
 	}
 	else
 	{
 		newnode->next = tail->next;
 		tail->next = newnode;
 	}
}

void insert_end()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("ENTER THE DATA: ");
	scanf("%d", &newnode->data);
	if(tail == NULL)
	{
		tail = newnode;
		tail->next = tail;
	}
	else
	{
		newnode->next = tail->next;
		tail->next = newnode;
		tail = newnode;
	}
}

void insert_mid()
{
	struct node *newnode, *temp=tail->next;
	int pos;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->next = NULL;
	printf("ENTER THE POSITION: ");
	scanf("%d", &pos);
	printf("ENTER DATA: ");
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
		tail = newnode;
	}
	
}

void del_beg()
{
	if(tail == NULL)
		printf("EMPTY\n");
	else if(tail == tail->next)
	{	
		free(tail);
		tail=NULL;
	}
	else
	{
		struct node *temp=tail->next;
		tail->next = temp->next;
		free(temp);
	}
}

void del_end()
{
	if(tail == NULL)
		printf("EMPTY\n");
	else if(tail == tail->next)
	{
		free(tail);
		tail = NULL;
	}
	else
	{
		struct node *temp=tail->next;
		while(temp->next != tail)
			temp = temp->next;
		temp->next = tail->next;
		free(tail);
		tail = temp;
	}
}

void del_mid()
{
	if(tail == NULL)
		printf("EMPTY\n");
	else if(tail == tail->next)
	{
		printf("DELETING LAST NODE..\n");
		free(tail);
		tail = NULL;
	}
	else
	{
		struct node *temp=tail->next, *temp1;
		int pos;
		printf("ENTER THE POSITION: ");
		scanf("%d", &pos);
		while(pos > 2)
		{
			temp = temp->next;
			pos--;
		}
		temp1 = temp->next;
		temp->next = temp1->next;
		if(temp1 == tail)
		{
			tail = temp;
		}
		free(temp1);
	}
}

void display()
{
 	if(tail == NULL)
 		printf("EMPTY\n");
 	else{
 		struct node *temp=tail->next;
 		do{
	 		printf("%d ", temp->data);
	 		temp = temp->next;
 		}while(temp != tail->next);
 	}	
 	printf("\n");
}

void create()
{
	int n, i;
	printf("HOW MANY NODES: ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
			insert_end();
	printf("\n");
}

void main()
{
	int choice;
	do
	{
		printf("\n");
		printf("ENTER \n0:EXIT\n1:DISPLAY\n2:INSERT_BEG\n3:INSERT_END\n4:INSERT_MID\n5:DEL_BEG\n6:DEL_END\n7:DEL_MID\n8:CREATE\nCHOICE:");
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
			case 8:
				printf("\n");
				create();
				break;											
			case 0:
				break;
			default:
				printf("WRONG CHOICE! \n");
		}
		printf("\n");
	}while(choice!=0);
}

/*C-program to implement Single Linked List using Dynamic Memory Allocation*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

#define ISEMPTY printf("\nEmpty List:");
struct node
{
	int value;
	struct node *next;
};
typedef struct node snode;
snode *create_node(int);
void insert_node_first();
void insert_node_last();
void insert_node_pos();
void sorted_ascend();
void delete_pos();
void search();
void update_val();
void display();
void rev_display(snode*);
snode *newnode,*ptr,*prev,*temp;
snode *first=NULL,*last=NULL;
int main()
{
	int ch;
	char ans='y';
	while(ans=='Y'||ans=='y')
	{
		printf("\n-------------------------------------\n");
		printf("\nOperations on Singly Linked List\n");
		printf("\n-------------------------------------\n");
		printf("\n1.Insert Node At First");
		printf("\n2.Insert Node At Last");
		printf("\n3.Insert Node At Position");
		printf("\n4.Sort Linked List In Ascending Order");
		printf("\n5.Delete Node From Any Position");
		printf("\n6.Update Node Value");
		printf("\n7.Search Element In The Linked List");
		printf("\n8.Display List From Beginning To End");
		printf("\n9.Display List From End Using Recursion");
		printf("\n10.EXIT");
		printf("\n-------------------------------------\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\n...Inserting node at first...\n");
			insert_node_first();
			break;
		case 2:
			printf("\n...Inserting node at last...\n");
			insert_node_last();
			break;
		case 3:
			printf("\n...Inserting node at position...\n");
			insert_node_pos();
			break;
		case 4:
			printf("\n...Sorted linked list in ascending order...\n");
			sorted_ascend();
			break;
		case 5:
			printf("\n...Deleting node from any position...\n");
			delete_pos();
			break;
		case 6:
			printf("\n...Updating node value...\n");
			update_val();
			break;
		case 7:
			printf("\n...Searching element in the list...\n");
			search();
			break;
		case 8:
			printf("\n...Displaying list from beginning to end...\n");
			display();
			break;
		case 9:
			printf("\n...Displaying list from end using recursion...\n");
			rev_display(first);
			break;
		case 10:
			printf("\n...Exiting...\n");
			return 0;
		default:
			printf("\n...Invalid Choice...\n");
			break;
		}
		printf("\nYou want to continue? (Y/N) : ");
		scanf(" %c",&ans);
	}
	return 0;
}
//creating a new node..
snode *create_node(int val)
{
	newnode=(snode*)malloc(sizeof(snode));
	if(newnode==NULL)
	{
		printf("\nMemory was not allocated");
		return 0;
	}
	else
	{
		newnode->value=val;
		newnode->next=NULL;
		return newnode;
	}
}
//inserting node at first..
void insert_node_first()
{
	int val;
	printf("\nEnter the value for the node : ");
	scanf("%d",&val);
	newnode=create_node(val);
	if(first==last && first==NULL)
	{
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;
	}
	else
	{
		temp=first;
		first=newnode;
		first->next=temp;
	}
	printf("\n...Inserted...\n");
}
//inserting node at last..
void insert_node_last()
{
	int val;
	printf("\nEnter the value for the node : ");
	scanf("%d",&val);
	newnode=create_node(val);
	if(first==last && last==NULL)
	{
		first=last=newnode;
		first->next=NULL;
		last->next=NULL;
	}
	else
	{
		last->next=newnode;
		last=newnode;
		last->next=NULL;
	}
	printf("\n...Inserted...\n");
}
//inserting node at position..
void insert_node_pos()
{
	int pos,val,cnt=0,i;
	printf("\nEnter the value for the node : ");
	scanf("%d",&val);
	newnode=create_node(val);
	printf("\nEnter the position : ");
	scanf("%d",&pos);

    
	ptr=first;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		cnt++;
	}
	if(pos==1)
	{
		if(first==last && first==NULL)
		{
			first=last=newnode;
			first->next=NULL;
			last->next=NULL;
		}
		else
		{
			temp=first;
			first=newnode;
			first->next=temp;
		}
		printf("\n...Inserted...\n");
	}
	else if(pos>1 && pos<=cnt)
	{
		ptr=first;
		for(i=1;i<pos;i++)
		{
			prev=ptr;
			ptr=ptr->next;
		}
		prev->next=newnode;
		newnode->next=ptr;
		printf("\n...Inserted...\n");
	}
	else
	{
		printf("\nPosition is out of range\n");
	}
}
//sorting linked list..
void sorted_ascend()
{
	snode *nxt;
	int t;
	if(first==NULL)
	{
		ISEMPTY;
		printf(":No elements to sort\n");
	}
	else
	{
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			for(nxt=ptr->next;nxt!=NULL;nxt=nxt->next)
			{
				if(ptr->value>nxt->value)
				{
					t=ptr->value;
					ptr->value=nxt->value;
					nxt->value=t;
				}
			}
		}
		printf("\n...Sorted List...\n");
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			printf("%d\t",ptr->value);
		}
	}
}
//delete node from specified position in a non-empty list..
void delete_pos()
{
	int pos,cnt=0,i;
	if(first==NULL)
	{
		ISEMPTY;
		printf(":No node to delete\n");
	}
	else
	{
		printf("\nEnter the position of value to be deleted : ");
		scanf("%d",&pos);
		ptr=first;
		if(pos==1)
		{
			first=ptr->next;
			printf("\nElement Deleted\n");
		}
		else
		{
			while(ptr!=NULL)
			{
				ptr=ptr->next;
				cnt=cnt+1;
			}
			if(pos>0 && pos<=cnt)
			{
				ptr=first;
				for(i=1;i<pos;i++)
				{
					prev=ptr;
					ptr=ptr->next;
				}
				prev->next=ptr->next;
			}
			else
			{
				printf("\nPosition is out of range\n");
			}
			free(ptr);
			printf("\nElement deleted\n");
		}
	}
}
//updating node value in a non-empty list..
void update_val()
{
	int oldval,newval,flag=0;
	if(first==NULL)
	{
		ISEMPTY;
		printf(":No nodes in the list to update\n");
	}
	else
	{
		printf("\nEnter the value to be updated : ");
		scanf("%d",&oldval);
		printf("\nEnter new value : ");
		scanf("%d",&newval);
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			if(ptr->value==oldval)
			{
				ptr->value=newval;
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nUpdated Successfully\n");
		}
		else
		{
			printf("\nValue not found in the list\n");
		}
	}
}
//searching an element in a non-empty list..
void search()
{
	int flag=0,key,pos=0;
	if(first==NULL)
	{
		ISEMPTY;
		printf(":No nodes in the list\n");
	}
	else
	{
		printf("\nEnter the value to search : ");
		scanf("%d",&key);
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			pos=pos+1;
			if(ptr->value==key)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("\nElement %d found at %d position\n",key,pos);
		}
		else
		{
			printf("\nElement %d not found in the list\n",key);
		}
	}
}
//display non-empty list from beginning to end..
void display()
{
	if(first==NULL)
	{
		ISEMPTY;
		printf(":No nodes in the list to display\n");
	}
	else
	{
		for(ptr=first;ptr!=NULL;ptr=ptr->next)
		{
			printf("%d\t",ptr->value);
		}
	}
}
//display non-empty list in reverse order..
void rev_display(snode *ptr)
{
	int val;
	if(ptr==NULL)
	{
		ISEMPTY;
		printf(":No nodes to display\n");
	}
	else
	{
		if(ptr!=NULL)
		{
			val=ptr->value;
			rev_display(ptr->next);
			printf("%d\t",val);
		}
	}
}
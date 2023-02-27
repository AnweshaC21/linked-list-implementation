#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int n;
	struct node *next;
}*h,*temp,*temp1,*temp2,*temp4;
void insertbeg();
void insertend();
void insert_at_pos();
void traversebeg();
//void traverseend(int);
void sort();
void search();
void update();
void delete();
int count=0;

int main()
{
	int ch;
	char ans='y';
	while(ans=='Y'||ans=='y')
	{
		printf("\n-------------------------------------\n");
		printf("\nOperations on Doubly Linked List\n");
		printf("\n-------------------------------------\n");
		printf("\n1.Insert Node At First");
		printf("\n2.Insert Node At Last");
		printf("\n3.Insert Node At Position");
		printf("\n4.Delete Node From Position");
		printf("\n5.Traverse from Beginning");
  //	       	printf("\n6.Traverse from End");
		printf("\n7.Sort The List");
		printf("\n8.Search Element In The Linked List");
		printf("\n9.Update Value Of A Node");
		printf("\n10.EXIT");
		printf("\n-------------------------------------\n");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\n...Inserting node at first...\n");
			insertbeg();
			break;
		case 2:
			printf("\n...Inserting node at last...\n");
			insertend();
			break;
		case 3:
			printf("\n...Inserting node at position...\n");
			insert_at_pos();
			break;
		case 4:
			printf("\n...Deleting node from any position...\n");
			delete();
			break;
		case 5:
			printf("\n...Displaying list from beginning to end...\n");
			traversebeg();
			break;
    /*		case 6:
			printf("\n...Displaying list from end...\n");
			traverseend(count);
			break;
    */
		case 7:
			printf("\n...Sorting linked list in ascending order...\n");
			sort();
			break;
		case 8:
			printf("\n...Searching element in the list...\n");
			search();
			break;
		case 9:
			printf("\n...Updating node value...\n");
			update();
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

/*to create an empty node*/
void create()
{
	int data;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\nEnter value of node : ");
	scanf("%d",&data);
	temp->n=data;
	count++;
}

/*insert at beginning*/
void insertbeg()
{
	if(h==NULL)
	{
		create();
		h=temp;
		temp1=h;
	}
	else
	{
		create();
		temp->next=h;
		h->prev=temp;
		h=temp;
	}
}

/*insert at end*/
void insertend()
{
	if(h==NULL)
	{
		create();
		h=temp;
		temp1=h;
	}
	else
	{
		create();
		temp1->next=temp;
		temp->prev=temp1;
		temp1=temp;
	}
}

/*to insert at any position*/
void insert_at_pos()
{
	int pos,i=2;
	printf("Enter position to be inserted : ");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1) || (pos>=count+1))
	{
		printf("\nPosition out of range to insert");
		return;
	}
	if((h==NULL) && (pos!=1))
	{
		printf("\nEmpty list, cannot insert other than first position");
		return;
	}
	if((h==NULL) && (pos!=1))
	{
		create();
		h=temp;
		temp1=h;
		return;
	}
	else
	{
		while(i<pos)
		{
			temp2=temp2->next;
			i++;
		}
		create();
		temp->prev=temp2;
		temp->next=temp2->next;
		temp2->next->prev=temp;
		temp2->next=temp;
	}
}

/*to delete an element*/
void delete()
{
	int i=1,pos;
	printf("Enter position to be detected : ");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1) || (pos>count+1))
	{
		printf("\nError : Position out of range to delete");
		return;
	}
	if(h==NULL)
	{
		printf("\nError : Empty list, no elements to delete");
		return;
	}
	else
	{
		while(i<pos)
		{
			temp2=temp2->next;
			i++;
		}
		if(i==1)
		{
			if(temp2->next==NULL)
			{
				printf("Node deleted from list");
				free(temp2);
				temp2=h=NULL;
				return;
			}
		}
		if(temp2->next==NULL)
		{
			temp2->prev->next=NULL;
			free(temp2);
			printf("Node deleted from list");
			return;
		}
		temp2->next->prev=temp2->next;
		if(i!=1)
		{
			temp2->prev->next=temp2->next;
		}
		if(i==1)
		{
			h=temp2->next;
		}
		printf("\nNode deleted");
		free(temp2);
	}
	count--;
}

/*traverse from beginning*/
void traversebeg()
{
	temp2=h;
	if(temp2==NULL)
	{
		printf("List empty to display\n");
		return;
	}
	printf("\nLinked list elements from beginning : ");
	while(temp2->next!=NULL)
	{
		printf(" %d ",temp2->n);
		temp2=temp2->next;
	}
	printf(" %d ",temp2->n);
}

/*to traverse from end using recursion
void traverseend(int i)
{
	if(temp2!=NULL)
	{
		i=temp2->n;
		temp2=temp2->next;
		traverseend(i);
		printf(" %d ",i);
	}
}
*/

/*to search for an element in the list*/
void search()
{
	int data,count=0;
	temp2=h;
	if(temp2==NULL)
	{
		printf("Error : List empty to search for data");
		return;
	}
	printf("Enter value to search : ");
	scanf("%d",&data);
	while(temp2!=NULL)
	{
		if(temp2->n==data)
		{
			printf("\nData found in %d position",count+1);
			return;
		}
		else
			temp2=temp2->next;
		count++;
	}
	printf("\nError : %d not found in the list",data);
}

/*to update a node value in the list*/
void update()
{
	int data,data1;
	printf("Enter node data to be updated : ");
	scanf("%d",&data);
	printf("Enter new data : ");
	scanf("%d",&data1);
	temp2=h;
	if(temp2==NULL)
	{
		printf("\nError : List empty no node to update");
		return;
	}
	while(temp2!=NULL)
	{
		if(temp2->n==data)
		{
			temp2->n=data1;
			traversebeg();
			return;
		}
		else
			temp2=temp2->next;
	}
	printf("\nError : %d not found in list to update",data);
}

/*to sort the linked list*/
void sort()
{
	int i,j,x;
	temp2=h;
	temp4=h;
	if(temp2==NULL)
	{
		printf("List empty to sort");
		return;
	}
	for(temp2=h;temp2!=NULL;temp2=temp2->next)
	{
		for(temp4=temp2->next;temp4!=NULL;temp4=temp4->next)
		{
			if(temp2->n>temp4->n)
			{
				x=temp2->n;
				temp2->n=temp4->n;
				temp4->n=x;
			}
		}
	}
	traversebeg();
}
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} list;
list *first,*temp,*prev,*newnode;

void insertnode(int);
void listIn();
void listOut();
void remN();

int main()
{
    printf("\nInput values into list\n");
    listIn();
    printf("\nGiven  List   : ");
    listOut();
    remN();
    printf("\nReversed List : ");
    listOut();
    return 0;
}
void listIn()
{
    int data,choice=1;
    do
    {
        printf("Enter a number : ");
        scanf("%d",&data);
        insertnode(data);
        printf("Insert more? (0/1) : ");
        scanf("%d",&choice);
    } while (choice==1);
}
void insertnode(int data)
{
    newnode=malloc(sizeof(list));
    newnode->val=data;
    newnode->next=NULL;
    if(first==NULL)
    {
        first=newnode;
        return;
    }
    temp=first;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
}
void listOut()
{
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    temp=first;
    while(temp->next!=NULL)
    {
        printf("%d-->--",temp->val);
        temp=temp->next;
    }
    printf("%d\n",temp->val);
}
void remN()
{
    int n,i,j,count=0,t;
    printf("\nEnter value of n : ");    
    scanf("%d",&n);
    temp=first;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    temp=first;
    for(i=1;i<=count-n;i++)
    {
		prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
	free(temp);
}
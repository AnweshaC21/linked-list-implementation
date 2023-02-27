#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} list;
list *first,*temp,*temp1,*newnode;

void insertnode();
void listIn();
void listOut();
void reverse();

int main()
{
    printf("\nInput values into list\n");
    listIn();
    printf("\nGiven  List   : ");
    listOut();
    reverse();
    printf("Reversed List : ");
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
void reverse()
{
    int i,j,count=0,t;
    temp=first;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    for(i=1;i<=count/2+1;i++)
    {
        temp=first;
        temp1=first;
        for(j=1;j<i;j++)
            temp=temp->next;
        for(j=1;j<count-i+1;j++)
            temp1=temp1->next;
        t=temp->val;
        temp->val=temp1->val;
        temp1->val=t;
    }
    
}
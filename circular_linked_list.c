#include <stdio.h>
#include <malloc.h>

struct node
{
    int value;
    struct node *next;
} *newnode, *temp, *prev, *first = NULL;
int num;

void insertbeg ();
void insertend ();
void insertpos ();
void deletebeg ();
void deleteend ();
void deletepos ();
void updatebypos ();
void updatebyvalue ();
void display ();

int main()
{
	int ch,ch1,ans=1;
	//clrscr();
	while(ans==1)
	{
		printf("\nOperations on Singly Linked List\n");
		printf("\n1. Insert");
		printf("\n2. Delete ");
		printf("\n3. Update");
		printf("\n4. Display");
		printf("\n5. EXIT");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\t1) Insert at beginning");
			printf("\n\t2) Insert at end");
			printf("\n\t3) Insert at any position");
			printf("\n\tEnter position in which value is to be inserted :");
			scanf("%d",&ch1);
			switch(ch1)
			{
				case 1:
					insertbeg();
					break;
				case 2:
					insertend();
					break;
				case 3:
					insertpos();
					break;
				default:
					printf("\n...Invalid Choice...\n");
					break;
			}
			break;
		case 2:
			if(first==NULL)
			{
				printf("\nList Empty\n");
				break;
			}
			printf("\t1) Delete from beginning");
			printf("\n\t2) Delete from end");
			printf("\n\t3) Delete from any position");
			printf("\n\tEnter position from which value is to be deleted :");
			scanf("%d",&ch1);
			switch(ch1)
			{
				case 1:
					deletebeg();
					break;
				case 2:
					deleteend();
					break;
				case 3:
					deletepos();
					break;
				default:
					printf("\n...Invalid Choice...\n");
					break;
			}
			break;
		case 3:
            printf("\n\t1) Delete from end");
			printf("\n\t2) Delete from any position");
			printf("\n\tEnter position from which value is to be deleted :");
			scanf("%d",&ch1);
			switch(ch1)
            {
                case 1:
                    updatebypos();
                    break;
                case 2:
                    updatebyvalue();
                    break;
                default:
                    printf("\n...Invalid Choice...\n");
                    break;
            }
            break;
		case 4:
			display();
			break;
		case 5:
			printf("\n...Exiting...\n");
			return 0;
		default:
			printf("\n...Invalid Choice...\n");
			break;
		}
		printf("\nYou want to continue? (0/1) : ");
		scanf("%d",&ans);
	}
	//getch();
	return 0;
}

void insertbeg ()
{
    printf("Enter the element : ");
        scanf("%d", &num);
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode ->value = num;
    if (first == NULL)
    {
        newnode ->next = newnode;
    }
    else
    {
        temp = first;
        while (temp ->next != first)
            temp = temp ->next ;
        temp ->next = newnode;
        newnode ->next = first;
    }
    first = newnode;
}

void insertend ()
{
    if (first == NULL)
        insertbeg ();
    else
    {
        printf("Enter the element : ");
        scanf("%d", &num);
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode ->value = num;
        temp = first;
        while (temp ->next != first)
            temp = temp ->next;
        temp ->next = newnode;
        newnode ->next = first;
    }
}

void insertpos ()
{
    int pos, count = 1, i;
    printf("Enter the position : ");
        scanf("%d", &pos);
    temp = first;
    while (temp ->next != first)
    {
        temp = temp ->next;
        count++;
    }

    if (pos == 1)    
        insertbeg ();

    else if ( pos <= count + 1 && pos > 1)    
    {
        printf("Enter the element : ");
        scanf("%d", &num);
        newnode = (struct node *) malloc(sizeof(struct node));
        newnode ->value = num;
        temp = first;
        for (i = 0; i < pos - 1; i++)
        {
            prev = temp;
            temp = temp ->next;
        }
        prev ->next = newnode;
        newnode ->next = temp;
    }
    
    else
        printf("Out of range \n");

}   

void deletebeg ()
{
    if (first == NULL) 
        printf("Empty List \n");

    else if (first ->next == first)
    {
        free (first);
        first = NULL;
    }

    else 
    {
        temp = first;
        while (temp ->next != first)
            temp = temp ->next;
        temp ->next = first ->next;
        free(first);
        first = temp ->next;
    }
}

void deleteend ()
{
    if (first == NULL) 
        printf("Empty List \n");
    
    else if (first ->next == NULL)
        deletebeg();

    else 
    {
        temp = first;
        while (temp ->next != first)
        {
            prev = temp;
            temp = temp ->next;
        }
        prev ->next = temp ->next;
        free(temp);
    }
}

void deletepos ()
{
    int pos, count = 1, i;
    if (first == NULL)
        printf("Empty List \n");

    else
    {
        printf("Enter the position to be deleted : ");
            scanf("%d", &pos);
        temp = first;
        if (pos == 1)
            deletebeg();

        else
        {
            while (temp ->next != first)
            {
                temp = temp ->next;
                count ++;
            }
            if (pos <= count && pos > 1)
            {
                temp = first;
                for (i = 0; i < pos -1; i++)
                {
                    prev = temp;
                    temp = temp ->next;
                }
                prev ->next = temp ->next;
            }

            else
                printf("Out of range \n");
            free (temp);
        }
    }
}

void updatebypos ()
{
    int pos, i, count = 1;
    if (first == NULL) 
        printf("Empty List \n");

    else
    {
        printf("Enter the position to be updated : ");
            scanf("%d", &pos);
        temp = first;
        while (temp ->next != first)
            {
                temp = temp ->next;
                count ++;
            }
        temp = first;
        if (pos <= count)
        {
            printf("Enter the element : ");
                scanf("%d", &num);
            for (i = 0; i < pos - 1; i++)
            {
                temp = temp ->next;
            }
            temp ->value = num;
        }

        else
            printf("Out of range \n");
    }
}

void updatebyvalue ()
{
    int old, i;
    if (first == NULL) 
        printf("Empty List \n");

    else
    {
        printf("Enter old value : ");
            scanf("%d", &old);
        printf("Enter new value : ");
            scanf("%d", &num);
        temp = first;
        while (temp ->next != first)
        {
            temp = temp ->next;
            if (temp ->value == old)
            {
                temp ->value = num;
                return;
            }
        }
        if (temp ->value == old)
        {
            temp ->value = num;
            return;
        }        
        printf("Value not found \n");
    }
}

void display ()
{
    if (first == NULL)
        printf("Link List is Empty !!! \n");

    else
    {
        temp = first;
        while (temp ->next != first)
        {
            printf ("%d\t", temp -> value);
            temp = temp ->next;
        }
        printf ("%d\t\n", temp -> value);
    }
}
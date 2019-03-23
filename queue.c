#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>

struct node *head;

struct node
{
    int num;
    struct node *next;
};

void enqueue(int item);
int dequeue(void);
void front(void);
void tail(void);
bool isEmpty(void);

int main()
{
    int choice,item,n;
    bool checkEmpty;

    head=NULL;

    do
    {
        system("cls");
        printf("Menu\n1]Enqueue\n2]Dequeue\n3]Front\n4]Tail\n5]Empty\n6]Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("Enter a number to add: ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: n=dequeue();
                    printf("Dequeuing of %d successful!",n);
                    getch();
                    break;
            case 3: front();
                    break;
            case 4: tail();
                    break;
            case 5: checkEmpty=isEmpty();
                    if(checkEmpty)
                    {
                        printf("Queue is empty.");
                        getch();
                    }
                    else
                    {
                        printf("Queue is not empty.");
                        getch();
                    }
                    break;
            case 6: printf("Exiting...");
                    break;
        }
    }while(choice!=6);

    return 0;
}

//Functions
void enqueue(int item)
{
    struct node *temp,*current,*tmpr;

    temp=malloc(sizeof (struct node));
    temp->num=item;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        current=temp;
    }
    else
    {
        tmpr=head;
        while(tmpr->next!=NULL)
        {
            tmpr=tmpr->next;
        }
        tmpr->next=temp;
    }
    tmpr=NULL;

    printf("Enqueue successful!");
    getch();
    return;
}
int dequeue(void)
{
    struct node *tpr;
    int i;

    tpr=head;
    i=tpr->num;
    head=head->next;
    free(tpr);
    return i;
}
void front(void)
{
    struct node *ptr;

    ptr=head;
    printf("Front = %d",ptr->num);
    ptr=NULL;
    getch();
    return;
}
void tail(void)
{
    struct node *tp;
    int num1;

    tp=head;

    while(tp!=NULL)
    {
        num1=tp->num;
        tp=tp->next;
    }

    printf("Tail = %d",num1);
    getch();
    return;
}
bool isEmpty(void)
{
    bool empty;

    if(head==NULL)
        empty=true;
    else
        empty=false;
    return empty;
}

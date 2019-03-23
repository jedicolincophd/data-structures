#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

typedef struct node
{
    int num;
    struct node *prev, *next;
}NODE;

NODE *create(void);

void insert(NODE *,NODE *);
int findRoot(NODE *);
bool isPresent(int,NODE *);
int smallest(NODE *);
int highest(NODE *);
bool siblings(int,int);
int level(int);
int height(NODE *);
void inOrder(NODE *);
void preOrder(NODE *);
void postOrder(NODE *);

int main()
{
    NODE *root,*temp;
    int choice,elem,n,i;
    int num1,num2,rootnum;
    int search,hNum,max,min;
    bool sFound;
    char ch;

    root=NULL;
    do
    {
        system("cls");
        printf("\nBinary Search Tree\n\n");
        printf("\nChoose a desired operation:\n");
        printf("\n1]  Create a binary search tree");
        printf("\n2]  Return root value");
        printf("\n3]  Search a number in the tree");
        printf("\n4]  Return smallest number in the tree");
        printf("\n5]  Return largest number in the tree");
        printf("\n6]  Confirm if two numbers are siblings");
        printf("\n7]  Return level of a certain number");
        printf("\n8]  Return the height of a tree");
        printf("\n9]  Traverse inorder");
        printf("\n10] Traverse preorder");
        printf("\n11] Traverse postorder");
        printf("\n12] Exit");
        printf("\n\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: system("cls");
                    do
                    {
                        temp=create();
                        if(root==NULL)
                            root=temp;
                        else
                            insert(root,temp);

                        printf("\nEnter more data (y/n)?");
                        scanf(" %c",&ch);
                    }while(ch=='y'||ch=='Y');
                    break;
            case 2: rootnum=findRoot(root);
                    printf("The value of the root is %d.",rootnum);
                    getch();
                    break;
            case 3: printf("Enter the number to be searched: ");
                    scanf("%d",&search);
                    sFound=isPresent(search,root);
                    if(sFound)
                    {
                        printf("Found: %d is present in the tree.",search);
                        getch();
                    }
                    else
                    {
                        printf("Not found: %d is not present in the tree.",search);
                        getch();
                    }
                    break;
            case 4: min=smallest(root);
                    printf("The smallest number is %d.",min);
                    getch();
                    break;
            case 5: max=highest(root);
                    printf("The highest number is %d.",max);
                    getch();
                    break;
            case 6: break;
            case 7: break;
            case 8: hNum=height(root);
                    printf("The height of the tree is %d.",hNum);
                    getch();
                    break;
            case 9: printf("In-order traversal\n");
                    inOrder(root);
                    getch();
                    break;
            case 10: printf("Preorder traversal\n");
                     preOrder(root);
                     getch();
                     break;
            case 11: printf("Posorder traversal\n");
                     postOrder(root);
                     getch();
                     break;
            case 12: system("cls");
                     printf("Exiting...");
                     getch();
                     break;
            default: system("cls");
                     printf("Error: invalid choice. Please try again.");
                     getch();
                     break;
        }
    }while(choice!=12);
    return 0;
}

//Functions
NODE *create(void)
{
    NODE *temp;
    printf("\n Enter an element: ");
    temp=(NODE *)malloc(sizeof(NODE));
    scanf("%d",&temp->num);
    temp->prev=temp->next=NULL;
    return temp;
}

void insert(NODE *root,NODE *temp)
{
    if(temp->num<root->num)
    {
        if(root->prev!=NULL)
            insert(root->prev,temp);
        else
            root->prev=temp;
    }
    if(temp->num>root->num)
    {
        if(root->next!=NULL)
            insert(root->next,temp);
        else
            root->next=temp;
    }
}

int findRoot(NODE *root)
{
    return(root->num);
}

bool isPresent(int search,NODE *root)
{
    bool found=false;

    if(root==NULL)
        return found;
    if(search>root->num)
        return isPresent(search,root->next);
    else if(search<root->num)
        return isPresent(search,root->prev);
    else
        found=true;

    return found;
}

int smallest(NODE *root)
{
    while(root->prev!=NULL)
    {
        root=root->prev;
    }
    return root->num;
}

int highest(NODE *root)
{
    while(root->next!=NULL)
    {
        root=root->next;
    }
    return root->num;
}

bool siblings(int n1,int n2)
{
}

int level(int num2)
{
}

int height(NODE *root)
{
    int height=0;

    return;
}

void inOrder(NODE *root)
{
    if(root!=NULL)
    {
        inOrder(root->prev);
        printf("%d ",root->num);
        inOrder(root->next);
    }
}

void preOrder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->num);
        preOrder(root->prev);
        preOrder(root->next);
    }
}

void postOrder(NODE *root)
{
    if(root!=NULL)
    {
        postOrder(root->prev);
        postOrder(root->next);
        printf("%d ",root->num);
    }
}

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define FLUSH while(getchar()!='\n');

int ar[50];

void push(int ar[],int t,int j);
int pop(int ar[],int j);
void isEmpty(void);

int main()
{
    char exp[50];
    char num[0];
    int ex,t,i,num1,num2,ans,p,j=0;

    printf("Enter a postfix expression: ");
    scanf("%s",&exp);
    FLUSH;

    for(i=0;i<strlen(exp);i++)
    {
        if (exp[i] == '+')
        {
            printf("operand detected\n");
            num1=pop(ar,j);
            j--;
            num2=pop(ar,j);
            j--;
            ans=num2+num1;
            push(ar,ans,j);
            j++;
        }
        else if(exp[i] == '-')
        {
            printf("operand detected\n");
            num1=pop(ar,j);
            j--;
            num2=pop(ar,j);
            j--;
            ans=num2-num1;
            push(ar,ans,j);
            j++;
        }
        else if(exp[i] == '*')
        {
            printf("operand detected\n");
            num1=pop(ar,j);
            j--;
            num2=pop(ar,j);
            j--;
            ans=num2*num1;
            push(ar,ans,j);
            j++;
        }
        else if(exp[i] == '/')
        {
            printf("operand detected\n");
            num1=pop(ar,j);
            j--;
            num2=pop(ar,j);
            j--;
            ans=num2/num1;
            push(ar,ans,j);
            j++;
        }
        else
        {
            num[0]=exp[i];
            printf("array = %c",exp[i]);
            t=atoi(num);

            printf(" num = %d\n",t);

            push(ar,t,j);
            j++;
        }
    }

    printf("The answer is %d\n",ans);

    getch();
    return 0;
}
//Functions
void push(int ar[],int t,int j)
{
    ar[j]=t;
    return;
}
int pop(int ar[],int j)
{
    int x;

    x=ar[j-1];
    return x;
}
void isEmpty(void)
{
    ;
}


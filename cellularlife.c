#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

int main()
{
	int row,col=11;
	int x,y,gen;
	
	printf("Input the number of generations: ");
	scanf("%d",&row);
	
	printf("What column should the cell be positioned: ");
	scanf("%d",&gen);
	printf("\n");
	
	int ar[row][col];
	gen--;
	
	for(x=0;x<row;x++)
	{
        for(y=0;y<col;y++)
        {
		if(x==0&&y==gen)
                	ar[x][y]=1;
		else
                	ar[x][y]=0;
        }
    }

	for(x=0;x<row;x++)
	{
		for(y=0;y<col;y++)
		{
			if(ar[x][y]==1)
			{
				if((ar[x][y-1]!=1)&&(ar[x][y+1]!=1))
					if(x+1!=row)
                        ar[x+1][y]=1;
                    else
                        break;
				else if((ar[x][y+1]==1)&&(ar[x][y-1]!=1))
					if(x+1!=row)
                        ar[x+1][y]=1;
                    else
                        break;
			}
			else
			{
				if((ar[x][y-1]==1)&&(ar[x][y+1]!=1))
					if(x+1!=row)
                        ar[x+1][y]=1;
                    else
                        break;
				else if((ar[x][y+1]==1)&&(ar[x][y-1]!=1))
					if(x+1!=row)
                        ar[x+1][y]=1;
                    else
                        break;
                else if(y==col-1)
                {
                    if(ar[x][y-1]==1)
                        ar[x+1][y]=1;
                    else if(ar[x][y-1]!=1)
                        ar[x+1][y]=0;
                }
			}
		}
	}

	for(x=0;x<row;x++)
	{
        for(y=0;y<col;y++)
        {
            if(ar[x][y]==1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
        getch();
    }
	
	getch();
	return 0;
}

//Author: Double X Li
//Date: 2014-10-01 

#include <stdio.h>
#include <time.h>

int num[9][9] = {0};
int x = 0;

int findrow(int row, int column)
{
	if(column == 8)
		return row + 1;
	else 
		return row;
}

int findcolumn(int row, int column)
{
	if(column == 8)
		return 0;
	else 
		return column + 1;
}

void print()
{
	int row, column;
	for(row = 0; row < 9; row++)
	{
		for(column = 0; column < 9; column++)
		{
			printf("%-2d",num[row][column]);
		}
		printf("\n");
	}
	printf("\n");
}

int cando(int k, int row, int column)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		if(k == num[i][column] || k == num[row][i])
			return 0;
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			if(num[row / 3 * 3 + i][column / 3 * 3 + j] == k)
				return 0;
		}
	}
	return 1;
}

int work(int n, int row, int column)
{
	int i;
	x++;
	if(num[row][column] != 0)
    {
        if(n == 80)
		{
			print();
			if(i == 1)
				return 0;
		}
        work(n + 1, findrow(row, column), findcolumn(row, column));
        return 0;
    }
    for(i = 9; i > 0; i--)
    {
  		if(cando(i, row, column))
  		{
 			num[row][column] = i;
 			if(n == 80)
			{
				print();
				if(i == 1)
					return 0;
			}
 			work(n + 1, findrow(row, column),findcolumn(row, column));
  		}
   	}
    num[row][column] = 0;
}

int main()
{
	int row, column;
	clock_t start, finish;
	double duration = 0.0;
	
	for(row = 0; row < 9; row++)
	{
        for(column = 0; column < 9; column++)
        {
            scanf("%d",&num[row][column]);
        }
    }
	printf("\n"); 
	start = clock();
	work(0,0,0);
	printf("\nx = %d",x);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n%f seconds\n",duration);
	return 0;
}

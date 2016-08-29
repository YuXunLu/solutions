/* Pay attention: this file should be compiled under C++ environment */
#include <cstdio>
#include <cstring>
#include <cstdlib.h>
#include <iostream>
using namespace std;
const int N = 500+2;
long long int mat[N][N];
int main()
{
	int n = 0;
	scanf("%d", &n);
	int mark_row = -1;
	int mark_col = -1;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 0) //find the space
			{
				mark_row = i;
				mark_col = j;
			}
		}
	}
	long long int diag_main = 0, diag_sec = 0;
	bool space_on_row = false;
	bool flag = true;
	if ( (i == j) || ( ( i + j ) == n - 1) )
	{
		space_on_row = true;
	}
	for(int i = 0; i < n; i++)
	{
		diag_main = diag_main + mat[i][i];
		diag_sec = diag_sec + mat[i][n - 1 - i];
	}
	if ( (diag_main != diag_sec) && !space_on_row)
		flag = false;
/*	1. The space is not on the both diagnoal lines, and the diagonal lines' sum equals to each other 
	2. The space is on the diagnoal lines (either of them is OK)
*/
// Condition 1
	if ( !space_on_row)
	{
		if (flag) //the standard will be the sum of both diagoal line
		{
			//line checking
			for (int i = 0; i < n; i++)
			{
				long long int row_res = 0;
				if ( i == mark_row )
					continue;
				for(int j = 0; j < n; j++)
				{
					row_res = row_res + mat[i][j];
				}
				if ( row_res != diag_main )
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				printf("-1\n");
			else
			{
				//line checking bypassed
				for (int i = 0; i < n; i++)
				{
					long long int col_res = 0;
					for(int j = 0; j < n; j++)
					{
						col_res = col_res + mat[i][j];
					}
					if ( col_res != diag_main )
					{
						flag = false;
						break;
					}
				}
				if ( flag ) //column chekcing bypassed
				{
				}
				else
					printf("-1\n");
			}
		}
		else
		{
			printf("-1\n");
		}
	}
	if ( space_on_row )
	{
	}
	return 0;
}

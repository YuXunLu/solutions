#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int N = 500 + 2;
long long int mat[N][N] = {0};
int main()
{
	int n = 0;
	int s_i = -1, s_j = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 0)
			{
				s_i = i;
				s_j = j;
			}
		}
	}
	if ( n == 1 )
	{
		printf("5\n");
		return 0;
	}
	long long int r_s = 0, c_s = 0;
	for(int i = 0; i < n; i++)
	{
		r_s = r_s + mat[s_i][i];
		c_s = c_s + mat[i][s_j];
	}
	if ( c_s != r_s ) //space line and row check error
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		long long int tmp_res = 0; //store the "standard" res.
		long long int ans = 0;
		if ( s_i == 0 )
		{
			int t_i = 1;
			for (int i = 0; i < n; i++)
				tmp_res = tmp_res + mat[t_i][i];
		}
		else
		{
			int t_i = 0;
			for (int i = 0; i < n; i++)
				tmp_res = tmp_res + mat[t_i][i];
		}
		ans = tmp_res - r_s;
		if ( ans == 0 )
		{
			printf("-1\n");
			return 0;
		}
		mat[s_i][s_j] = ans;
		//legality checking.
		bool legal = true;
		long long int d1 = 0, d2 = 0;
		for (int i = 0; i < n; i++)
		{
			d1 = d1 + mat[i][i];
			d2 = d2 + mat[i][n - 1 - i];
		}
		if ( (d1 != d2) || (d1 != tmp_res) )
		{
			printf("-1\n");
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			long long int cs = 0;
			for(int j = 0; j < n; j++)
				cs = cs + mat[i][j];
			if ( (cs != tmp_res) )
			{
				printf("-1\n");
				return 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			long long int rs = 0;
			for(int j = 0; j < n; j++)
				rs = rs + mat[j][i];
			if ( (rs != tmp_res ) )
			{
				printf("-1\n");
				return 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

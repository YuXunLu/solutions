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
			int t_i = s_i + 1;
			for (int i = 0; i < n; i++)
			{
				tmp_res = tmp_res + mat[t_i][i];
			}
		}
		else
		{
			int t_i = s_i - 1;
			for (int i = 0; i < n; i++)
				tmp_res = tmp_res + mat[t_i][i];
		}
		ans = tmp_res - r_s;
//		printf("Tmp ans got: %lld\n", ans);
		mat[s_i][s_j] = ans;
		//legality checking.
		bool legal = true;
		long long int d1 = 0, d2 = 0;
		for (int i = 0; i < n; i++)
		{
			d1 = d1 + mat[i][i];
			d2 = d2 + mat[i][n - 1 - i];
		}
		if ( d1 != d2 )
		{
//			printf("Diagonal line check error\n");
			printf("-1\n");
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			long long int cs = 0, rs = 0;
			for(int j = 0; j < n; j++)
			{
				cs = cs + mat[i][j];
				rs = rs + mat[j][i];
			}
			if ( ( cs != rs) || (cs != tmp_res))
			{
//				printf("Legality on tmp_res check error: cs!=rs %d cs!=tmp_res %d\n", (cs != rs), (cs != tmp_res) );
				printf("-1\n");
				return 0;
			}
		}
//		printf("%lld\n", ans);
		cout << ans << endl;
	}
	return 0;
}

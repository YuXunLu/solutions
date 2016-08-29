#include <cstdio>
#include <cstring>
#include <stdlib.h>
const int N = 1e5 + 5;
const int M = 1e5 + 5;
int map[3][N] = {0};	//cost
int storage[N] = {0};
int s[N] = {0};
int main()
{
	int n = 0, m = 0, k = 0;
	scanf("%d %d %d", &n, &m, &k);
	if ( k == 0 )
	{
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		int u = 0, v = 0, l = 0;
		scanf("%d %d %d", &u, &v, &l);
		map[0][i] = u;
		map[1][i] = v;
		map[2][i] = l;
	}
//This part should be optimized
	int ind = 0;
	int min_cost = 1e9 + 5;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &s[i]);
		storage[s[i]] = 1;
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[0][j] == s[i])
			{
				if (storage[map[1][j]] != 1)
				{
					if (map[2][j] < min_cost)
					{
						min_cost = map[2][j];
					}
				}
			}
			if (map[1][j] == s[i])
			{
				if (storage[map[0][j]] != 1)
				{
					if (map[2][j] < min_cost)
					{
						min_cost = map[2][j];
					}
				}
			}
		}
	}
	if (min_cost == (1e9 + 5))
		printf("-1\n");
	else
		printf("%d\n", min_cost);
	return 0;
}

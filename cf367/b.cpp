#include <stdlib.h>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX_SHOP = 100000;
const int MAX_DAY = 100000;
int compare_int(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int get_available(int coin, int n_shops, int* prices)
{
	int result = 0;
	//binary search
	int l = 0, r = n_shops - 1, mid = ( l + r ) / 2;
	while( l <= r )
	{
		if ( prices[mid] < coin )
		{
			l = mid + 1;
		}
		else if ( coin == prices[mid] )
		{
			while ( coin == prices[mid] && mid < n_shops)
				mid++;
//				printf("Coin %d, Price %d, Mid %d\n", coin, prices[mid], mid);
			break;
		}
		else
		{
			r = mid - 1;
		}
		mid = ( l + r ) / 2;
	}
	result = mid;
	return result;
}
int main()
{
	int n_shops = 0;
	int n_days = 0;
	int prices[MAX_SHOP] = {0};
	int coins[MAX_DAY] = {0};
	scanf("%d", &n_shops);
	for(int i = 0; i < n_shops; i++)
	{
		scanf("%d", &prices[i]);
	}
	scanf("%d",&n_days);
	for(int i = 0; i < n_days; i++)
	{
		scanf("%d",&coins[i]);
		int num_available = get_available(coins[i], n_shops, prices);
		printf("%d\n", num_available);
	}
	return 0;
}

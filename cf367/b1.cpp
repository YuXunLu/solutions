#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;
const int MAX_BAR = 100000;
const int MAX_DAY = 100000;
const int MAX_PRICE = 1e5;
int drinks[MAX_BAR] = {0};
int main()
{
	int bar_num = 0;
	scanf("%d", &bar_num);
	for (int i = 0; i < bar_num; i++)
	{
		int price = 0;
		scanf("%d", &price);
		drinks[price] = drinks[price] + 1;
	}
	for (int i = 1; i <= MAX_PRICE; i++)
	{
		drinks[i]= drinks[i] + drinks[i-1];
	}
	int day = 0;
	scanf("%d", &day);
	for (int i = 0; i < day; i++)
	{
		int result = 0;
		int coin = 0;
		scanf("%d", &coin);
		if ( coin <= MAX_PRICE )
			printf("%d\n",drinks[coin]);
		else
			printf("%d\n", drinks[MAX_PRICE]);
	}
//	printf("%d\n",result);
	return 0;
}

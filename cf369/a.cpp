#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
const int N = 1000+5;
const int S = 5+2;
char config[N][S];
int main()
{
	int n = 0;
	scanf("%d", &n);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		scanf("%s", config[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if ( config[i][0] == 'O' && config[i][1] == 'O' )
		{
			flag = true;
			config[i][0] = '+';
			config[i][1] = '+';
			break;
		}
		if ( config[i][3] == 'O' && config[i][4] == 'O' )
		{
			flag = true;
			config[i][3] = '+';
			config[i][4] = '+';
			break;
		}
	}
	if (flag)
	{
		printf("YES\n");
		for(int i = 0; i < n; i++)
		{
			printf("%s\n", config[i]);
		}
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}

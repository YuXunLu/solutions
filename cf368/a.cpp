#include <cstdio>
#include <stdlib.h>
#include <cstring>
const int MAT_SIZE = 100;
const char* BNW = "#Black&White";
const char* CLR = "#Color";
bool isColor(char c)
{
	bool res = false;
	if ( c == 'M' || c == 'Y' || c == 'C')
		res = true;
	return res;
}
int main()
{
	int m_x = 0, m_y = 0;
	scanf("%d %d", &m_x, &m_y);
	int flag = 0; //default as white and black
	char c_a = 0, c_b = 0;
	for(int i = 0; i < m_x; i++)
	{
		for(int j = 0; j < m_y; j++)
		{
			scanf("%c %c\n", &c_a, &c_b);
			if (isColor(c_a) || isColor(c_b) )
			{
				flag = 1;
				break;
			}
		}
		if ( flag == 1 )
			break;
	}
	if (flag)
		printf("%s\n", CLR);
	else
		printf("%s\n", BNW);
	return 0;
}

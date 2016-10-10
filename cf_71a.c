//Something garbage
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int n = 0;
	char str_word[100] = {0};
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", str_word);
		int l = strlen(str_word);
		if (l > 10) //over 10 characters
		{
			printf("%c%d%c\n", str_word[0], l - 2, str_word[l - 1]);
		}
		else
		{
			printf("%s\n", str_word);
		}
	}
	return 0;
}

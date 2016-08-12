#include <cstdio>
#include <cstring>
bool is_a_vowel(char c)
{
	bool res = false;
	if ( c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I')
	{
		res = true;
	}
	return res;
}
int main()
{
	char s[100] = {0};
	while ( scanf("%s", s) )
	{
		char s_out[100] = {0};
		strcpy(s_out, s);
		for ( int i = 0; i < len(s); i ++)
		{
			
		}
	}
	return 0;
}

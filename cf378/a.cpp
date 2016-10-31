#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LEN = 100 + 5;
char s[MAX_LEN] = {0};
bool isVowel(char c)
{
    bool res = false;
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y' )
        res = true;
    return res;
}
int main()
{
    cin >> s;
    int min_dis = 0;
    int current_pos = -1;
    int target_pos = strlen(s);
    int i = 0;
    for(i = 0; i < strlen(s); i++)
    {
        int this_dis = 0;
        if (isVowel(s[i] ) ) 
        {
            this_dis = i - current_pos;
            if ( this_dis > min_dis )
                min_dis = this_dis;
            current_pos = i;
        }
    }
    if (current_pos != i)
    {
        int this_dis = strlen(s) - current_pos;
        if (this_dis > min_dis)
            min_dis = this_dis;
    }
    cout << min_dis << endl;
    return 0;
}

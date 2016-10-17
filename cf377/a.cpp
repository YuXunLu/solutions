#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    int k = 0, r = 0;
    cin >> k >> r;
    if ( k == r ) 
    { //the shovel's price is exactly r
        cout << "1" << endl;
        return 0;
    }
    for(int i = 1; i <= 10; i++)
    {
        if ( ( (k * i ) % 10 )== 0 ) //won't use the denomination
        {
            cout << i << endl;
            return 0;
        }
        if (( ( k * i - r ) % 10 ) == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
long long int min_three_num(long long int a, long long int b, long long int c)
{
    if ( a <= b )
        if ( a <= c )
            return a;
        else
            if ( b <= c )
                return b;
            else
                return c;
    else
        if ( b <= c )
            return b;
        else
            return c;
}
int main()
{
    long long int b = 0, d = 0, s = 0;
    cin >> b >> d >> s;
    long long int res = 0, p = 0;
    p = min_three_num(b,d,s); 
    long long int b1 = 0, d1 = 0, s1 = 0, b2 = 0, d2 = 0, s2 = 0;
    b1 = b - p;
    d1 = d - p;
    s1 = s - p;
    long long int q = 0;
    long long int t = 0;
    if ( ( b1 == 1 ) && ( d1 == 0 ) && ( s1 == 0 ) )
    {
        cout << 0 << endl;
        return 0;
    }
    if ( ( b1 == 0 ) && ( d1 == 1 ) && ( s1 == 0 ) )
    {
        cout << 0 << endl;
        return 0;
    }
    if ( ( b1 == 0 ) && ( d1 == 0 ) && ( s1 == 1 ) )
    {
        cout << 0 << endl;
        return 0;
    }
    if ( ( b1 > 0 ) && ( d1 == 0 ) && ( s1 == 0 ) )
    {
        cout << ( (b1-1) * 2 ) << endl;
        return 0;
    }
    if ( ( b1 == 0 ) && ( d1 > 0 ) && ( s1 == 0 ) )
    {
        cout << ( (d1-1) * 2 ) << endl;
        return 0;
    }
    if ( ( b1 == 0 ) && ( d1 == 0 ) && ( s1 > 0 ) )
    {
        cout << ( (s1-1) * 2 ) << endl;
        return 0;
    }
    if ( b1 == 0 )
    {
        //s and d
        q = min(s1,d1);
        res = (q - 1) >= 0 ? q - 1 : 0;
        t = ( abs(s1 - d1) - 1 );
        if ( t >= 0 )
            res = res + t * 2 + 1;
    }
    else
    {
        if ( d1 == 0 )
        {
            q = min(s1,b1);
            res = (q - 1) >= 0 ? q - 1 : 0;
            t =  (abs(s1 - b1) - 1 );
            if ( t >= 0 )
                res = res + t * 2 + 1;
        }
        else
        {
            q = min(b1,d1);
            res = (q - 1) >= 0 ? q - 1 : 0;
            t = abs(b1 - d1) - 1;
            if ( t >= 0 )
                res = res + t * 2 + 1;
        }
    } 
    cout << res << endl;
    return 0;
}

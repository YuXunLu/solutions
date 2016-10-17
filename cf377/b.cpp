#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 500 + 3;
const int K = 500 + 3;
const int NEG_INF = -1e9;
const int POS_INF = 1e9;
int days[N] = {0};
int main()
{
    int n = 0, k = 0;
    int sum = 0;
    int res = 0;
    cin >> n >> k;
//    cout << "n=" << n << "k=" << k <<endl;
    for (int i = 1; i <= n; i++)
        cin >> days[i];
    days[0] = k;
    days[n+1] = k;
    for (int i = 1; i <= n; i++)
    {
        int tmp = 0;
        int a = 0, b = 0;
        if ( (days[i-1] + days[i]) < k)
            tmp = k - ( days[i-1] + days[i] );
        sum = sum + tmp;
        days[i] = days[i] + tmp;
    }
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << days[i];
        if ( i != n )
            cout << " ";
        else
            cout << endl;
    }
    return 0;
}

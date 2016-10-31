#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAX_N = 1e5 + 10;
int soilder[MAX_N][2] = {0};
int main()
{
    int n = 0;
    int choose_col = 0;
    int max_score = 0;
    int sum_L = 0;
    int sum_R = 0;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> soilder[i][0] >> soilder[i][1];
        sum_L = sum_L + soilder[i][0];
        sum_R = sum_R + soilder[i][1];
    }

    max_score = abs(sum_L - sum_R);

    int init_L = sum_L;
    int init_R = sum_R;

    for(int i = 0; i < n; i++)
    {
        //if choose the i-th
        init_L = sum_L - soilder[i][0] + soilder[i][1];
        init_R = sum_R - soilder[i][1] + soilder[i][0];
        int ex_s = abs(init_L - init_R);
        if ( ex_s > max_score) 
        {
            max_score = ex_s;
            choose_col = i + 1;
        }
    }
    cout << choose_col << endl;
    return 0;
}

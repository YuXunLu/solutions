#include <iostream>
#include <vector>
#define DEBUG 1
using namespace std;
vector<int> ind;
vector<char> opr;
vector<int> current_queue;
vector<int> target_queue;
bool search(int t, int offset)
{
    bool result = false;
#ifdef DEBUG
    cout << "Offset: " << offset << endl;
    vector<int>::iterator tk = current_queue.begin() + offset;
    cout << "assertion: " << (tk == current_queue.begin() ) << endl;
#endif
    for( vector<int>::iterator it = current_queue.begin() + offset; it < current_queue.end();)
    {
        if ( *it == t)
        {
            result = true;
            return result;
        }
#ifdef DEBUG
        cout << "assertion (it eql begin): " << (it == current_queue.begin() ) << endl;
#endif
        if ( it == current_queue.begin() )
        {
            //Only right is allowed.
            if ( ( *it > *(it+1) ) && ( (it + 1) < current_queue.end() ) )//the left side is huge
            {
                cout << "Step in beginning" << endl;
                int tmp = *it;
                ind.push_back(1 + it - current_queue.begin() );
                current_queue.erase(it+1); //eat
                *it = *it + tmp; //get fat
                opr.push_back('R');
#ifdef DEBUG
                cout << "Monster " << 1 + it - current_queue.begin() << " Eats Right Side" << endl;
                cout << "Current ind: " << it - current_queue.begin() << " Total Length " << current_queue.size() << endl;
#endif
            }
            else
            {
                it = it + 1;
            }
        }
        else
        {
            if ( (it + 1 ) == current_queue.end() )
            {
                //Only left is allowed.
                if ( ( *it > *(it-1) ) && ( (it-1) >= current_queue.begin() ) ) //eat left side
                {
                    int tmp = *(it-1);
                    ind.push_back(1 + it - current_queue.begin() );
                    it = current_queue.erase(it-1);
                    *it = *it + tmp;
                    opr.push_back('L');
#ifdef DEBUG
                    cout << "Monster " << 1 + it - current_queue.begin() << " Eats Left Side" << endl;
                    cout << "Current ind: " << it - current_queue.begin() << " Total Length " << current_queue.size() << endl;
#endif
                }
                else
                {
                    result = false;
                    return result;
                }
            }
            else
            {
                //Both side is allowed.
                //left side first
                if ( ( *it > *(it - 1 )  ) && ( (it - 1) >= current_queue.begin() ) ) //left side
                {
                    int tmp = *(it-1);
                    ind.push_back(1 + it - current_queue.begin());
                    it = current_queue.erase(it-1);
                    *it = *it + tmp;
                    opr.push_back('L');
#ifdef DEBUG
                    cout << "Monster " << 1 + it - current_queue.begin() << " Eats Left Side" << endl;
                    cout << "Current ind: " << it - current_queue.begin() << " Total Length " << current_queue.size() << endl;
#endif
                }
                else
                {
                    if ( ( *it > *(it + 1 ) ) && ((it + 1) < current_queue.end())  )//right side
                    {
                        int tmp = *(it+1);
                        ind.push_back(1 + it - current_queue.begin());
                        current_queue.erase(it+1);
                        *it = *it + tmp;
                        opr.push_back('R');
#ifdef DEBUG
                        cout << "Monster " << 1 + it - current_queue.begin() << " Eats Right Side" << endl;
                        cout << "Current ind: " << it - current_queue.begin() << " Total Length " << current_queue.size() << endl;
#endif
                    }
                    else
                    {
                        it++;
                    }
                }
            }
        }
    }
}
int main()
{
    int n = 0;
    int k = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        current_queue.push_back(tmp);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int tmp = 0;
        cin >> tmp;
        target_queue.push_back(tmp);
    }
    for (vector<int>::iterator it = target_queue.begin(); it != target_queue.end(); it++)
    {
        if ( false == search(*it, it - target_queue.begin()) )
        {
            cout << "NO" << endl;
            return 0;
        }
    }
//    if ( target_queue.size() != current_queue.size() )
//    {
//        cout << "NO" << endl;
//        return 0;
//    }
//    vector<int>::iterator cur_ind = current_queue.begin();
//    vector<int>::iterator tar_ind = target_queue.begin();
//    for(; cur_ind != current_queue.end(); cur_ind++)
//    {
//        if (*cur_ind != *tar_ind)
//        {
//            cout << "NO" << endl;
//            return 0;
//        }
//        tar_ind++;
//    }
    cout << "YES" << endl;
    vector<char>::iterator opr_it = opr.begin();
    vector<int>::iterator ind_it = ind.begin();
    for (; opr_it != opr.end(); opr_it++, ind_it++)
    {
        cout << *ind_it << " " << *opr_it << endl;
    }
    return 0;
}

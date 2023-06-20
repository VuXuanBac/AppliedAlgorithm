
#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<unsigned long long>> _count;

int main()
{
    do {
        cin >> n;
        if(n <= 0)
            break;
        _count.clear();
        _count.push_back(vector<unsigned long long>()); ///0
        _count.push_back(vector<unsigned long long>(1)); ///1
        _count[1][1] = 1;
        _count.push_back(vector<unsigned long long>(2)); ///1
        _count[2][1] = 2;
        _count.push_back(vector<unsigned long long>(2)); ///1
        _count[3][1] = 3;
        for(int x = 4; x <= n; ++x)
        {
            _count.push_back(vector<unsigned long long>(x/2 + 1));

            _count[x][x/2] = 2;
            for(int t = x/2-1; t > 0; --t)
            {
                _count[x][t] = ((t > (x-t)/2) ? 1 : _count[x-t][t]) + _count[x][t+1];
            }
        }
        cout << _count[n][1] << "\n";
    } while(n > 0);
    return 0;
}

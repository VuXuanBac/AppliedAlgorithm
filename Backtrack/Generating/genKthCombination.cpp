
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10001
#define max_val(x) n-m+x
int n, m, k;
int temp[MAX_N];
bool Try(int index, int min_val)
{
    if(index == m)
    {
        if(k <= n - min_val + 1){
            temp[index] = min_val + k - 1;
            return true;
        }
        else
            k -= (n - min_val + 1);
            return false;
    }
    else{
        int _k = k;
        for(int i = min_val; i <= max_val(index); ++i){
            if(Try(index + 1, i + 1)){
                temp[index] = i;
                return true;
            }
        }

    }
    return false;
}
int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m; ++i)
        temp[i] = i;
    if(Try(1, 1)){
        for(int i = 1; i <= m; ++i)
            cout << temp[i] << " ";
        cout << "\n";
    }
    else
        cout << "-1\n";
    return 0;
}


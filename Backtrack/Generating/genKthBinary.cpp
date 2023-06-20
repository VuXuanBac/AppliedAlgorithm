#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10001
int n, contiguous, k;
int cur[MAX_N];
void print()
{
    for(int i = 1; i <= n; ++i)
        cout << cur[i] << " ";
    cout << "\n";
}
bool genNext()
{
    int i = n;
    while(i > 0)
    {
        if(*(cur + i) == 0)
        {
            *(cur + i) = 1;
            for(int j = 1; j <= n-i; ++j)
                cur[i + j] = j % contiguous ? 0 : 1;
            return true;
        }
        i--;
    }
    return false;
}
int main()
{
    cin >> n >> k >> contiguous;
    for(int i = 1; i <= n; ++i)
        cur[i] = i % contiguous ? 0 : 1;
    int i = 1;
    for(; i < k; ++i){
        if(!genNext())
            //print();
        //else
            break;
    }
    if(i < k)
        cout << "-1\n";
    else
        print();
    return 0;
}


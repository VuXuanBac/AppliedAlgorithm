#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> grow(N);
    for(int& i : grow){
        cin >> i;
    }
    long long res = 0;
    sort(grow.begin(), grow.end(), greater<int>());
    for(int i = 0; i < N; ++i){
        res = max(res, (long long)i + 1 + grow[i]);
    }
    cout << res + 1;
    return 0;
}
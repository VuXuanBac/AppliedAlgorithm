#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, p;
    cin >> N;
    const auto cmp = [](const int& a, const int& b) -> bool { return a > b; };
    map<int, int, decltype(cmp)> grow(cmp);

    for(int i = 0; i < N; ++i){
        cin >> p;
        grow[p]++;
    }
    long long res = 0;
    long long c = 0;
    for(const auto& i : grow){
        c += i.second;
        res = max(res, c + i.first);
    }
    cout << res + 1;
    return 0;
}
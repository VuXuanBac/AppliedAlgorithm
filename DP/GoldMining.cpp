#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N, L1, L2;
int gold[MAX_N];
vector<int> sum(MAX_N);
int dp(int pos)
{
    if (pos >= N - L1)
        return gold[pos];
    if (pos >= 0 && sum[pos] != 0)
        return sum[pos];
    int result = 0;
    int max_i = min(pos + L2, N - 1);
    for (int i = pos + L1; i <= max_i; ++i)
    {
        result = max(result, dp(i));
    }
    if (pos >= 0)
    {
        sum[pos] = result + gold[pos];
        return sum[pos];
    }
    else
        return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L1 >> L2;
    for (int i = 0; i < N; ++i)
        cin >> gold[i];
    cout << dp(-L1) << "\n";
    return 0;
}

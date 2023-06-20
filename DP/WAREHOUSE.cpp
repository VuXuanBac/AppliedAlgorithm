/// Cho dãy { (a[i], t[i]), ... }
/// Với T cho trước, xác định một tập con {x[k]} mà 
/// + sum(t[k]) <= T
/// + Hai phần tử liên tiếp cách nhau không quá D.
/// + sum(a[k]) là lớn nhất.
/// N <= 1000. T <= 100; D <= 10
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000
#define MAX_T 100
int N, T, D;
int goods[MAX_N];
int ptime[MAX_N];
vector<vector<int> > sum;
int dc(int start, int t)
{
    if(sum[start][t] > 0)
        return sum[start][t];
    if(t == ptime[start])
        return goods[start];
    else if(t < ptime[start])
        return 0;
    int best = 0;
    t -= ptime[start];
 
    int max_i = min(start + D, N - 1);
    for(int i = start + 1; i <= max_i; ++i){
        if(t >= ptime[i]){
            best = max(best, dc(i, t));
        }
    }
    t += ptime[start];
    sum[start][t] = best + goods[start];
    return sum[start][t];
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N >> T >> D;
    for(int i = 0; i < N; ++i)
        cin >> goods[i];
    for(int i = 0; i < N; ++i)
        cin >> ptime[i];
    for(int i = 0; i < N; ++i)
        sum.push_back(vector<int>(T + 1));
    int best = 0;
    for(int i = 0; i < N; ++i){
        best = max(best, dc(i, T));
    }
    cout << best << "\n";
    return 0;
}
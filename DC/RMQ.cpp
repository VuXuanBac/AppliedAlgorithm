/// Cho dãy a[1..N]
/// Kí hiệu rmq(i, j) = phần tử nhỏ nhất trong đoạn a[i..j]
/// Với một tập M cặp (i, j) cho trước, tìm sum(rmq(i, j));
/// DC: T(N) = 2*T(N/2) + O(1) -> O(N)
/// -> O(M*N)
#include <bits/stdc++.h>
using namespace std;
int N, M, v, u;
vector<int> a;
int rmq(int i, int j){
    if(j == i)
        return a[i];
    int m = (i + j) >> 1;
    int l = rmq(i, m);
    int r = rmq(m + 1, j);
    return min(l, r);
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> v;
        a.push_back(v);
    }
    cin >> M;
    long long sum = 0;
    for(int i = 0; i < M; ++i){
        cin >> u >> v;
        sum += rmq(u, v);
        //cout << rmq(u, v) << "\n";
    }
    cout << sum << "\n";
    return 0;
}

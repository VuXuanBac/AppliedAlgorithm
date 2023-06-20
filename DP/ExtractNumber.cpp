/// Cho số nguyên dương M và dãy nguyên dương a[1..N]
/// Tìm số cách phân tích M thành tổng tuyến tính của tất cả các phần tử trong dãy a[1..N]
/// M = sum(x[i]*a[i]) (mọi i = 1,N), x[i] nguyên dương.
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100
#define MAX_M 500
#define MOD 1000000007
int N, M;
int a[MAX_N];
/// _count[N - 1][M] = Số cách phân tích M thành tổng tuyến tính của N số đầu 
/// _count[i][v] = sum(_count[i - 1][v - x*a[i]]) với x = [1,t]. 
/// với t là giá trị lớn nhất thỏa v > t*a[i].
vector<vector<int> > _count;
/// sum[i] = sum(a[0..i]); // Tổng của i + 1 phần tử đầu.
vector<int> sum;
// Số cách phân tích value thành tổng tuyến tính của k + 1 phần tử đầu
int dc(int k, int value)
{
    int c = 0;
    if(k == 0){
        c = (value % a[k] ? 0 : 1);
    }
    else{
        int p = k - 1;
        for(int v = value - a[k]; v >= sum[p]; v -= a[k]){
            if(v == sum[p])
                ++c;
            else
                c += (_count[p][v] >= 0 ? _count[p][v] : dc(p, v));
            if(c >= MOD)
                c -= MOD;
        }
    }
    _count[k][value] = c;
    return c;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a, a + N);
    sum.push_back(a[0]);
    _count.push_back(vector<int>(M + 1, -1));
    
    for(int i = 1; i < N; ++i){
        sum.push_back(sum[i - 1] + a[i]);
        _count.push_back(vector<int>(M + 1, -1));
    }
    cout << (M < sum[N - 1] ? 0 : dc(N - 1, M)) << "\n";
    return 0;
}

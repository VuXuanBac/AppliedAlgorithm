/// Cho dãy a[1..N]
/// Kí hiệu rmq(i, j) = phần tử nhỏ nhất trong đoạn a[i..j]
/// Với một tập M cặp (i, j) cho trước, tìm sum(rmq(i, j));
/// DP: Lưu chỉ số của phần tử nhỏ nhất trong đoạn [i, i + 2^k - 1]
/// -> O(N*logN) cho xây dựng bảng và O(M) cho truy vấn
#include <bits/stdc++.h>
using namespace std;
int N, M, u, v, k;
vector<int> a;
/// min_index[j][i] = chỉ số phần tử nhỏ nhất trong đoạn [i, i + 2^j - 1]
///                         (dãy bắt đầu tử i và có 2^j phần tử).
/// min_index[0][j] = i với mọi i.
/// min_index[j][i] = so sánh giữa {a[min_index[j-1][i]], 
///                                 a[min_index[j-1][i + 2^(j-1)]]}
vector<vector<int> > min_index;
int rmq(int i, int j){
    k = (int)log2(j - i + 1); //chỉ số thứ nhất của min_index
    // so sánh hai đoạn [i, x] và [y, j] với 
    // x = i + 2^k - 1
    // y = j - 2^k + 1
    u = min_index[k][i];
    v = min_index[k][j - (1 << k) + 1];
    return a[u] < a[v] ? a[u] : a[v];
}
void init()
{
    int log2_N = (int)log2(N);
    for(int i = 0; i <= log2_N; ++i){
        min_index.push_back(vector<int>(N));
    }
    for(int i = 0; i < N; ++i){
        min_index[0][i] = i;
    }
    for(int i = 1; i <= log2_N; ++i){
        for(int j = N - (1 << i) ; j >= 0; --j){
            u = min_index[i-1][j];
            v = min_index[i-1][j + (1 << (i-1))];
            min_index[i][j] = a[u] < a[v] ? u : v;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; ++i)
    {
        cin >> v;
        a.push_back(v);
    }
    init();
    cin >> M;
    long long sum = 0;
    for(int i = 0; i < M; ++i){
        cin >> u >> v;
        sum += rmq(u, v);
    }
    cout << sum << "\n";
    return 0;
}

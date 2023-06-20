/// Cho hai dãy value[1..N] và step[1..N]
/// Từ một phần tử i của dãy [1..N] ta có thể chọn phần tử tiếp theo j
/// thỏa mãn i + 1 <= j <= i + step[i]
/// Chỉ được chọn một số lượng phần tử giới hạn (k)
/// Tìm cách chọn mà:
/// + Phần tử đầu tiên là 1 và phần tử cuối cùng là N.
/// + sum(value[i]) là lớn nhất.
/// ------------------------
/// -> O(k*(n^2))
/// k <= 100; n <= 3000
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 3000
int N, K;
int value[MAX_N];
int step[MAX_N];
/// sum_value[node][stop] = value
/// + Tổng <value> từ phần tử <node> tới phần tử cuối cùng 
/// + Mà số lượng phần tử bằng <stop>
vector<vector<int> > sum_value;
/// max_step[node] và min_step[node]:
/// Số phần tử lớn nhất và số phần tử nhỏ nhất mà 
/// từ phần tử vị trí node có thể đến phần tử cuối cùng.
int max_step[MAX_N];
int min_step[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; ++i)
        cin >> value[i];
    for(int i = 0; i < N; ++i)
        cin >> step[i];
    for(int i = 0; i < N; ++i)
        sum_value.push_back(vector<int>(K + 2, 0));
    max_step[N - 1] = 0;
    min_step[N - 1] = 0;
    sum_value[N - 1][0] = value[N - 1];
    // Duyệt từng phần tử từ cuối (N).
    for(int i = N - 2; i >= 0; --i){
        int en = min(N - 1, i + step[i]);
        max_step[i] = min(max_step[i + 1] + 1, K);
        min_step[i] = min_step[i + 1] + 1;
        // Duyệt theo vị trí các phần tử tiếp theo có thể đến từ phần tử hiện tại
        for(int nxt = i + 1; nxt <= en; ++nxt){
            // Duyệt theo số lượng step (tối đa K lần)
            for(int st = max_step[nxt] + 1; st > min_step[nxt]; --st){
                sum_value[i][st] = max(sum_value[i][st], 
                        value[i] + sum_value[nxt][st - 1]);
            }
            min_step[i] = min(min_step[i], min_step[nxt] + 1);
        }
    }
    int best = 0;
    // Duyệt theo số lượng phần tử được chọn từ vị trí 1 để đến đích.
    // Thông thường, càng chọn nhiều phần tử thì tổng value càng lớn.
    for(int i = K; i > 0; --i)
        best = max(best, sum_value[0][i]);
    cout << (best == 0 ? -1 : best) << "\n";
    return 0;
}
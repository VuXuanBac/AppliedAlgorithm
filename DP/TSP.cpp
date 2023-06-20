/// Cho đồ thị có hướng và có trọng số N đỉnh
/// Tìm chu trình đi qua N đỉnh, mỗi đỉnh đúng một lần mà chi phí là nhỏ nhất
/// DP: Bitmask
#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> cost;
// path[i][x]: chi phí nhỏ nhất.
// - i: đỉnh đang xét.
// - x: tập các đỉnh đã thăm. (bitmask)
// path[i][2^N - 1] = cost[i][0] : Chi phí đi tiếp từ i khi mà đã đi qua mọi đỉnh là chi phí quay lại đỉnh xuất phát.
vector<vector<int>> path;
int dp(int st, int state)
{
    if (state == (1 << N) - 1)
        return cost[st][0] > 0 ? cost[st][0] : INT_MAX;
    if (path[st][state] > 0)
        return path[st][state];
    int best_cost = INT_MAX;
    for (int i = 0; i < N; ++i)
    {
        if (state & (1 << i))
            continue;
        if (cost[st][i] > 0){
            int t = dp(i, state | (1 << i));
            if(t != INT_MAX)
                best_cost = min(best_cost, cost[st][i] + t);
        }
    }
    path[st][state] = best_cost;
    return best_cost;
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cost.push_back(vector<int>(N));
        path.push_back(vector<int>(1 << N));
    }
    int x, y, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y >> c;
        cost[x - 1][y - 1] = c;
    }
    cout << dp(0, 1) << "\n";

    return 0;
}
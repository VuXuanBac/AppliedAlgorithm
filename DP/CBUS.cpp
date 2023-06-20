/// Cho đồ thị có hướng (2*N + 1) đỉnh (0, 1, 2,..., 2N) có trọng số
/// Giữa hai cặp đỉnh u, v bất kì luôn có hai cung u->v và v->u
/// Tìm một chiến lược di chuyển trên đồ thị:
/// + Xuất phát từ đỉnh 0, mỗi đỉnh qua đúng một lần, cuối cùng phải quay trở lại điểm 0 (TSP)
/// + Một đỉnh v > N chỉ có thể thăm khi đỉnh (v-N) đã thăm.
/// + Mỗi lần thăm một đỉnh thuộc đoạn 1, N sẽ làm tăng tải lên 1, mỗi lần thăm một đỉnh
///     v > N thì tải giảm 1. Tại mọi thời điểm, yêu cầu tải không vượt quá K.
/// + Chi phí nhỏ nhất.
/// ---------------
/// Duyệt toàn bộ + Nhánh cận: O( (2N)! )
/// Quy hoạch động (Bitmask): O( (2N) * 2^(2N) )
#include <bits/stdc++.h>
using namespace std;

int N, _2N, max_load;
vector<vector<int> > dist;
/// cost[v][state]: Chi phí đi từ đỉnh v mà các đỉnh đã đi qua được thể hiện trong state (bitmask)
vector<vector<int> > cost;
int dp(int st, int state)
{
    if(state == (1 << _2N) - 2)
        return dist[st][0];
    if(cost[st][state] > 0) return cost[st][state];
    int load = __builtin_popcount(state) - (__builtin_popcount(state >> (N + 1)) << 1);
    int best = INT_MAX;
    if(load > 0){
        for(int i = N+1; i < _2N; ++i)
        {
            if(state & (1 << i) || !(state & (1 << (i-N))))
                continue;
            best = min(best, dist[st][i] + dp(i, state | (1 << i)));
        }
    }
    if(load < max_load){
        for(int i = 1; i <= N; ++i)
        {
            if(state & (1 << i))
                continue;
            best = min(best, dist[st][i] + dp(i, state | (1 << i)));
        }
    }
    cost[st][state] = best;
    return best;
}
int main()
{
    cin >> N >> max_load;
    _2N = (N << 1) + 1;
    for (int r = 0; r < _2N; ++r)
    {
        dist.push_back(vector<int>(_2N, 0));
        for (int c = 0; c < _2N; ++c)
            cin >> dist[r][c];
    }
    for(int i = 0; i < _2N; ++i){
        cost.push_back(vector<int>(1 << _2N, 0));
    }
    cout << dp(0, 0) << "\n";
    return 0;
}

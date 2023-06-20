/// Tìm cây khung nhỏ nhất (Minimum Spanning Tree) của đồ thị vô hướng có trọng số và
/// LIÊN THÔNG.
/// MST: Cây chứa mọi đỉnh của đồ thị và tổng trọng số trên các cạnh là nhỏ nhất.
/// Prim's Algorithm: Bắt đầu từ đỉnh bất kì, thêm dần từng đỉnh 

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int V, E;
vector<vector<pii> > edges;
///Sum weights on a MST find with Prim's Algorithm start at st

long long prim(int st)
{
    long long ret = 0;
    auto node_cmp = [](const pii& a, const pii& b) -> bool
    {
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(node_cmp) > 
            vpqueue(node_cmp); // using lambda must declare Constructor like this
            
    vector<int> dist(V + 1, INT_MAX); // dist[u]: minimum distance from u to one vertext of current MST
    vpqueue.push({st, 0});
    dist[st] = 0;
    int v, v_dist; /// PQueue top 

    while (!vpqueue.empty()) {
        v = vpqueue.top().first;
        v_dist = vpqueue.top().second;
        vpqueue.pop();

        if (v_dist != dist[v]) // Already in the MST
            continue;

        ret += dist[v]; 
        dist[v] = INT_MIN; 

        for (auto &e : edges[v]) {
            int u = e.first; 
            int w = e.second;
            if (dist[u] > w) {
                dist[u] = w;
                vpqueue.push({u, w});
            }
        }
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    int u, v, w;
    edges.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    cout << prim(1);
    return 0;
}

/// Cho cây vô hướng có trọng số.
/// Tìm đường đi đơn có tổng trọng số lớn nhất.
/// -> 2 lần Dijkstra
/// Tìm đường đi ngắn nhất trên đồ thị có hướng
/// Dijkstra: BFS + Priority-queue
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int V;
vector<vector<pii> > edges;
/// Tìm đỉnh xa đỉnh st nhất, trả về độ dài đường đi
int find_longest(int st, int& en)
{
    auto node_cmp = [](const pii& a, const pii& b) -> bool
    {
        return a.second < b.second; /// Đảo ngược chiều chọn
    };
    priority_queue<pii, vector<pii>, decltype(node_cmp) > 
            vpqueue(node_cmp); // using lambda must declare Constructor like this
    vector<int> dist(V + 1, 0); // dist from <st> node to cur node
    /// Check if the node has been get from the top of PQueue.
    vector<bool> visited(V + 1, false);
    vpqueue.push({st, 0});
    dist[st] = 0;
    int v, v_dist, longest = 0; /// PQueue top 
    while (!vpqueue.empty())
    {
        v = vpqueue.top().first;
        v_dist = vpqueue.top().second;
        vpqueue.pop();
        if(visited[v]) 
            continue;
        visited[v] = true;
        if(v_dist > longest){
            longest = v_dist;
            en = v;
        }
        for (const auto& nv : edges[v])
        {
            int d = v_dist + nv.second;
            /// if cur dist is better, push this node one more times to PQueue
            /// So PQueue can contains many 'version' of a node
            /// Top 'version' has maximum distance from <st> node.
            if (d > dist[nv.first])
            {
                dist[nv.first] = d;
                vpqueue.push({nv.first, d});
            }
        }
    }
    return longest;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V;
    int u, v, w;
    edges.resize(V + 1);
    for (int i = 1; i < V; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    find_longest(1, v);
    cout << find_longest(v, u);
    return 0;
}

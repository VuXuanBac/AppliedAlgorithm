/// Tìm cách xếp lịch có điều kiện tiên quyết
/// Dijkstra: BFS + Priority-queue
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int V, E;
vector<vector<int> > edges;
vector<int> cost;
vector<int> dist;
vector<bool> visited;
auto node_cmp = [](const pii& a, const pii& b) -> bool
{
    return a.second > b.second;
};
priority_queue<pii, vector<pii>, decltype(node_cmp) > 
    vpqueue(node_cmp); // using lambda must declare Constructor like this
int dijkstra(int st)
{
    vpqueue.push({st, 0});
    dist[st] = 0;
    int v, v_dist; /// PQueue top
    while (!vpqueue.empty())
    {
        v = vpqueue.top().first;
        v_dist = vpqueue.top().second;
        vpqueue.pop();
        if(visited[v]) 
            continue;
        visited[v] = true;

        if(v == en){
            return v_dist;
        }
        for (const auto& nv : edges[v])
        {
            int d = v_dist + cost[v];
            /// if cur dist is better, push this node one more time to PQueue
            /// So PQueue can contains many 'version' of a node
            /// Top 'version' has minimum distance from <st> node.
            if (d < dist[nv])
            {
                dist[nv] = d;
                vpqueue.push({nv, d});
            }
        }
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    int u, v, w;
    edges.resize(V + 1);
    cost.resize(V + 1);
    visited.resize(V + 1, false);
    dist.resize(V + 1, INT_MAX);
    cost.push_back(0);
    for(int i = 1; i <= V; ++i)
        cin >> cost[i];
    int start = 0;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back(v);
        start |= (1 << v);
    }
    start = ~start;
    cout << find_path(u, v);
    return 0;
}

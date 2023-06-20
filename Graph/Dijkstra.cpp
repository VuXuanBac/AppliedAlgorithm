/// Tìm đường đi ngắn nhất trên đồ thị có hướng
/// Dijkstra: BFS + Priority-queue
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int V, E;
vector<vector<pii> > edges;

int find_path(int st, int en)
{
    auto node_cmp = [](const pii& a, const pii& b) -> bool
    {
        return a.second > b.second;
    };
    priority_queue<pii, vector<pii>, decltype(node_cmp) > 
            vpqueue(node_cmp); // using lambda must declare Constructor like this
    vector<int> dist(V + 1, INT_MAX); // dist from <st> node to cur node
    /// Check if the node has been get from the top of PQueue.
    vector<bool> visited(V + 1, false);
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
            int d = v_dist + nv.second;
            /// if cur dist is better, push this node one more time to PQueue
            /// So PQueue can contains many 'version' of a node
            /// Top 'version' has minimum distance from <st> node.
            if (d < dist[nv.first])
            {
                dist[nv.first] = d;
                vpqueue.push({nv.first, d});
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
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    cin >> u >> v;
    cout << find_path(u, v);
    return 0;
}

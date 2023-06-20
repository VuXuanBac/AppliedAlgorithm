/// Tìm cây khung nhỏ nhất trong đồ thị con K cạnh của đồ thị vô hướng có trọng số.
/// Brute-Force: Sinh từng đồ thị con với K+1 đỉnh và Prim trên đồ thị con.
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int V, E, K, mst = INT_MAX;
vector<vector<pii> > edges;
int visited; /// Tập các đỉnh đã thăm.
int c; /// Số đỉnh hiện tại trong đồ thị con. Dùng trong Try()
    auto node_cmp = [](const pii &a, const pii &b) -> bool
    {
        return a.second > b.second;
    };
/// Prim trên tập con K+1 đỉnh của đồ thị.
/// vertices: Bitmask xác định các đỉnh trong đồ thị con
int prim(int st, int vertices)
{
    int ret = 0;
    priority_queue<pii, vector<pii>, decltype(node_cmp)>
        vpqueue(node_cmp); // using lambda must declare Constructor like this

    vector<int> dist(V + 1, INT_MAX); // dist[u]: minimum distance from u to one vertext of current MST
    vpqueue.push({st, 0});
    dist[st] = 0;
    int v, v_dist; /// PQueue top

    while (!vpqueue.empty())
    {
        v = vpqueue.top().first;
        v_dist = vpqueue.top().second;
        vpqueue.pop();

        if (v_dist != dist[v]) // Already in the MST
            continue;

        ret += dist[v];
        //dist[v] = INT_MIN;
        vertices &= ~(1 << v);

        for (const auto &e : edges[v])
        {
            int u = e.first;
            if (vertices & (1 << u))
            {
                int w = e.second;
                if (dist[u] > w)
                {
                    dist[u] = w;
                    vpqueue.push({u, w});
                }
            }
        }
    }
    // In case the subgraph does not connected.
    if(vertices != 0 || ret == 0)
        return INT_MAX;
    return ret;
}
void Try(int u)
{
    for(int v = u + 1; v <= V; ++v){
        visited |= (1 << v);
        c++;
        if(c == K + 1){
            mst = min(prim(v, visited), mst);
        }
        else if(c + V - v > K){
            Try(v);
        }
        c--;
        visited &= ~(1 << v);
    }
}
int main()
{
    cin >> V >> E >> K;
    int u, v, w;
    edges.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    if(K < V)
        Try(0);
    cout << (mst == INT_MAX ? -1 : mst);
    return 0;
}
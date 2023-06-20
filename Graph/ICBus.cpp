#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int V, E, res = INT_MAX;
vector<int> cost;
vector<int> far;
vector<vector<int> > directs;
vector<vector<int> > edges;

void BFS(int st)
{
    vector<int> d(V + 1, -1);
    queue<int> q;
    q.push(st);
    d[st] = 0;
    int v;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        if (d[v] < far[st])
        {
            for (const auto &u : directs[v])
            {
                if (d[u] < 0)
                {
                    d[u] = d[v] + 1;
                    q.push(u);
                    edges[st].push_back(u);
                }
            }
        }
    }
}
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
        if(edges[v].empty())
            BFS(v);
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
    cin >> V >> E;
    int c, f;
    cost.push_back(0);
    far.push_back(0);
    for (int i = 0; i < V; ++i)
    {
        cin >> c >> f;
        cost.push_back(c);
        far.push_back(f);
    }
    directs.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> c >> f;
        directs[c].push_back(f);
        directs[f].push_back(c);
    }
    edges.resize(V + 1);
    cout << find_path(1, V);
    return 0;
}
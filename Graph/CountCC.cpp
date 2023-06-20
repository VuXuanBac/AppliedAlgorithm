/// Đếm số thành phần liên thông của đồ thị vô hướng
/// DFS -> O(|V| + |E|)
#include <bits/stdc++.h>
using namespace std;
int V, E, u, v;
vector<vector<int> > edges;

int count_CC()
{
    int CC_count = 0;
    stack<int> vstack;
    vector<bool> visited(V + 1);
    for (int st = 1; st <= V; ++st)
    {
        if(visited[st]) continue;
        CC_count++;
        vstack.push(st);
        visited[st] = true;
        int v;
        while (!vstack.empty())
        {
            v = vstack.top();
            vstack.pop();
            for (int nv : edges[v])
            {
                if (!visited[nv])
                {
                    visited[nv] = true;
                    vstack.push(nv);
                }
            }
        }
    }
    return CC_count;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin >> V >> E;
    edges.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << count_CC();
    return 0;
}
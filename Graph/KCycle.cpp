/// Đếm số chu trình cơ bản K cạnh trong đồ thị vô hướng.
#include <bits/stdc++.h>
using namespace std;
int V, E, K, res;
vector<vector<int> > edges;
int mark;
int start;
int c;
void DFS(int v)
{
    mark |= (1 << v);
    c++;
    if(c == K)
    {
        if(find(edges[v].begin(), edges[v].end(), start) != edges[v].end()){
            res++;
        }
    }
    for(const auto& i : edges[v])
    {
        if(mark & (1 << i))
            continue;
        DFS(i);
    }
    c--;
    mark &= ~(1 << v);
}
int countKCycle()
{
    for(int i = 1; i <= V; ++i)
    {
        start = i;
        DFS(i);
    }
    return res / K / 2; // hai hướng và lặp lại mỗi đỉnh
}
int main()
{
    cin >> V >> E >> K;
    int u, v;
    edges.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << countKCycle();
    return 0;
}
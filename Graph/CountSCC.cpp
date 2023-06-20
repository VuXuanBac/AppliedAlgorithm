/// Đếm số thành phần liên thông mạnh của đồ thị có hướng
/// DFS -> O(|V| + |E|)
#include <bits/stdc++.h>
using namespace std;
int V, E, u, v, scc;
vector<vector<int> > edges;
vector<int> num;
vector<int> low;
vector<bool> onStack;
stack<int> S;
int t = 0;
void DFS(int u)
{
    S.push(u);
    onStack[u] = true;
    num[u] = low[u] = ++t;
    for(const int& v : edges[u]){
        if(num[v] == 0){ // v là hậu duệ
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else if(onStack[v]){ // v là tổ tiên
            low[u] = min(low[u], num[v]);
        }
    }
    if(num[u] == low[u]){
        scc++;
        int v;
        do{
            v = S.top();
            S.pop();
            onStack[v] = false;
        }while(v != u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    edges.resize(V + 1);
    num.resize(V + 1);
    low.resize(V + 1);
    onStack.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for(int i = 1; i <= V; ++i){
        if(num[i] == 0)
            DFS(i);
    }
    cout << scc << "\n";
    return 0;
}
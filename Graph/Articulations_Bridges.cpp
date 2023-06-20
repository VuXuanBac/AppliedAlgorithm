/// Tìm tất cả khớp (Articulation) và cầu (Bridges) trên đồ thị vô hướng
/// Khớp là một đỉnh mà nếu xóa nó thì số thành phần liên thông tăng lên.
/// Cầu là một cạnh mà nếu xóa nó thì số thành phần liên thông tăng lên.
/// DFS + Tarjan: O (|V| + |E|)
#include <bits/stdc++.h>
using namespace std;
int V, E, bridges, articulations;
vector<vector<int> > edges;
vector<int> num;
vector<int> low;
vector<bool> isarticulation;
int t = 0;
void DFS(int u, int pre)
{
    num[u] = low[u] = ++t;
    int child = 0;
    for(const int& v : edges[u]){
        if(num[v] == 0){ // v là hậu duệ
            DFS(v, u);
            if(num[u] < low[v]){
                bridges++; /// (u, v) là một cầu
            }
            if(u != pre && !isarticulation[u] && num[u] <= low[v]){ // u không phải là gốc
                articulations++; /// u là một khớp
                isarticulation[u] = true;
            }
            low[u] = min(low[u], low[v]);
            child++;
        }
        else if(v != pre){ // v là tổ tiên
            low[u] = min(low[u], num[v]);
        }
        
    }
    if(u == pre && child > 1) /// u là gốc DFS và có nhiều hơn 1 nhánh
        articulations++; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V >> E;
    int u, v;
    edges.resize(V + 1);
    num.resize(V + 1);
    low.resize(V + 1);
    isarticulation.resize(V + 1);
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= V; ++i){
        if(num[i] == 0)
            DFS(i, i);
    }
    cout << articulations << " " << bridges << "\n";
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
#define MAX_K 10
int N, E, k, _count;
vector<vector<int> > edges(MAX_N, vector<int>());
vector<bool> visited(MAX_N);
void Try(int index, int prev)
{
    for(int node : edges[prev]){
        if(visited[node]){
            continue;
        }
        visited[node] = true;
        if(index == k){
            _count++;
        }
        else
            Try(index + 1, node);
        visited[node] = false;
    }
}
int main()
{
    cin >> N >> k >> E;
    int u,v;
    for(int i = 1; i <= E; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i = 1; i <= N; ++i){
        visited[i] = true;
        Try(1, i);
        visited[i] = false;
    }
    cout << (_count >> 1) << "\n";
    return 0;
}

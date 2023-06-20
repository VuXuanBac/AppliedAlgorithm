/// Tìm nút cha của một nút trên cây.
/// BFS: O(2*|V|) // |E| = |V| - 1
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V, u, v;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V;
    vector<vector<int> > edges;
    for(int i = 1; i < V; ++i){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    queue<int> Q;
    Q.push(1);
    father[1] = 1;
    while(!Q.empty()){
        u = Q.front();
        Q.pop();
        for(const int& v : edges[u]){
            if(father[v] == 0){
                father[v] = u;
                Q.push(v);
            }
        }
    }
    for(int i = 2; i <= V; ++i)
        cout << father[i] << " ";
    return 0;
}


/// Kiểm tra đồ thị hai phần (Bipartie Graph)
/// Một cách phân hoạch tập đỉnh thành 2 tập mà mọi cạnh đều chỉ nối giữa hai đỉnh thuộc hai tập đó.
/// BFS: O(|V| + |E|)
#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<vector<int> > edges;
int check_bipartie()
{
    /// state = 0 <-> Not Visited
    /// state = 1 <-> Belong to set 1
    /// state = 2 <-> Belong to set 2
    vector<int> state(V + 1);
    queue<int> vqueue;
    int v;
    for(int st = 1; st <= V; ++st){ /// in case the graph has many connected components
        if(state[st] != 0) continue;
        vqueue.push(st);
        state[st] = 1; /// default belong to set 1
        while(!vqueue.empty()){
            v = vqueue.front(); vqueue.pop();
            for(int nv : edges[v]){
                if(state[nv] == 0){
                    state[nv] = 3 - state[v]; // belong to the other set
                    vqueue.push(nv);
                }
                else if(state[nv] == state[v])
                    return 0;
            }
        }
    }
    return 1;
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    cin >> V >> E;
    edges.resize(V + 1);
    int u, v;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << check_bipartie();
    return 0;
}

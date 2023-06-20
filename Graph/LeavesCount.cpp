/// Đếm số lá trên cây -> Đếm số nút khác gốc mà bậc bằng 1
/// O(1)
#include <bits/stdc++.h>
using namespace std;

int V;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> V;
    int u, v, lcount = 0;
    vector<int> degree(V + 1, 0);
    for (int i = 1; i < V; ++i)
    {
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    for(const int& d : degree){
        if(d == 1) 
            lcount++;
    }
    cout << (degree[1] == 1 ? lcount - 1 : lcount) << "\n";
    return 0;
}

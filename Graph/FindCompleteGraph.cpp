/// Tìm đồ thị đầy đủ là đồ thị con của đồ thị vô hướng mà số đỉnh là lớn nhất
/// Brute-Force: Đếm số đồ thị đầy đủ chứa đỉnh v và Đếm số đồ thị đầy đủ chứa một đỉnh > v
/// V <= 12
#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> edges; /// danh sách cạnh dưới dạng Bitmask
/// Xét đỉnh v thuộc đồ thị đầy đủ với vertices là bitmask thể hiện các đỉnh có thể xét tiếp theo
/// Chỉ duyệt tiếp các đỉnh > v trong vertices.
int Try(int v, int vertices)
{
    int res = 1;
    int i = v + 1;
    int e = vertices >> i;
    while(e){
        if(e & 1){
            res = max(res, 1 + Try(i, vertices & edges[i]));
        }
        e >>= 1;
        i++;
    }
    return res;
}
int main()
{
    cin >> V >> E;
    edges.resize(V + 1);
    int u, v;
    for(int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        edges[u] |= (1 << v);
        edges[v] |= (1 << u);
    }
    cout << Try(0, (1 << (V + 2)) - 1) - 1;
    return 0;
}
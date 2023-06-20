/// BFS: Ứng dụng.
/// Tìm nút cha của một nút trên cây.
/// BFS: O(2*|V|) // |E| = |V| - 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int st, en, floors, up, down, cur = 0, n;
    cin >> floors >> st >> en >> up >> down;
    queue<int> Q;
    Q.push(st);
    vector<int> dist(floors + 1, -1);
    dist[st] = 0;
    while(!Q.empty()){
        cur = Q.front();
        Q.pop();
        if(cur == en)
            break;
        n = cur + up;
        if(n <= floors && dist[n] < 0){
            Q.push(n);
            dist[n] = dist[cur] + 1;
        }
        n = cur - down;
        if(n > 0 && dist[n] < 0){
            Q.push(n);
            dist[n] = dist[cur] + 1;
        }
    }
    if(dist[en] > -1)
        cout << dist[en] << "\n";
    else
        cout << "use the stairs\n";
    return 0;
}


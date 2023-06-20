
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 101
#define MAX_ROUTES 10
int N, R;
int dist[MAX_N][MAX_N];
vector<int> routes;
vector<bool> visited(MAX_N);
int _size, cur_dist, best, en;
void Try(int index, int prev)
{
    for(int i = 1; i < _size; ++i){
        int node = routes[i];
        if(!visited[node] && dist[prev][node] > 0){
            visited[node] = true;
            cur_dist += dist[prev][node];
            if(index == _size-1){
                if(dist[node][en] > 0)
                    best = min(best, cur_dist + dist[node][en]);
            }
            else if(cur_dist < best){
                Try(index + 1, node);
            }
            cur_dist -= dist[prev][node];
            visited[node] = false;
        }
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> N >> R;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= N; ++j)
            cin >> dist[i][j];
    int v;
    for(int i = 0; i < R; ++i)
    {
        routes.clear();
        cur_dist = 0; best = INT_MAX;
        while(cin >> v){
            routes.push_back(v);
            if(cin.peek() != ' ')
                break;
        }
        _size = routes.size() - 1;
        en = routes[_size];
        if(_size == 1)
            best = dist[routes[0]][en];
        else
            Try(1, routes[0]);
        cout << (best == INT_MAX ? 0 : best) << "\n";
//        for(int j = 0; j < routes[i]._size(); ++j)
//            cout << routes[i][j] << " ";
//        cout << "\n";
    }
    return 0;
}

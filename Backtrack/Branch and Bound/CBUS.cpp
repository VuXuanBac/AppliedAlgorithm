/// NOT FULL
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 12
int n, points_num, max_load, cur_load, cur_cost, best_cost = INT_MAX;
int distances[MAX_N << 1][MAX_N << 1];
int route[MAX_N << 1];
vector<bool> visited(MAX_N << 1, false);
void Try(int index, int prev_point)
{
    for(int i = 1; i <= points_num; ++i){
        if(i <= n && cur_load >= max_load){
            i = n;
            continue;
        }
        if(visited[i] || (i > n && visited[i - n] == false) ||
            cur_cost + distances[prev_point][i] >= best_cost)
            continue;
        //cout << "Try at " << i << " " << " for index " << index << "\n";
        int restore_load = cur_load;
        cur_load += (i > n ? -1 : 1);
        visited[i] = true;
        route[index] = i;
        cur_cost += distances[prev_point][i];
        if(index == points_num){
            cout << "ROUTE FOUND: ";
            for(int i = 0; i <= points_num; ++i)
                cout << route[i] << " ";
            best_cost = min(cur_cost + distances[i][0], best_cost);
            cout << " COST " << cur_cost + distances[i][0] << "\n";
        }
        else
            Try(index + 1, i);
        visited[i] = false;
        cur_cost -= distances[prev_point][i];
        cur_load = restore_load;
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> n >> max_load;
    points_num = n << 1;
    for(int r = 0; r <= points_num; ++r){
        for(int c = 0; c <= points_num; ++c)
            cin >> distances[r][c];
    }
    visited[0] = true;
    route[0] = 0;
    Try(1, 0);
    cout << best_cost << "\n";
    return 0;
}

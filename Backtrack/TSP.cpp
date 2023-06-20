
#include <bits/stdc++.h>
#include <conio.h>
#define V 2
using namespace std;
int n, m;
int pos[21];
int best_cost = INT_MAX;
bool visited[21];
#if V == 1
typedef struct destcost {
    int dest;
    int cost;
} DestCost;
vector<vector<DestCost>> node;
#elif V == 2
int cost[21][21];
#endif // V
void print()
{
    for(int i = 1; i <= n; ++i)
        cout << pos[i] << " -> ";
    cout << "1\n";
}
#if V == 1
void Try(int index, int cur_cost)
{
    vector<DestCost> temp = node[pos[index-1]]; /// list next location of previous node
    for(int i = 0; i < temp.size(); ++i) {
        if(visited[temp[i].dest] || cur_cost + temp[i].cost >= best_cost)
            continue;
        pos[index] = temp[i].dest;
        if(index == n) {
            for(int j = 0; j < node[1].size(); ++j) {
                if(node[1].at(j).dest == pos[index]) {
                    print();
                    if(cur_cost + node[1].at(j).cost + temp[i].cost < best_cost)
                        best_cost = cur_cost + node[1].at(j).cost + temp[i].cost;
                    break;
                }
            }
        } else {
            visited[pos[index]] = true;
            Try(index+1, cur_cost + temp[i].cost);
            visited[pos[index]] = false;
        }
    }
}
#elif V == 2
void Try(int index, int cur_cost)
{
    for(int i = 1; i <= n; ++i) {
        if(!visited[i] && cost[pos[index]][i] > 0) {
            //cout << "chosen next: " << i << "\n";
            pos[index+1] = i;
            cur_cost += cost[pos[index]][i];
            //cout << "cur_cost : " << cur_cost << "\n";
            if(cur_cost < best_cost) {
                if(index+1 == n && cost[i][1] > 0) {
                    print();
                    if(cur_cost + cost[i][1] < best_cost)
                        best_cost = cur_cost + cost[i][1];
                }
                else
                {
                    visited[i] = true;
                    Try(index+1, cur_cost);
                    visited[i] = false;
                }
            }
            cur_cost -= cost[pos[index]][i];
        }
    }
}
#endif // V
//void printcost()
//{
//    for(int i = 1; i <= n; ++i){
//        int costi[21];
//        for(int j = 1; j <= n; ++j)
//            costi[j] = -1;
//        for(int j = 0; j < cost[i].size(); ++j)
//            costi[cost[i][j].dest] = cost[i][j].cost;
//        for(int j = 1; j <= n; ++j)
//            cout << costi[j] << " ";
//        cout << "\n";
//    }
//}
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\testout2.txt", "w", stdout);
    do {
        cin >> n >> m;
        if(n <= 0)
            break;
        int x, y, c;
#if V == 1
        for(int i = 0; i <= n; ++i) {
            node.push_back(vector<DestCost>());
        }
        for(int i = 0; i < m; ++i) {
            cin >> x >> y >> c;
            node[x].push_back({y, c});
        }
#elif V == 2
        for(int i = 1; i <= n; ++i) {
            cost[i][i] = -1;
            for(int j = 1; j < i; ++j)
                cost[i][j] = cost[j][i] = -1;
        }
        for(int i = 0; i < m; ++i) {
            cin >> x >> y >> c;
            cost[x][y] = c;
        }
#endif // V
        for(int i = 2; i <= n; ++i)
            visited[i] = false;
        visited[1] = true;
        pos[1] = 1; /// start at 1
        Try(1, 0);
        cout << best_cost << "\n";
        //
    } while(n > 0);
    return 0;
}


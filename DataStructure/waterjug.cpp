#include <bits/stdc++.h>
using namespace std;
#define MAX 901
int a,b,c;
typedef struct status {
    int first;
    int second;
} STATUS;
vector<vector<int>> visit;
queue<STATUS> bfs_queue;

int bfs()
{
    int first, second;
    int step;
    while(!bfs_queue.empty()) {
        first = bfs_queue.front().first;
        second = bfs_queue.front().second;
        step = visit[first][second] + 1;
        //cout << "POP " << first << " " << second << " next step " << step << "\n";
        bfs_queue.pop();
        if(first == c || second == c) {
            return visit[first][second];
        }
        if(first != 0 && !visit[0][second]) {
            //cout << "EMPTY the First\n";
            bfs_queue.push({0, second});            /// empty the first
            visit[0][second] = step;
        }
        if(second != 0 && !visit[first][0]) {
            //cout << "EMPTY the Second\n";
            bfs_queue.push({first, 0});             /// empty the second
            visit[first][0] = step;
        }
        if(first < a) {
            if(!visit[a][second])   {           /// fill the first
                //cout << "FILL the First\n";
                bfs_queue.push({a, second});
                visit[a][second] = step;
            }
            if(second != 0) {                   /// second to first
                int x = first + second;
                x = x > a ? a : x;
                int y = first + second - x;
                if(!visit[x][y]){
                    //cout << "Second to First: ";;
                    bfs_queue.push({x, y});
                    visit[x][y] = step;
                }
                //cout << x << " " << y << "\n";
            }
        }
        if(second < b) {
            if(!visit[first][b])   {           /// fill the second
                //cout << "FILL the Second\n";
                bfs_queue.push({first, b});
                visit[first][b] = step;
            }
            if(first != 0) {                    /// first to second
                int y = first + second;
                y = y > b ? b : y;
                int x = first + second - y;
                if(!visit[x][y]){
                    //cout << "First to Second: ";
                    bfs_queue.push({x, y});
                    visit[x][y] = step;
                }
                //cout << x << " " << y << "\n";
            }
        }
    }
    return -1;
}
int main()
{
    //gentest();
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\testout.txt", "w", stdout);
    cin >> a >> b >> c;
    bfs_queue.push({a, 0});
    bfs_queue.push({0, b});
    for(int i = 0; i <= a; ++i)
        visit.push_back(vector<int>(b+1));
    visit[0][0] = 1;
    visit[a][0] = 1;
    visit[0][b] = 1;
    cout << bfs() << "\n";
    return 0;
}

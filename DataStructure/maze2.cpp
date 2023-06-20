#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 901
int M, N;
int maze[MAX_SIZE][MAX_SIZE];
const int x[] = {1, 0, -1, 0};
const int y[] = {0, 1, 0, -1};
typedef struct cell{
    int row;
    int col;
}CELL;
queue<CELL> Q;
vector<vector<int> > min_path(MAX_SIZE, vector<int>(MAX_SIZE));
int bfs(int row, int col)
{
    Q.push({row, col});
    min_path[row][col] = 1;
    while(!Q.empty())
    {
        int rtop = Q.front().row;
        int ctop = Q.front().col;
        //cout << "VISIT " << rtop << " " << ctop << " path = " << min_path[rtop][ctop] << "\n";
        if(rtop == 1 || ctop == 1 || rtop == N || ctop == M)
            return min_path[rtop][ctop];
        Q.pop();
        int step = min_path[rtop][ctop] + 1;
        for(int i = 0; i < 4; ++i){
            int r = rtop + x[i];
            int c = ctop + y[i];
            if(maze[r][c] == 0 && min_path[r][c] == 0){
                //cout << "PUSH " << r << " " << c << "\n";
                Q.push({r, c});
                min_path[r][c] = step;
            }
        }
    }
    return -1;
}

int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\testout.txt", "w", stdout);
    int r0, c0;
    cin >> N >> M;
    cin >> r0 >> c0;
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            cin >> maze[i][j];
    cout << bfs(r0, c0) << "\n";
    return 0;
}

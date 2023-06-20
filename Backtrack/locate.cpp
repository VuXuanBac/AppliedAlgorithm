
#include <bits/stdc++.h>
using namespace std;
typedef struct position {
    int row;
    int col;
} position;
int N, Width, Height;
int main()
{
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int v;
        vector<position> detect_pos[2];
        cin >> Height >> Width;
        for(int j = 0; j < 2; ++j) {
            for(int r = 0; r < Height; ++r)
                for(int c = 0; c < Width; ++c) {
                    cin >> v;
                    if(v == 1)
                        detect_pos[j].push_back({r, c});
                }
        }
        int count_1 = detect_pos[0].size();
        int count_2 = detect_pos[1].size();
        vector<vector<int> > direction(Height << 1, vector<int>(Width << 1, 0));

        int _max = 0;
        for(int i = 0; i < count_1; ++i) {
            for(int j = 0; j < count_2; ++j) {

                int r = detect_pos[1][j].row - detect_pos[0][i].row + Height;
                int c = detect_pos[1][j].col - detect_pos[0][i].col + Width;
                if(++direction[r][c] > _max)
                    _max = direction[r][c];
            }
        }
        cout << _max << "\n";
    }
    return 0;
}

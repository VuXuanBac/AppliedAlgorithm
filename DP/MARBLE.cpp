/// Tìm cách cắt hình chữ nhật W*H theo các hình chữ nhật nhỏ hơn cho trước mà phần
/// thừa là nhỏ nhất.
/// DP: S[x][y] là diện tích lớn nhất có thể cắt được theo yêu cầu đối với hcn x*y
///     - Chọn một điểm cắt xi -> Chia hcn thành hai phần xi*y và (x - xi)*y
///     - Tương tự theo chiều y.
///     -> S[x'][y] = max{S[xi][y] + S[x - xi][y], với xi chạy từ 1 đến x-1}
///     -> S[x][y'] = max{S[x][yi] + S[x][y - yi], với yi chạy từ 1 đến y-1}
///     -> S[x][y] = x*y nếu x*y là một trong các hcn con. // Neo
#include <bits/stdc++.h>
using namespace std;

int W, H, n;
int main()
{
    cin >> W >> H >> n;
    int w, h;
    vector<vector<int> > S(W + 1, vector<int>(H + 1));
    for(int i = 0; i < n; ++i)
    {
        cin >> w >> h;
        S[w][h] = w*h;
    }
    for(int x = 1; x <= W; ++x){
        for(int y = 1; y <= H; ++y){
            for(int xi = 1; xi < x; ++xi)
                S[x][y] = max(S[x][y], S[xi][y] + S[x - xi][y]);
            for(int yi = 1; yi < y; ++yi)
                S[x][y] = max(S[x][y], S[x][yi] + S[x][y - yi]);
        }
    }
    cout << W*H - S[W][H];
}
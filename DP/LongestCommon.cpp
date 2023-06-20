/// Cho hai dãy a[1..N] và b[1..M]
/// Tìm dãy con chung dài nhất giữa hai dãy.
/// Các phần tử trong dãy con chung không cần liên tiếp nhau.
/// O(M*N)
/// ---------------------------
/// count[x][y] = Độ dài dãy con chung dài nhất giữa hai dãy a[1..x] và b[1..y]
/// Nếu a[x] != b[y]: count[x][y] = max( count[x-1][y], count[x][y-1] );
/// Nếu a[x] == b[y]: count[x][y] = max{ count[x-1][y], count[x][y-1], count[x-1][y-1] + 1 };
/// Cải tiến bộ nhớ: Do count[x][y] chỉ phụ thuộc vào các giá trị count[x][y-1], count[x-1][y] và count[x-1][y-1]
/// -> Dùng mảng 1 chiều bottom[y] <-> count[x][y]
#include <bits/stdc++.h>
using namespace std;
int N, M, v;
vector<int> a;
vector<int> b;
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    cin >> N >> M;
    a.push_back(0);
    b.push_back(0);
    for(int i = 0; i < N; ++i){
        cin >> v;
        a.push_back(v);
    }
    for(int i = 0; i < M; ++i){
        cin >> v;
        b.push_back(v);
    }
    // vector<vector<int> > _count(N + 1, vector<int>(M + 1));
    // for(int ia = 1; ia <= N; ++ia){
    //     for(int ib = 1; ib <= M; ++ib){
    //         int c = max(_count[ia][ib - 1], _count[ia - 1][ib]);
    //         if(a[ia] == b[ib])
    //             c = max(c, _count[ia - 1][ib - 1] + 1);
    //         _count[ia][ib] = c;

    //     }
    // }
    // CẢI TIẾN BỘ NHỚ
    vector<int> bottom(M + 1);
    for(int ia = 1; ia <= N; ++ia){
        int left = 0;
        for(int ib = 1; ib <= M; ++ib){
            int c = max(left, bottom[ib]);
            if(a[ia] == b[ib])
                c = max(c, bottom[ib - 1] + 1);
            bottom[ib - 1] = left;
            left = c;
        }
        bottom[M] = left;
    }
    cout << bottom[M] << "\n";
    return 0;
}

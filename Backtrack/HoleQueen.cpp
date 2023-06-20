
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 13
int n, m, _count;
int left_diag;
int right_diag;
int column;
vector<int> holes(MAX_N);
void Try(int row)
{
    int bicol = 1;
    int bileft = 1 << (row + n);
    int biright = 1 << (row);
    for (int col = 1; col <= n; ++col)
    {
        bicol <<= 1;
        bileft >>= 1;
        biright <<= 1;
        if ((column & bicol) || (holes[row] & bicol) ||
            (left_diag & bileft) || (right_diag & biright))
            continue;
        else
        {
            if (row == n)
            {
                _count++;
                //cout << "ANSWER\n";
            }
            else
            {
                //cout << "PUT AT " << row << " " << col << "\n";
                left_diag |= bileft;
                right_diag |= biright;
                column |= bicol;
                Try(row + 1);
                left_diag &= ~bileft;
                right_diag &= ~biright;
                column &= ~bicol;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    do
    {
        cin >> n >> m;
        if (n <= 0)
            break;
        _count = 0;
        for (int i = 1; i <= n; ++i)
            holes[i] = 0;
        int r, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> r >> c;
            holes[r] |= (1 << c);
        }
        Try(1);
        cout << _count << "\n";
    } while (true);
    return 0;
}
F

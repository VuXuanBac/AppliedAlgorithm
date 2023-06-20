#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    int x, y, z;
} block;
int n;
vector<block> a;
vector<int> maxh;
int dp(int i)
{
    if (maxh[i] != 0)
        return maxh[i];
    maxh[i] = a[i].z;
    for (int j = 1; j <= 3 * n; j++)
    {
        if ((a[i].x < a[j].x && a[i].y < a[j].y) ||
            (a[i].x < a[j].y && a[i].y < a[j].x))
        {
            maxh[i] = max(maxh[i], a[i].z + dp(j));
        }
    }
    return maxh[i];
}

int main()
{
    int cnt = 1, x, y, z;
    while (1)
    {
        int res = 0;
        cin >> n;
        if (n == 0)
            break;
        a.resize(3 * n + 1);
        maxh.resize(3 * n + 1);
        std::fill(maxh.begin(), maxh.end(), 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y >> z;
            a[3 * i - 2].x = x;
            a[3 * i - 2].y = y;
            a[3 * i - 2].z = z;
            a[3 * i - 1].x = y;
            a[3 * i - 1].y = z;
            a[3 * i - 1].z = x;
            a[3 * i].x = z;
            a[3 * i].y = x;
            a[3 * i].z = y;
        }
        for (int i = 1; i <= 3 * n; i++)
            res = max(res, dp(i));
        printf("Case %d: maximum height = %d\n", cnt++, res);
    }
    return 0;
}

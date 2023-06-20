#include <bits/stdc++.h>
using namespace std;
#define MUL 7418880
int result[6];
int query(int i, int j)
{
    cout << "? " << i << " " << j << "\n";
    fflush(stdout);
    cin >> i;
    return i;
}

void extract(int value, int &i, int &j)
{
    if (value % 5 == 0)
        i = 15;
    else if (value % 7 == 0)
        i = 42;
    else if (value % 23 == 0)
        i = 23;
    else if (value >= 64)
        i = 16;
    else
        i = 8;
    j = value / i;
}
int main()
{
    int f, s, u, v;
    int _01 = query(0, 1);
    int _23 = query(2, 3);
    int _02 = query(0, 2);
    int _14 = query(1, 4);
    extract(_01, f, s);
    extract(_02, u, v);
    if (f == u || s == u)
    {
        result[1] = f == u ? s : f;
        result[0] = u;
        result[2] = v;
    }
    else
    {
        result[1] = f == v ? s : f;
        result[0] = v;
        result[2] = u;
    }
    result[3] = _23 / result[2];
    result[4] = _14 / result[1];
    result[5] = MUL / (_01 * _23 * result[4]);
    cout << "! ";
    for(int i = 0; i < 6; ++i)
        cout << result[i] << " ";
    return 0;
}

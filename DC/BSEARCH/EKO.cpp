#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int N, require;
int heights[MAX_N];
bool over_require(int h)
{
    int sum = 0;
    for(int i = 0; i < N; ++i)
        if(heights[i] > h)
            sum += (heights[i] - h);
    return sum >= require;
}
int bsearch_min(int l, int r)
{
    while(l < r) {
        int m = (l + r + 1) / 2;
        if (over_require(m))
            l = m;
        else
            r = m - 1;
    }
    if(l == r && over_require(l))
        return l;
    return -1;
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> N >> require;
    int max_height = 0;
    for(int i = 0; i < N; ++i) {
        cin >> heights[i];
        max_height = max(max_height, heights[i]);
    }
    cout << bsearch_min(0, max_height) << "\n";
    return 0;
}


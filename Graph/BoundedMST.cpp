#include <bits/stdc++.h>
#define MAX_N 101
#define MAX_M 1000
#define INF 10000000
using namespace std;
int N, M, K;
//vector<int> A[MAX_N];
int b[MAX_M];
int e[MAX_M];
int c[MAX_M]; // c[i] is the weight of edge (b[i],e[i])
int X[MAX_N]; // model solution, set of indices of edges of spanning trees
int W;
int ans;
// data structure for disjoint-set
int r[MAX_N]; // r[v] is rank of set v
int p[MAX_N]; // p[v] is parent of v
long long rs;
void link(int x, int y)
{
    if (r[x] > r[y])
        p[y] = x;
    else
    {
        p[x] = y;
        if (r[x] == r[y])
            r[y] = r[y] + 1;
    }
}
void makeSet(int x)
{
    p[x] = x;
    r[x] = 0;
}
int findSet(int x)
{
    if (x != p[x])
        p[x] = findSet(p[x]);
    return p[x];
}
int check(int val, int k)
{
    // check if set edges (b[X[1]],e[X[1]]), (b[X[2]],e[X[2]]), ...,
    // (b[X[val]],e[X[val]])
    // induces a cycle
    for (int i = 1; i <= N; i++)
        makeSet(i);
    for (int j = 1; j < k; j++)
    {
        int u = b[X[j]];
        int v = e[X[j]];
        int ru = findSet(u);
        int rv = findSet(v);
        if (ru == rv)
            return 0;
        link(ru, rv);
    }
    if (findSet(b[val]) == findSet(e[val]))
        return 0;
    return 1;
}
int selectMax(int d[], int N)
{
    int max_d = -1;
    int u = -1;
    for (int v = 1; v <= N; v++)
    {
        if (max_d < d[v])
        {
            max_d = d[v];
            u = v;
        }
    }
    return u;
}
int diameter()
{
    vector<int> A[MAX_N];
    for (int i = 1; i <= N - 1; i++)
    {
        int u = b[X[i]];
        int v = e[X[i]];
        A[u].push_back(v);
        A[v].push_back(u);
    }
    queue<int> Q;
    int d[MAX_N] = {-1};
    for (int v = 1; v <= N; v++)
        d[v] = -1;
    int s = 1;
    d[s] = 0;
    Q.push(s);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < A[u].size(); i++)
        {
            int v = A[u][i];
            if (d[v] < 0)
            {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    int x = selectMax(d, N);
    for (int v = 1; v <= N; v++)
        d[v] = -1;
    while (!Q.empty())
        Q.pop();
    d[x] = 0;
    Q.push(x);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = 0; i < A[u].size(); i++)
        {
            int v = A[u][i];
            if (d[v] < 0)
            {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    int y = selectMax(d, N);
    return d[y];
}
void TRY(int k)
{
    for (int v = X[k - 1] + 1; v <= M; v++)
    {
        int ok = check(v, k);
        if (ok)
        {
            X[k] = v;
            W += c[v];
            if (k == N - 1)
            {
                int dia = diameter();
                if (dia <= K)
                {
                    if (W < ans)
                        ans = W;
                }
            }
            else
            {
                TRY(k + 1);
            }
            W -= c[v];
        }
    }
}
int main()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        b[i] = u;
        e[i] = v;
        c[i] = w;
    }
    ans = INF;
    X[0] = 0;
    TRY(1);
    cout << ans;
}
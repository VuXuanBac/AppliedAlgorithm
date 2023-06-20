#include <bits/stdc++.h>
using namespace std;
LLONG_MAX
long long pow10(int c)
{
    if(c == 0) return 1;
    long long res = pow10(c / 2);
    res *= res;
    if(c % 2) 
        return 10*res;
    return res;
}
int main()
{
    int T, c;
    long long V, v;
    int C[] = {0, 1, 1, 1, 2, 1, 2, 2, 2, 3};
    int K[] = {1, 1, 1, 1, 2, 1, 2, 1, 1, 3};
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int a = 0, b = 1;
        cin >> V >> c;
        if(V % 1000){
            cout << 0 << "\n";
            continue;
        }
        V /= 1000;
        long long M = 5*pow10(c);
        if(V > M){
            a += V / M;
            V -= a*M;
        }
        while(V > 0){
            v = V % 10;
            a += C[v];
            b *= K[v];
            V /= 10;
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}
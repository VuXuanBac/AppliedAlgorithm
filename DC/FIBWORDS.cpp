#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int N;
string pattern;
string strN;
ull _count
ull dc(int N, int st, int en)
{
    if(N < 2){
        return en - st == 0 && (pattern[st] - '0' == N);
    }
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    //freopen("../test.txt", "r", stdin);
    int c = 1;
    while(true){
        getline(cin, strN);
        if(strN.length() < 1)
            break;
        N = std::stoi(strN);
        cout << N << "\n";
        getline(cin, pattern);
        cout << "Case " << c << ": " << dc(N, pattern) << "\n";
        c++;
    }
    //freopen("../testout.txt", "w", stdout);
    // cout.precision(10);
    // cout << fixed << "\n";
    return 0;
}

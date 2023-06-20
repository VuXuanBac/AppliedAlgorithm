#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int N, m, M, result;
/// 0 <-> on.
int count_on;
void Try(int day)
{
    int st = (count_on == M ? 1 : 0);
    int en = (count_on < m && day > 1) ? 1 : 2;
    for(int i = st; i < en; ++i) {
        int restore = count_on;
        count_on = (i == 1 ? 0 : count_on + 1);
        //cout << "Day " << day << (i == 1 ? " OFF\n" : " WORK\n");
        if(day == N){
            if(count_on >= m && count_on <= M || count_on == 0)
                result++;
            //cout << "COUNT " << result << "\n";
        }
        else
            Try(day + 1);
        count_on = restore;
    }
}
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> N >> m >> M;
    Try(1);
    cout << result % MOD << "\n";
    return 0;
}


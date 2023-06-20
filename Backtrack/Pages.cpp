/// Tìm cách phân hoạch dãy cho trước sao cho chênh lệch giữa 
/// tổng các phần tử của các tập con đôi một là nhỏ nhất.
#include <bits/stdc++.h>
using namespace std;
#define MAX_BOOKS 501
#define MAX_SCRIBERS 501
int books, scribers;
int pages[MAX_BOOKS];
int result[MAX_SCRIBERS];
long long sum_before[MAX_BOOKS];
long long best = LLONG_MAX;
long long cur_load;
void Try(int scb)
{
    int st = result[scb - 1];
    int temp;
    for (int en = st + 1; en < books; ++en)
    {
        temp = cur_load;
        cur_load = max(cur_load, sum_before[en] - sum_before[st]);
        if (scb == scribers - 1)
        {
            cur_load = max(cur_load, sum_before[books] - sum_before[en]);
            int tempresult = result[scb];
            result[scb] = en;
            if (cur_load < best)
                best = cur_load;
            else
                result[scb] = tempresult;
            cur_load = temp;
        }
        else if (cur_load < best)
        {
            result[scb] = en;
            Try(scb + 1);
            cur_load = temp;
        }
        else
            break;
    }
}
int main()
{
    freopen("./test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\test2.txt", "w", stdout);
    int N;
    cin >> N;
    for (int t = 0; t < N; ++t)
    {
        cin >> books >> scribers;
        sum_before[0] = 0;
        for (int b = 1; b <= books; ++b)
        {
            cin >> pages[b];
            sum_before[b] = sum_before[b - 1] + pages[b];
        }
        for(int i = 0; i <= scribers; ++i)
            result[i] = 0;
        best = LLONG_MAX;
        cur_load = 0;
        Try(1);
        int b = 1;
        for (int i = 1; i < scribers; ++i){
            while(b <= result[i]){
                cout << pages[b] << " ";
                ++b;
            }
            cout << "/ ";
        }
        while(b <= books){
            cout << pages[b] << " ";
            ++b;
        }
        cout << "\n";
    }
    return 0;
}

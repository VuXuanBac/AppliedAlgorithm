/// Tìm cách phân hoạch dãy cho trước sao cho chênh lệch giữa 
/// tổng các phần tử của các tập con đôi một là nhỏ nhất.
#include <bits/stdc++.h>
using namespace std;
#define MAX_BOOKS 502
#define MAX_SCRIBERS 502
int T, books, scribers;
int pages[MAX_BOOKS];
int start_book[MAX_SCRIBERS];
long long sum[MAX_BOOKS];
bool is_over(long long m)
{
    int prev_st = books + 1, scb = 1;
    while (scb <= scribers)
    {
        int st = prev_st;
        while (--st > 0)
        {
            if (sum[st] - sum[prev_st] > m)
                break;
        }
        if (st == 0)
            break;
        prev_st = st + 1;
        ++scb;
    }
    return scb <= scribers;
}
// Tìm kiếm theo giá trị max_load
long long bsearch()
{
    long long l = 1;
    long long r = sum[1];
    long long m = l;
    while (l < r)
    {
        m = (l + r) >> 1;
        if (is_over(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}
void find_start(long long max_load)
{
    start_book[scribers + 1] = books + 1;
    int scb = scribers;
    int b = books;
    while (scb > 0)
    {
        while (b >= scb)
        {
            if (sum[b] - sum[start_book[scb + 1]] > max_load)
                break;
            --b;
        }
        start_book[scb] = b + 1;
        --scb;
    }
}
void print()
{
    int b = 1;
    for (int i = 2; i <= scribers; ++i)
    {
        while (b < start_book[i])
        {
            cout << pages[b] << " ";
            ++b;
        }
        cout << "/ ";
    }
    while (b <= books)
    {
        cout << pages[b] << " ";
        ++b;
    }
    cout << "\n";
}
int main()
{
    freopen("../test.txt", "r", stdin);
    cin >> T;
    for (int test = 0; test < T; ++test)
    {
        cin >> books >> scribers;
        for (int b = 1; b <= books; ++b)
            cin >> pages[b];
        sum[books + 1] = 0;
        for (int b = books; b >= 1; --b)
            sum[b] = sum[b + 1] + pages[b];
        find_start(bsearch());
        print();
    }
    return 0;
}

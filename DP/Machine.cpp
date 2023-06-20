/// Cho dãy các cặp (start, end) (start < end)
/// Trọng số của một phần tử (st, en): en - st
/// Tìm một tập con của dãy trên sao cho
/// + Các phần tử đôi một rời nhau
/// + Tổng trọng số là lớn nhất.
/// ----------------------------
/// -> O(max{end_i} - min{start_i})
/// Khoảng cách giữa giá trị end lớn nhất và giá trị start nhỏ nhất.
#include <bits/stdc++.h>
using namespace std;
int N;
typedef struct period
{
    int start;
    int end;
} period;
vector<period> p;
bool Compare(period a, period b)
{
    return a.end < b.end;
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> N;
    int s, t;
    for (int i = 0; i < N; ++i)
    {
        cin >> s >> t;
        p.push_back({s, t});
    }
    // Sắp xếp ưu tiên giá trị period.end nhỏ hơn.
    sort(p.begin(), p.end(), Compare);
    // product[i] = Tổng trọng số lớn nhất tại thời điểm i
    // product[0] = 0
    // product[k] = product[k - 1] nếu k không phải thời điểm 'end'
    // product[endi] = max{ product[starti] + en-st }
    vector<int> product;
    product.push_back(0);
    int pos = 1;
    for (int period = 0; period < N; ++period)
    {
        int st = p[period].start;
        int en = p[period].end;
        while (pos <= en)
        {
            product.push_back(product.back());
            pos++;
        }
        product[en] = max(product[en], product[st] + en - st);
    }
    cout << product[p.back().end] << "\n";
    return 0;
}

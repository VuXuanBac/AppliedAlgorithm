/// Cho dãy các cặp (start, end) (start < end)
/// Trọng số của một phần tử (st, en): en - st
/// Tìm một bộ gồm HAI phần tử
/// + Rời nhau
/// + Tổng trọng số là lớn nhất.
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
    sort(p.begin(), p.end(), Compare);
    // for (int i : p)
    //     cout << i.start << " " << i.end << "\n";
    // cout << "\n";

    /// product[i] = Trọng số lớn nhất của các phần tử con nằm phía trước điểm i
    /// product[k] = product[k - 1] với k không phải một điểm end.
    /// product[endi] = max{ product[endi - 1], endi - starti }
    vector<int> product(p.front().end + 1, 0);
    int best = -1;
    int st = p.front().start;
    int en = p.front().end;
    product[en] = en - st;
    int pos = en + 1;
    for (int period = 1; period < N; ++period)
    {
        st = p[period].start;
        en = p[period].end;
        while (pos <= en)
        {
            product.push_back(product.back());
            pos++;
        }
        product[en] = max(product[en], en - st);
        if(product[st] > 0)
            best = max(best, product[st] + en - st);
    }
    cout << best << "\n";
    return 0;
}

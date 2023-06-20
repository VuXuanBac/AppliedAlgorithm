/// Cho tập các đoạn [si, fi]. Tìm tập con các đoạn đôi một 
/// không giao nhau mà có lực lượng lớn nhất
/// Greedy: Chọn đoạn có fi nhỏ nhất mà không giao với mọi đoạn đã chọn.
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pii> segments(N);
    for(auto& seg : segments)
    {
        cin >> seg.first >> seg.second;
    }
    sort(segments.begin(), segments.end(), 
        [](const auto& a, const auto&b) -> bool {
            return a.second < b.second;
    });
    int last = -1;
    int c = 0;
    for(const auto& s : segments)
    {
        if(s.first > last){
            c++;
            last = s.second;
        }
    }
    cout << c;
    return 0;
}

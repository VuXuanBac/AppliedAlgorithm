#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int N, c = 0, maxd = 0;
    long long result = 0;
    cin >> N;
    /// s.first = deadline, s.second = profit
    vector<pii> segments(N);

    for(auto& seg : segments)
    {
        cin >> seg.first >> seg.second;
        maxd = max(maxd, seg.first);
    }
    sort(segments.begin(), segments.end(), 
        [](const auto& a, const auto&b) -> bool {
            return (a.second > b.second);
    });
    vector<bool> is_set(maxd + 1);
    int d;
    for(const auto& s : segments){
        d = s.first;
        while(is_set[d]) d--;
        if(d > 0){
            is_set[d] = true;
            result += s.second;
            c++;
            if(c >= maxd)
                break;
        }
    }
    cout << result;
    return 0;
}

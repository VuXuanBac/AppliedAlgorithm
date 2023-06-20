#include <bits/stdc++.h>
using namespace std;
int n;
int l[101];
int r[101];
vector<int> missLeft;
vector<int> missRight;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> l[i] >> r[i];
        if(l[i] == 0)
            missLeft.push_back(i);
        if(r[i] == 0)
            missRight.push_back(i);
    }
    // missLeft.size() = missRight.size()
    int last_miss = missLeft.size() - 1;
    int mr_ind = missRight.size() - 1;
    for(int ml_ind = 0; ml_ind < last_miss; ++ml_ind)
    {
        if(missLeft[ml_ind] != missRight[mr_ind]){
            if(r[missLeft[ml_ind]] == missRight[mr_ind])
                swap(missLeft[ml_ind], missLeft[ml_ind+1]);
            l[missLeft[ml_ind]] = missRight[mr_ind];
            r[missRight[mr_ind]] = missLeft[ml_ind];
        }
        else{
            ml_ind--; // ignore this loop
        }
        mr_ind--;
    }
    for(int i = 1; i <= n; ++i)
        cout << l[i] << " " << r[i] << "\n";
    return 0;
}

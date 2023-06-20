/// Tìm dãy con tăng dài nhất (các phần tử có thể không liên tiếp)
/// O(n^2)
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10001
//int prev[MAX_N];
int length[MAX_N];
int N;
int a[MAX_N];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> a[i];
    length[1] = 1;
    int result = 0;
    for(int i = 2; i <= N; ++i){
        int l = 1;
        for(int j = i-1; j >= l; --j){
            if(a[j] < a[i] && length[j] >= l){
                l = length[j] + 1;
            }
        }
        length[i] = l;
        if(l > result)
            result = l;
    }
    cout << result << "\n";
    return 0;
}

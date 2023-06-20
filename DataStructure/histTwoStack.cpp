
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000002
int N;
long long hist[MAX_N];
long long max_rect[MAX_N];
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    do {
        cin >> N;
        if(N == 0)
            break;
        hist[0] = -1;
        hist[N+1] = -1;
        for(int i = 1; i <= N; ++i)
            cin >> hist[i];
        stack<int> left_index;
        for(int i = 1; i <= N; ++i) {
            if(hist[i] > hist[i-1])
                left_index.push(i-1);
            else {
                while(!left_index.empty() && hist[left_index.top()] >= hist[i])
                    left_index.pop();
            }
            max_rect[i] = (i-left_index.top())*hist[i];
        }
        stack<int> right_index;
        long long _max = 0;
        for(int i = N; i > 0; --i) {
            if(hist[i] > hist[i+1])
                right_index.push(i+1);
            else {
                while(!right_index.empty() && hist[right_index.top()] >= hist[i])
                    right_index.pop();
            }
            max_rect[i] += (right_index.top()-i-1)*hist[i];
            if(max_rect[i] > _max)
                _max = max_rect[i];
        }
        cout << _max << "\n";
    } while(true);
    return 0;
}

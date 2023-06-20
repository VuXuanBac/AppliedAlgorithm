#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
int N;
int require;
int heights[MAX_N];
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    while(cin >> N >> require){
        for(int i = 0; i < N; ++i)
            cin >> heights[i];
        sort(heights, heights+N);
        int higher = 0;
        int temp;
        for(int i = N-2; i >= 0; --i)
        {
            temp = higher + (heights[i+1]-heights[i])*(N-1-i);
            if(temp < require){
                higher = temp;
                continue;
            }
            else if(temp == require)
                cout << heights[i] << "\n";
            else
                cout << heights[i+1] - (require-higher+N-i-2)/(N-i-1) << "\n";
            break;
        }
    }
    return 0;
}

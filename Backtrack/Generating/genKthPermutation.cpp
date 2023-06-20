
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10001
int n, k;
int frac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600};

int main()
{
    cin >> n >> k;
    if(n < 13 && k > frac[n]) {
        cout << "-1\n";
        return 0;
    }
    int a[MAX_N];
    for(int i = 1; i <= n; ++i)
        a[i] = i;
    for(int i = 1; i <= n; ++i) {
        if(n-i > 12 || k <= frac[n-i])
            cout << a[i] << " "; /// nhung so duoc giu nguyen
        else {
            int next = i + k / frac[n-i];
            k %= frac[n-i];
            if(k == 0) {
                cout << a[--next] << " ";
                for(int ind = n; ind >= i; --ind)
                    if(ind != next)
                        cout << a[ind] << " ";
                break;
            } else {
                int temp = a[next];
                for(int ind = next; ind > i; --ind)
                    a[ind] = a[ind-1];
                a[i] = temp;
                cout << a[i] << " ";
            }
        }
    }
    return 0;
}


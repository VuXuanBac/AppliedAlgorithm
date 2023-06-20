#include <iostream>
using namespace std;
int n, k;
int cur[100];
int c[100];
void print()
{
    cout << "{";
    for(int i = 0; i < k-1; ++i)
        cout << cur[i] << ", ";
    cout << cur[k-1] << "}\n";
}
void Try(int index)
{
    for(int i = 0; i < n; ++i) {
        if(c[i]) {
            cur[index] = i+1;
            if(index == k-1)
                print();
            else {
                c[i] = 0;
                Try(index + 1);
                c[i] = 1;
            }
        }
    }
}
int main()
{
    do {
        cin >> n >> k;
        if(n <= 0)
            break;
        for(int i = 0; i < n; ++i)
            c[i] = 1;
        Try(0);
    } while(n > 0);
    return 0;
}


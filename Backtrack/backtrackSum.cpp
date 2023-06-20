#include <iostream>
using namespace std;
int n, k;
int cur[100];
int sum[100];
void print(int k)
{
    cout << n << " = ";
    for(int i = 1; i < k-1; ++i)
        cout << cur[i] << "+";
    cout << cur[k-1] << "\n";
}
int _count;
void Try(int index)
{
    for(int i = cur[index-1]; i <= n - sum[index-1]; ++i) {
        cur[index] = i;
        sum[index] = sum[index-1] + i;
        if(sum[index] == n){
            //print(index + 1);
            _count++;
        }
        else
            Try(index + 1);
    }
}
int main()
{
    do {
        cin >> n;
        if(n <= 0)
            break;
        _count = 0;
        sum[0] = 0;
        cur[0] = 1;
        Try(1);
        cout << _count << "\n";
    } while(n > 0);
    return 0;
}

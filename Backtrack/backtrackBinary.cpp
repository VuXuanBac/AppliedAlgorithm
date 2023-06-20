
#include <iostream>
using namespace std;
int n;
int cur[100];
void print()
{
    for(int i = 0; i < n; ++i)
        cout << cur[i];
    cout << "\n";
}
void Try(int index)
{
    for(int v = 0; v < 2; ++v)
    {
        cur[index] = v;
        if(index == n-1)
            print();
        else
            Try(index + 1);
    }
}
int main()
{
    do{
        cin >> n;
        if(n <= 0)
            break;
        Try(0);
    }while(n > 0);
    return 0;
}

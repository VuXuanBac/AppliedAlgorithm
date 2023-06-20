
#include <iostream>
using namespace std;
int n, k;
int cur[100];
void print()
{
    cout << "{";
    for(int i = 0; i < k-1; ++i)
        cout << cur[i] << ", ";
    cout << cur[k-1] << "}\n";
}
int genSubSeq()
{
    int i = k-1;
    while(cur[i] >= n+1-k+i)
        i--;
    if(i < 0)
        return -1;
    cur[i]++;
    while(i < k)
    {
        ++i;
        cur[i] = cur[i-1] + 1;
    }
    return 1;
}
int main()
{
    do{
        cin >> n >> k;
        if(n <= 0)
            break;
        for(int i = 0; i < k; ++i)
            cur[i] = i+1;
        print();
        while(genSubSeq() > -1)
            print();
    }while(n > 0);
    return 0;
}

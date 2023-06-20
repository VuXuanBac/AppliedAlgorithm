#include <iostream>
using namespace std;
int n, i;
int cur[100];
bool genNext()
{
    int i = n-1;
    while(i >= 0)
    {
        if(*(cur + i) == 0)
        {
            *(cur + i) = 1;
            return true;
        }
        else
            *(cur + i) = 0;
        i--;
    }
    return false;
}
void print(int index)
{
    cout << index << ": ";
    for(int i = 0; i < n; ++i)
        cout << cur[i];
    cout << "\n";
}
int main()
{
    do{
        cin >> n;
        for(int i = 0; i < n; ++i)
            cur[i] = 0;
        if(n <= 0)
            break;
        i = 1;
        do
        {
            print(i);
            ++i;
        }while(genNext());
    }while(n > 0);
    return 0;
}


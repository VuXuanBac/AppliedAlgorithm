#include <iostream>
using namespace std;
int n, i;
int cur[100];
int cur_01_count;
int genNext()
{
    int i = n-1;
    if(i >= 1 && cur[i] == 0 && cur[i-1] == 0)
        cur_01_count++;
    while(i >= 0)
    {
        if(*(cur + i) == 0)
        {
            *(cur + i) = 1;
            if(i == 0 || (i < n-1 && cur[i-1] == 1))
                cur_01_count--;
            return cur_01_count == 2;
        }
        else
            *(cur + i) = 0;
        i--;
    }
    return -1;
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
        int result;
        while((result = genNext()) >= 0)
        {
            if(result == 1)
                print(i);
            ++i;
        }
    }while(n > 0);
    return 0;
}


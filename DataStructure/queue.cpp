
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int min_index[MAX];
int n;
int age[MAX];
int result[MAX];
int recur(int pivot, int end)
{
    //cout << "recur: " << pivot << " " << end << "\n";
    if(end < 0)
    {
        //cout << "end < 0\n";
        return -1;
    }
    if(age[pivot] <= age[min_index[end]])
    {
        //result[pivot] = -1;
        //cout << "age[" << pivot << "] = " << age[pivot] << " <= age["
          //  << min_index[end] << "] = " << age[min_index[end]] << "\n";
        return -1;
    }
    else
    {
        int prev = recur(pivot, min_index[end]-1);
        //cout << "after recur " << min_index[end] -1 << ": " << prev << "\n";
        return (prev < 0 ? min_index[end] : prev);
        //result[pivot] = prev < 0 ? min_index[end] : prev;
    }
}
int main()
{
    //gentest();
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\testout.txt", "w", stdout);
    cin >> n;
    for(int i = n-1; i >= 0; --i)
        cin >> age[i];
    min_index[0] = 0;
    for(int i = 1; i < n; ++i)
    {
        min_index[i] = age[min_index[i-1]] > age[i] ? i : min_index[i-1];
    }
//    for(int i = 0; i < n; ++i)
//        cout << min_index[i] << " ";
    result[0] = -1;
    for(int i = 1; i < n; ++i)
        result[i] = recur(i, i-1);
    //cout << "RESULT\n";
    for(int i = n-1; i >= 0; --i)
        cout << (result[i] == -1 ? -1 : i-result[i]-1) << " ";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
#define M_PI  3.14159265358979323846
#define PRE 0.0000001
int T, N, F;
int radius;
double area[MAX_N];
double sum_area = 0;
bool is_over(double x)
{
    int set_count = F + 1;
    for(int i = 0; i < N; ++i)
    {
        set_count -= (int)floor(area[i] / x);
        if(set_count <= 0)
            return false;
    }
    return true;
}
double DC()
{
    double l = PRE;
    double r = sum_area / (F + 1) + PRE;
    double mid;
    while(r - l >= PRE){
        mid = (l + r) / 2;
        if(is_over(mid))
            r = mid;
        else
            l = mid + PRE;
    }
    return l-PRE;
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    freopen("../test.txt", "r", stdin);
    //freopen("../testout.txt", "w", stdout);
    cin >> T;
    for(int i = 0; i < T; ++i){
        cin >> N >> F;
        for(int j = 0; j < N; ++j)
        {    
            cin >> radius;
            area[j] = (double)radius*radius;
            sum_area += area[j];            
        }
        cout.precision(7);
        cout << fixed << DC()*M_PI << "\n";
    }
    
    return 0;
}

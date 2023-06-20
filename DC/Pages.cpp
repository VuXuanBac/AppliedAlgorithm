#include <bits/stdc++.h>
using namespace std;
#define MAX_BOOKS 501
#define MAX_SCRIBERS 501
int T, books, scribers;
int pages[MAX_BOOKS];
int result[MAX_SCRIBERS];
long long sum[MAX_BOOKS];
long long dc(int scbs, int prev_end)
{
    //cout << "DC with " << scbs << " start " << prev_end+1 << "\n";
    if(scbs == 1){
        //cout << "Load for 1 " << sum[books] - sum[prev_end] << "\n"; 
        return sum[books] - sum[prev_end];
    }
    long long best_load = LLONG_MAX;
    long long cur_load;
    for(int en = prev_end + 1; en < books; ++en){
        if(sum[en] - sum[prev_end] >= best_load){
            //cout << "Break at " << scbs << " start " << prev_end+1 << " end " << en << "\n";
            break;
        }
        cur_load = max(sum[en] - sum[prev_end], dc(scbs - 1, en));
        if(cur_load < best_load){
            best_load = cur_load;
            result[scribers - scbs + 1] = en;
            // cout << "Cur best " << scbs << " start " << prev_end+1 <<
            //  " end " << en << " LOAD = " << cur_load << "\n";
        }
    }
    return best_load;
}
int main()
{
    freopen("..\\test.txt", "r", stdin);
    //freopen("c:\\users\\rsn\\desktop\\test2.txt", "w", stdout);
    cin >> T;
    for(int test = 0; test < T; ++test){
        cin >> books >> scribers;
        sum[0] = 0;
        for(int b = 1; b <= books; ++b){
            cin >> pages[b];
            sum[b] = sum[b-1] + pages[b];
        }
        dc(scribers, 0);
        int b = 1;
        for (int i = 1; i < scribers; ++i){
            while(b <= result[i]){
                cout << pages[b] << " ";
                ++b;
            }
            cout << "/ ";
        }
        while(b <= books){
            cout << pages[b] << " ";
            ++b;
        }
        cout << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define MAX_TYPE int(1e+9)
#define MAX_N int(1e+5)+1
int N, Q;
int _type[MAX_N];
int _count;
void change(int pos, int new_type)
{
    int cur_type = _type[pos];
    if(cur_type == new_type)
        return;
    _type[pos] = new_type;
    if(pos == 1) {
        if(N == 1)
            return;
        if(cur_type == _type[2])
            _count++;
        else if(new_type == _type[2])
            _count--;
        return;
    }
    if(pos == N) {
        if(cur_type == _type[N-1])
            _count++;
        else if(new_type == _type[N-1])
            _count--;
        return;
    }
    if(cur_type == _type[pos-1]) {
        if(cur_type == _type[pos+1])
            _count += 2;
        else if(new_type != _type[pos+1])
            _count++;
    } else if(cur_type == _type[pos+1]) {
        if(new_type != _type[pos-1])
            _count++;
    } else if(_type[pos-1] == _type[pos+1]) {
        if(new_type == _type[pos-1])
            _count -= 2;
    } else if(new_type == _type[pos+1] || new_type == _type[pos-1]) {
        _count--;
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    int pos, cur_type;
    do {
        cin >> N;
        if(N <= 0)
            break;
        cin >> _type[1];
        _count = 1;
        for(int i = 2; i <= N; ++i) {
            cin >> _type[i];
            if(_type[i] != _type[i-1])
                ++_count;
        }
        cout << _count << "\n";
        cin >> Q;
        for(int i = 0; i < Q; ++i) {
            cin >> pos >> cur_type;
            change(pos, cur_type);
            cout << _count << "\n";
        }
    } while(true);
    return 0;
}

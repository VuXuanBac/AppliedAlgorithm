/// Sắp xếp lịch on/off trong N ngày.
/// + Số ngày on liên tiếp >= min_days và <= max_days
/// + Số ngày off liên tiếp tối đa 1.
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int N, min_work, max_work;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> N >> min_work >> max_work;
    // _count[X] = Số cách sắp xếp mà tính đến ngày hiện tại 
    // thì số ngày làm việc liên tiếp đã là X
    // X = 0 <-> off
    long long temp, _sum;
    vector<long long> _count(max_work + 1);
    _count[0] = _count[1] = 1;
    for(int day = 1; day < N; ++day){
        temp = 0;
        /// Đếm số cách mà ngày hiện tại có thể off
        /// = Tổng số cách sắp xếp mà ngày phía trước đã on số ngày trong khoảng min_work đến max_work
        for(int wdays = min_work; wdays <= max_work;++wdays)
            temp = (temp + _count[wdays]) % MOD;
        for(int wdays = max_work; wdays >= 1; --wdays){
            _count[wdays] = _count[wdays - 1];
        }
        _count[0] = temp;
    }
    /// -> O(max_work * N)
    _sum = _count[0];
    for(int i = min_work; i <= max_work; ++i)
        _sum = (_sum + _count[i]) % MOD;
    cout << _sum << "\n";
    return 0;
}

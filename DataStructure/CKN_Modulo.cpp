
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T;
ll m, n, k;
ll extended_gcd(ll a, int b) /// s*a + t*b = gcd(a, b)
{
    pair<ll, ll> r = {a, b};
    pair<ll, ll> s = {1, 0};
    pair<ll, ll> t = {0, 1};
    ll quotient;
    while(r.second != 0){
        quotient = r.first / r.second;
        r = {r.second, r.first - quotient * r.second};
        s = {s.second, s.first - quotient * s.second};
        t = {t.second, t.first - quotient * t.second};
    }
    return t.first; /// b^(-1) mod a (if gcd(a, b) = 1, a > b)
}
ll multi_mod(ll a, ll b, ll m) /// a < m & b < m
{
    ll result = 0;
    while (b) {
        if (b & 1) {
            result += a;
            if (result >= m) result -= m;
        }
        a += a;
        if (a >= m) a -= m;
        b >>= 1;
    }
    return result;
}
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> T;
    for(int test = 0; test < T; ++test){
        cin >> n >> k >> m;
        if(k == 0){
            cout << "1\n";
            continue;
        }
        cout << multi_mod(n, k, m) << "\n";
        //cout << extended_gcd(m, k) << "\n";
        ll st = n - k;
        ll res = (st + 1) % m;
        for(ll i = 2; i <= k; ++i){
            ll temp = extended_gcd(m, i);
            res = multi_mod(res, temp < 0 ? temp + m : temp, m);
            res = multi_mod(res, (st+i) % m, m);
            if(res == 0)
                break;
        }
        cout << (res >= 0 ? res : res + m) << "\n";
    }
    return 0;
}

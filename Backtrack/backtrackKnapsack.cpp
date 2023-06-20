#include <bits/stdc++.h>
using namespace std;
#define MAX 30
int n, max_weight, best;
typedef struct item {
    int weight;
    int value;
} item;
item items[MAX];

void Try(int index, int sum_value, int remain_weight)
{
    for(int i = index; i >= 0; --i) {
        if(items[i].weight <= remain_weight) {
            if(sum_value + items[i].value > best)
                best = sum_value + items[i].value;
            if(i > 0 && remain_weight > items[i].weight)
                Try(i-1, sum_value + items[i].value, remain_weight - items[i].weight);
        }
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    do {
        cin >> n >> max_weight;
        if(n <= 0)
            break;
        int i;
        for(i = 0; i < n; ++i) {
            cin >> items[i].weight >> items[i].value;
        }
        Try(n-1, 0, max_weight);
        cout << best << "\n";
    } while(n > 0);
    return 0;
}


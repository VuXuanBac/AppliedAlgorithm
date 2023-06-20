
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1001
int N, _max_weight;
unsigned long long result;
int pos[MAX_N];
int weight[MAX_N];
class MyComparator
{
public:
    bool operator()(int x, int y)
    {
        if(pos[x] < 0 && pos[y] < 0)
            return pos[x] > pos[y];
        else
            return pos[x] < pos[y];
    }
};
priority_queue<int, vector<int>, MyComparator> pqueue;
int main()
{
    //freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> N >> _max_weight;
    for(int i = 0; i < N; ++i){
        cin >> pos[i] >> weight[i];
        pqueue.push(i);
    }
//    while(!pqueue.empty())
//    {
//        int top = pqueue.top();
//        cout << top << " " << pos[top] << " " << weight[top] << "\n";
//        pqueue.pop();
//    }
    int remain_weight, top, k = 1;
    long long times;
    while(!pqueue.empty())
    {
        //cout << "LOOP " << k++ << "\n";
        top = pqueue.top();
        times = (_max_weight == 1 ? weight[top] : (weight[top]/_max_weight + 1));
        result = result + (pos[top] > 0 ? times*pos[top] : -times*pos[top]);
        remain_weight = (_max_weight == 1 ? 0 : (_max_weight - weight[top]%_max_weight));
        //cout << "\tPOS " << pos[top] << "\n\tTIMES " << times << "\n\tRESULT "
          //  << result << "\n\tREMAIN " << remain_weight << "\n";
        pqueue.pop();
        //cout << "BACK\n";
        while(!pqueue.empty() && remain_weight > 0)
        {
            if(pos[top] > 0 && pos[pqueue.top()] < 0)
                break;

            top = pqueue.top();
            //cout << "\tREACH: POS " << pos[top] << "\tREMAIN " << remain_weight << " -> ";
            if(weight[top] > remain_weight){
                weight[top] -= remain_weight;
                //cout << "GREATER -> BACK TO 0.\n";
                break;
            }
            else
            {
                //cout << "DONE WITH " << pos[top] << "\n";
                remain_weight -= weight[top];
                pqueue.pop();
            }
        }
    }
    cout << (result << 1) << "\n";
    return 0;
}

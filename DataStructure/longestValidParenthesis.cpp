#include <bits/stdc++.h>
using namespace std;
typedef struct valid {
    int start_ind;
    int end_ind;
    int count;
} valid;
string input;
int input_len;
map<char, char> bracketpair = {{'(',')'}, {'[',']'}};

stack<valid> stValid;
void Try(int index)
{
    stack<int> open;
    for(int i = index; i < input_len; ++i) {
        /// open
        if(input[i] == '(' || input[i] == '[') {
            open.push(i);
        }
        /// close
        else if(open.empty() || input[i] != bracketpair[input[open.top()]]) {
            Try(i+1);
            return;
        } else {
            int st = open.top();
            int count = input[i] == ']' ? 1 : 0;
            if(!stValid.empty() && stValid.top().start_ind > st) {
                //cout << "POP " << stValid.top().start_ind << " " << stValid.top().end_ind << "\n";
                count += stValid.top().count;
                stValid.pop();
            }
            while(!stValid.empty() && stValid.top().end_ind + 1 == st) {
                st = stValid.top().start_ind;
                count += stValid.top().count;
                stValid.pop();
            }
            stValid.push({st, i, count});
            //cout << "PUSH " << st << " " << i << " " << count << "\t" << input.substr(st, i-st+1) << "\n";
            open.pop();
        }
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> input;
        input_len = input.length();
        cout << input << "\t" << input_len << "\n";
        while(!stValid.empty())
            stValid.pop();
        Try(0);
        if(stValid.empty())
            cout << 0 << "\n";
        else {
            valid max_ = stValid.top();
            while(!stValid.empty()) {
                if(stValid.top().count > max_.count)
                    max_ = stValid.top();
                stValid.pop();
            }
            cout << max_.count << "\n" << input.substr(max_.start_ind, max_.end_ind - max_.start_ind + 1) << "\n";
        }
//        cout << start_ind << " " << end_ind << "\t" << best_count << "\t"
//             << input.substr(start_ind, end_ind-start_ind+1) << "\n";
    }
    return 0;
}


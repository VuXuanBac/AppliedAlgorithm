#include <bits/stdc++.h>
using namespace std;
#define MAX_COURSES 17
#define MAX_SEMESTER 6
int courses_num, semester_num, best_load = INT_MAX, cur_load;
vector<int> semester_load(MAX_SEMESTER);
vector<int> semester_for_course(MAX_COURSES);
int credit[MAX_COURSES];
vector<vector<int> > pre(MAX_COURSES, vector<int>());
/// pre[x] = y > 0 -> course y must be assign before course x
/// pre[x] = -y < 0 -> course x must be assign before course y
/// x > |y|
//vector<vector<int> > pre(MAX_COURSES, vector<int>());
void Try(int course)
{
    int st = 1, en = semester_num;
    for(int c : pre[course]) {
        if(c > 0) /// c must be assign before 'course'
            st = max(st, semester_for_course[c] + 1);
        else
            en = min(en, semester_for_course[-c] - 1);
    }
    //cout << "COURSE " << course << " START " << st << " END " << en << "\n";
    for(int i = st; i <= en; ++i) {
        semester_for_course[course] = i;
        semester_load[i] += credit[course];
        int prev_load = cur_load;
        cur_load = max(prev_load, semester_load[i]);
        if(course == courses_num) {
            best_load = min(best_load, cur_load);
        } else if(cur_load < best_load)
            Try(course + 1);
        cur_load = prev_load;
        semester_load[i] -= credit[course];
        semester_for_course[course] = 0;
    }
}
int main()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> courses_num >> semester_num;
    for(int i = 1; i <= courses_num; ++i)
        cin >> credit[i];
    int v;
    for(int r = 1; r <= courses_num; ++r) {
        for(int c = 1; c <= courses_num; ++c) {
            cin >> v;
            if(v == 1) {
                if(r < c)
                    pre[c].push_back(r);
                else
                    pre[r].push_back(-c);
            }
        }
    }
    Try(1);
    cout << (best_load == INT_MAX ? -1 : best_load) << "\n";
    return 0;
}


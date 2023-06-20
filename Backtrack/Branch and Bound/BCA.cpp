#include <bits/stdc++.h>
using namespace std;
#define MAX_TEACHER 11
#define MAX_COURSES 31
int teachers_num, courses_num, result = INT_MAX, cur_max_load;
vector<vector<int> > conflict_courses(MAX_COURSES, vector<int>());
vector<vector<int> > teach(MAX_COURSES, vector<int>());

vector<int> teacher_load(MAX_TEACHER, 0);
vector<int> teacher_for_course(MAX_COURSES, 0);
void Try(int course)
{
    for(int teacher : teach[course]) {
        bool can_teach = true;
        for(int c : conflict_courses[course])
            if(teacher_for_course[c] == teacher)
                can_teach = false;
        if(!can_teach)
            continue;

        teacher_for_course[course] = teacher;
        teacher_load[teacher]++;
        int prev = cur_max_load;
        cur_max_load = max(cur_max_load, teacher_load[teacher]);
        if(course == courses_num) {
            result = min(result, cur_max_load);
        } else if(cur_max_load < result)
            Try(course+1);
        cur_max_load = prev;
        teacher_load[teacher]--;
        teacher_for_course[course] = 0;
    }
}
int main ()
{
    freopen("c:\\users\\rsn\\desktop\\test.txt", "r", stdin);
    cin >> teachers_num >> courses_num;
    int c, v, k;
    for (int t = 1; t <= teachers_num; ++t) {
        cin >> k;
        for(int i = 1; i <= k; ++i) {
            cin >> c;
            teach[c].push_back(t);
        }
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> c >> v;
        conflict_courses[c].push_back(v);
        conflict_courses[v].push_back(c);
    }
    Try(1);
    cout << (result == INT_MAX ? -1 : result) << "\n";
    return 0;
}

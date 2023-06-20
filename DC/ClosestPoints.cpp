/// Cho N điểm nguyên phân biệt trên mặt phẳng Descarte
/// Tìm cặp điểm có khoảng cách (Euclid) gần nhau nhất.
/// (Có duy nhất một cặp thỏa mãn)
#include <bits/stdc++.h>
using namespace std;
#define MAX_N 50000
typedef struct Point{
    int x;
    int y;
    int index;
}Point;
int N;
Point points[MAX_N];

bool Comparex(Point a, Point b)
{
    return a.x < b.x;
}
bool Comparey(Point a, Point b)
{
    return a.y < b.y;
}
double dist(Point a, Point b){
    double u = a.x - b.x;
    double v = a.y - b.y;
    return sqrt(u*u + v*v);
}
double check_mid(int st, int en, int enl, int str, 
        int mid_x, double bound, int &ind1, int&ind2)
{
    double bound_left = mid_x - bound;
    double bound_right = mid_x + bound;
    while(enl >= st && points[enl].x > bound_left) --enl;
    while(str <= en && points[str].x < bound_right) ++str;
    sort(points + enl + 1, points + str, Comparey);
    
    for(int i = enl + 1; i < str; ++i){
        double bound_up = points[i].y + bound;
        for(int j = i + 1; j < str; ++j){
            if(points[j].y >= bound_up)
                break;
            double d = dist(points[i], points[j]);
            if(d < bound){
                bound = d;
                bound_up = points[i].y + bound;
                ind1 = i; ind2 = j;
            }
        }
    }
    return bound;
}
double dc(int st, int en, int &ind1, int &ind2)
{
    if(en - st < 1){
        ind1 = ind2 = -1;
        return DBL_MAX;
    }
    if(en - st == 1){ // 2 points
        ind1 = st; ind2 = en;
        return dist(points[st], points[en]);
    }
    int mid = (en + st) >> 1;
    int enl = mid - 1;
    while(enl >= st && points[enl].x == points[mid].x) enl--;
    int str = mid + 1;
    while(str <= en && points[str].x == points[mid].x) str++;
    int ind1l, ind1r, ind2l, ind2r;
    double min_left = dc(st, enl, ind1l, ind2l);
    double min_right = dc(str, en, ind1r, ind2r);
    double min_side = min_left;
    ind1 = ind1l; ind2 = ind2l;
    if(min_right < min_left){
        min_side = min_right;
        ind1 = ind1r; ind2 = ind2r;
    }
    min_left = check_mid(st, en, enl, str, points[mid].x, min_side, ind1l, ind2l);
    if(min_left < min_side){
        ind1 = ind1l; ind2 = ind2l;
        return min_left;
    }
    return min_side;
}
void print(int st = 0, int en = N)
{
    for(int i = st; i < en; ++i)
        cout << "(" << points[i].x << ", " << points[i].y << ") ";
    cout << "\n";
}
int main()
{
    cin >> N;
    int x, y;
    for(int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        points[i] = {x, y, i};
    }
    sort(points, points + N, Comparex);
    cout.precision(7);
    double result = dc(0, N-1, x, y);
    int m = min(points[x].index, points[y].index);
    cout << m << " " << (points[y].index + points[x].index - m) << " " 
            << fixed << result << "\n";
    return 0;
}

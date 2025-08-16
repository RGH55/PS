#include <cstdio>
#include <algorithm>
#include <vector>
#define X first
#define Y second

using namespace std;
using Point = pair<int, int>;

int N;
vector<Point> p, ans;

int ccw(Point p1, Point p2, Point p3)
{
    long long c = (long long)(p2.X - p1.X) * (p3.Y - p2.Y) - (long long)(p3.X - p2.X) * (p2.Y - p1.Y);
    if(c > 0) return 1;
    if(c < 0) return -1;
    return 0;
}

bool cmp(const Point& a, const Point& b)
{
    int c = ccw(p.front(), a, b);
    return c > 0;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        p.push_back({x, y});
    }
    sort(p.begin(), p.end());
    sort(p.begin() + 1, p.end(), cmp);
    p.push_back(p.front());
    for(vector<Point>::iterator it = p.begin(); it != p.end(); ++it){
        while(ans.size() >= 2 && ccw(ans[ans.size() - 2], ans[ans.size() - 1], *it) <= 0) ans.pop_back();
        ans.push_back(*it);
    }
    printf("%d\n", ans.size() - 1);
    return 0;
}

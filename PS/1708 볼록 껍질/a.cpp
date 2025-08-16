#include <cstdio>
#include <algorithm>
#include <vector>
#define X first
#define Y second
#define MAX 40000

using namespace std;
using Point = pair<int, int>;

int N;
vector<int> vt[80005];
vector<Point> p[2], ans[2];
int d[2] = {1, -1};

int ccw(Point p1, Point p2, Point p3)
{
    long long k = (long long)(p2.X - p1.X) * (p3.Y - p2.Y) - (long long)(p3.X - p2.X) * (p2.Y - p1.Y);
    if(k > 0) return 1;
    if(k < 0) return -1;
    return 0;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x + MAX].push_back(y);
    }
    for(int i = -MAX; i <= MAX; i++) sort(vt[i + MAX].begin(), vt[i + MAX].end());
    for(int i = -MAX; i <= MAX; i++){
        if(vt[i + MAX].empty()) continue;
        p[0].push_back({i, vt[i + MAX].front()});
        p[1].push_back({i, vt[i + MAX].back()});
    }
    ans[0].push_back(p[0][0]);
    ans[0].push_back(p[0][1]);
    ans[1].push_back(p[1][0]);
    ans[1].push_back(p[1][1]);
    for(int i=0; i<2; i++){
        for(int j=2; j<p[i].size(); j++){
            while(ans[i].size() >= 2 && ccw(ans[i][ans[i].size() - 2], ans[i][ans[i].size() - 1], p[i][j]) != d[i]) ans[i].pop_back();
            ans[i].push_back(p[i][j]);
        }
    }
    int cnt = ans[0].size() + ans[1].size();
    if(ans[0].front() == ans[1].front()) cnt--;
    if(ans[0].back() == ans[1].back()) cnt--;
    printf("%d\n", cnt);
    return 0;
}

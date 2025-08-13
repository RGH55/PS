#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3)
{
    long long cross = (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x);
    if(cross > 0) return -1;
    if(cross < 0) return 1;
    return 0;
}

int main()
{
    pair<long long, long long> p1, p2, p3, p4;
    scanf("%lld %lld %lld %lld", &p1.x, &p1.y, &p2.x, &p2.y);
    scanf("%lld %lld %lld %lld", &p3.x, &p3.y, &p4.x, &p4.y);
    bool ans = true;
    if(ccw(p1, p2, p3) == ccw(p1, p2, p4)) ans = false;
    if(ccw(p3, p4, p1) == ccw(p3, p4, p2)) ans = false;
    if(ccw(p1, p2, p3) == ccw(p1, p2, p4) && ccw(p1, p2, p3) == 0){
        if((p1.x - p3.x) * (p1.x - p4.x) < 0) ans = true;
        if((p1.y - p3.y) * (p1.y - p4.y) < 0) ans = true;
        if((p2.x - p3.x) * (p2.x - p4.x) < 0) ans = true;
        if((p2.y - p3.y) * (p2.y - p4.y) < 0) ans = true;
        if((p1.x - p3.x) * (p2.x - p3.x) < 0) ans = true;
        if((p1.y - p3.y) * (p2.y - p3.y) < 0) ans = true;
        if((p1.x - p4.x) * (p2.x - p4.x) < 0) ans = true;
        if((p1.y - p4.y) * (p2.y - p4.y) < 0) ans = true;
    }
    if(p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4) ans = true;
    printf("%d\n", ans);
    return 0;
}

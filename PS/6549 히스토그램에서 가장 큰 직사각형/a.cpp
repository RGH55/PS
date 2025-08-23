#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int a[100005], seg[400005][3]; /// [0] : 가운데, [1] : 왼쪽, [2] : 오른쪽

void initSeg(int n, int s, int e)
{
    if(s == e){
        seg[n][0] = seg[n][1] = seg[n][2] = a[s];
        return;
    }
    initSeg(2*n, s, (s + e)/2);
    initSeg(2*n + 1, (s + e)/2 + 1, e);

}

int getInterval(int n, int s, int e, int i, int dir)
{
    if(seg[n] >= a[i]) return e - s + 1;
    if(s == e) return 0;
    if(dir == 1){
        int ret = getInterval(2*n + 1, (s + e)/2 + 1, e, i, 1);
        if(ret == e - (s + e)/2) ret += getInterval(2*n, s, (s + e)/2, i, 1);
        return ret;
    }
    if(dir == -1){
        int ret = getInterval(2*n, s, (s + e)/2, i, -1);
        if(ret == (s + e)/2 - s + 1) ret += getInterval(2*n + 1, (s + e)/2 + 1, e, i, -1);
        return ret;
    }
    int ret = max(getInterval(2*n, s, (s + e)/2, i, 0), getInterval(2*n + 1, (s + e)/2 + 1, e, i, 0));
    ret = max(ret, getInterval(2*n, s, (s + e)/2, i, 1) + getInterval(2*n + 1, (s + e)/2 + 1, e, i, -1));
    return ret;
}

int main()
{
    scanf("%d", &N);
    while(N){
        for(int i=1; i<=N; i++) scanf("%d", &a[i]);
        initSeg(1, 1, N);
        long long ans = 0;
        for(int i=1; i<=N; i++){
            ans = max(ans, (long long) a[i] * getInterval(1, 1, N, i, 0));
        }
        printf("%lld\n", ans);
        scanf("%d", &N);
    }
    return 0;
}

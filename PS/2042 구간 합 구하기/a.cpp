#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int N, M, K;
ll a[1000005];
ll seg[4000005];

ll init(int n, int s, int e)
{
    ll& ret = seg[n];
    if(s == e) return ret = a[s];
    return ret = init(2*n, s, (s + e)/2) + init(2*n + 1, (s + e)/2 + 1, e);
}

void update(int n, int s, int e, int x, ll delta)
{
    if(s > x || x > e) return;
    seg[n] += delta;
    if(s == e) return;
    update(2*n, s, (s + e)/2, x, delta);
    update(2*n + 1, (s + e)/2 + 1, e, x, delta);
}

ll sum(int n, int s, int e, int x, int y)
{
    if(x > e || y < s) return 0;
    if(x <= s && e <= y) return seg[n];
    return sum(2*n, s, (s + e)/2, x, (s + e)/2) + sum(2*n + 1, (s + e)/2 + 1, e, (s + e)/2 + 1, y);
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for(int i=1; i<=N; i++) scanf("%lld", &a[i]);
    init(1, 1, N);
    M += K;
    while(M--){
        ll c, x, y;
        scanf("%lld %lld %lld", &c, &x, &y);
        if(c == 1){
            update(1, 1, N, x, y - a[x]);
            a[x] = y;
        }
        else printf("%lld\n", sum(1, 1, N, x, y));
    }
    return 0;
}

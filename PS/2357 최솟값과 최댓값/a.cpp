#include <cstdio>
#include <algorithm>
#include <vector>
#define MIN 0
#define MAX 1000000005

using namespace std;

int N, M;
int a[100005];
pair<int, int> b[400005];

void init(int n, int s, int e)
{
    if(s == e){
        b[n] = {a[s], a[s]};
        return;
    }
    init(2*n, s, (s + e)/2);
    init(2*n + 1, (s + e)/2 + 1, e);
    b[n] = {min(b[2*n].first, b[2*n + 1].first), max(b[2*n].second, b[2*n + 1].second)};
}

pair<int, int> f(int n, int s, int e, int x, int y)
{
    if(y < s || x > e) return {MAX, MIN};
    if(x <= s && e <= y) return b[n];
    pair<int, int> f1 = f(2*n, s, (s + e)/2, x, y);
    pair<int, int> f2 = f(2*n + 1, (s + e)/2 + 1, e, x, y);
    return {min(f1.first, f2.first), max(f1.second, f2.second)};
}

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) scanf("%d", &a[i]);
    init(1, 1, N);
    while(M--){
        int x, y;
        scanf("%d %d", &x, &y);
        pair<int, int> ans = f(1, 1, N, x, y);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[505][2];
int dp[505][505];

int f(int s, int e)
{
    int& ret = dp[s][e];
    if(ret) return ret;
    if(s + 1 >= e) return 0;
    ret = (1 << 31) - 1;
    for(int i=s+1; i<e; i++){
        ret = min(ret, f(s, i) + f(i, e) + a[s][0] * a[i][0] * a[e-1][1]);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d", &a[i][0], &a[i][1]);
    printf("%d\n", f(0, N));
    return 0;
}

#include <cstdio>
#include <algorithm>
#define MAX 1e9

using namespace std;

int N;
int a[20][20];
int dp[17][65536]; /// [출발지][bitmask 2^16 visited]

int f(int n, int bit)
{
    int& ret = dp[n][bit];
    if(ret) return ret;
    if(bit == (1 << N) - 1 && n == 0) return 0;
    if(bit == (1 << N) - 1) return MAX;
    ret = MAX;
    for(int i=0; i<N; i++){
        if(bit & (1 << i) || a[n][i] == 0) continue;
        ret = min(ret, f(i, bit | (1<<i)) + a[n][i]);
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &a[i][j]);
    printf("%d\n", f(0, 0));
    return 0;
}

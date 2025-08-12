#include <cstdio>
#include <algorithm>
#define MOD 1000000000

using namespace std;

int N;
int dp[105][10][4]; /// [길이][끝][bitmask] -> bitmask는 0, 9 visited, 00 01 10 11

int f(int len, int n, int bit)
{
    int& ret = dp[len][n][bit];
    if(ret) return ret;
    if(len == N){
        if(bit == 3) ret = 1;
        else ret = 0;
        return ret;
    }
    if(n < 9){
        ret += f(len + 1, n + 1, bit | (n+1 == 9 ? 2 : 0));
        ret %= MOD;
    }
    if(n > 0){
        ret += f(len + 1, n - 1, bit | (n-1 == 0 ? 1 : 0));
        ret %= MOD;
    }
    return ret;
}

int main()
{
    scanf("%d", &N);
    int ans = 0;
    for(int i=1; i<10; i++){
        ans += f(1, i, (i == 9) ? 2 : 0);
        ans %= MOD;
    }
    printf("%d\n", ans);
    return 0;
}

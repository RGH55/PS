#include <cstdio>
#include <algorithm>

using namespace std;

int T, N;
int a[100005][2];
int dp[100005][3];

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%d", &a[i][0]);
        for(int i=0; i<N; i++) scanf("%d", &a[i][1]);
        dp[0][0] = a[0][0];
        dp[0][1] = a[0][1];
        dp[0][2] = 0;
        for(int i=1; i<=N; i++){
            dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + a[i][1];
            dp[i][2] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        }
        printf("%d\n", dp[N][2]);
    }
    return 0;
}

#include <cstdio>
#include <algorithm>
#define MAX 20005

using namespace std;

int T;
int N, W;
int a[10005][2];
int dp[10005][3][4];

int main()
{
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &W);
        for(int i=1; i<=N; i++) scanf("%d", &a[i][0]);
        for(int i=1; i<=N; i++) scanf("%d", &a[i][1]);
        a[0][0] = a[N][0]; a[0][1] = a[N][1];
        dp[0][2][2] = 0; dp[0][0][2] = dp[0][1][2] = MAX;
        dp[0][2][1] = 1; dp[0][0][1] = 0; dp[0][1][1] = MAX;
        dp[0][2][0] = 1; dp[0][0][0] = MAX; dp[0][1][0] = 0;
        dp[0][0][3] = dp[0][1][3] = dp[0][2][3] = MAX;
        dp[1][0][3] = dp[1][1][3] = dp[1][2][3] = MAX;
        if(a[0][0] + a[1][0] <= W && a[0][1] + a[1][1] <= W) dp[1][2][3] = 2;
        for(int i=1; i<=N; i++){
            for(int j=0; j<4; j++){
                if(i == 1 && j == 3) continue;
                dp[i][0][j] = dp[i-1][2][j] + 1;
                if(a[i-1][0] + a[i][0] <= W) dp[i][0][j] = min(dp[i][0][j], dp[i-1][1][j] + 1);
                dp[i][1][j] = dp[i-1][2][j] + 1;
                if(a[i-1][1] + a[i][1] <= W) dp[i][1][j] = min(dp[i][1][j], dp[i-1][0][j] + 1);
                dp[i][2][j] = min(dp[i][0][j], dp[i][1][j]) + 1;
                if(a[i][0] + a[i][1] <= W) dp[i][2][j] = min(dp[i][2][j], dp[i-1][2][j] + 1);
                if(i >= 2 && a[i][0] + a[i-1][0] <= W && a[i][1] + a[i-1][1] <= W) dp[i][2][j] = min(dp[i][2][j], dp[i-2][2][j] + 2);
            }
        }
        printf("%d\n", min(min(dp[N][1][0], dp[N][0][1]), min(dp[N][2][2], dp[N-1][2][3])));
    }
    return 0;
}

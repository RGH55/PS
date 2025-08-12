#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int a[1025][1025], dp[1025][1025];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &a[i][j]);
    dp[1][1] = a[1][1];
    for(int i=2; i<=N; i++){
        dp[i][1] = a[i][1] + dp[i-1][1];
        dp[1][i] = a[1][i] + dp[1][i-1];
    }
    for(int i=2; i<=N; i++){
        for(int j=2; j<=N; j++){
            dp[i][j] = a[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    while(M--){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]);
    }
    return 0;
}

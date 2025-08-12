#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[1005][3];
int dp[1005][3];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];
    for(int i=1; i<N; i++){
        dp[i][0] = a[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = a[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = a[i][2] + min(dp[i-1][1], dp[i-1][0]);
    }
    printf("%d\n", *min_element(dp[N-1], dp[N-1]+3));
    return 0;
}

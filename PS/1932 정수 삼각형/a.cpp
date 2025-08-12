#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[505][505];
int dp[505][505];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++) scanf("%d", &a[i][j]);
    }
    dp[0][0] = a[0][0];
    for(int i=1; i<N; i++){
        dp[i][0] = dp[i-1][0] + a[i][0];
        for(int j=1; j<i; j++) dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + a[i][j];
        dp[i][i] = dp[i-1][i-1] + a[i][i];
    }
    printf("%d\n", *max_element(dp[N-1], dp[N-1] + N));
    return 0;
}

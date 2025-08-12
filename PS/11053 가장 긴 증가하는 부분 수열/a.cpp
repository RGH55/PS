#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int a[1005];
int dp[1005];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &a[i]);
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    printf("%d\n", *max_element(dp, dp+N) + 1);
    return 0;
}

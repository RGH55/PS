#include <cstdio>
#include <algorithm>

using namespace std;

int C, N;
int dp[100005];

int main()
{
    scanf("%d %d", &C, &N);
    for(int i=0; i<N; i++){
        int c, w;
        scanf("%d %d", &c, &w);
        for(int i=c; i<=100000; i++){
            dp[i] = max(dp[i], dp[i-c] + w);
        }
    }
    for(int i=0; i<=100000; i++){
        if(dp[i] >= C){
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

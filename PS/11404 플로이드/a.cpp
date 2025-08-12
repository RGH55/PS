#include <cstdio>
#include <algorithm>
#define INF 1000000000

using namespace std;

int N, M;
int dp[105][105];

int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) if(i != j) dp[i][j] = INF;
    for(int i=0; i<M; i++){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        dp[s-1][e-1] = min(dp[s-1][e-1], w);
    }
    for(int i=0; i<N; i++){
        for(int s=0; s<N; s++){
            for(int e=0; e<N; e++){
                dp[s][e] = min(dp[s][e], dp[s][i] + dp[i][e]);
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dp[i][j] == INF) printf("0 ");
            else printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}

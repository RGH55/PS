#include <cstdio>
#include <algorithm>
#define MOD 1000000000

using namespace std;

int N;
int dp[105][10][10][10]; /// [길이][최소][최대][끝]

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=9; i++) dp[0][i][i][i] = 1;
    for(int i=1;i<N; i++){
        for(int a=0; a<=9; a++){
            for(int b=0; b<=9; b++){
                for(int c=0; c<=9; c++){
                    if(a == c){
                        if(c != 9) dp[i][a][b][c] = (dp[i-1][a][b][c+1] + dp[i-1][a+1][b][c+1])%MOD;
                    }
                    else if(b == c){
                        if(c != 0) dp[i][a][b][c] = (dp[i-1][a][b][c-1] + dp[i-1][a][b-1][c-1])%MOD;
                    }
                    else if(a <= c && c <= b){
                        if(c == 0) dp[i][a][b][c] = dp[i-1][a][b][c+1];
                        else if(c == 9) dp[i][a][b][c] = dp[i-1][a][b][c-1];
                        else dp[i][a][b][c] = (dp[i-1][a][b][c-1] + dp[i-1][a][b][c+1])%MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=9; i++) ans = (ans + dp[N-1][0][9][i])%MOD;
    printf("%d\n", ans);
    return 0;
}

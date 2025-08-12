#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

char a[1005], b[1005];
int dp[1005][1005];

int main()
{
    scanf(" %s %s", a, b);
    for(int i=0; a[i]!='\0'; i++){
        for(int j=0; b[j]!='\0'; j++){
            if(a[i] == b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    printf("%d\n", dp[strlen(a)][strlen(b)]);
    return 0;
}

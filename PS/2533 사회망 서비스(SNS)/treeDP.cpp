#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> vt[1000005];
int dp[1000005][2];

void dfs(int n, int p)
{
    dp[n][1]++;
    for(vector<int>::iterator it = vt[n].begin(); it != vt[n].end(); ++it){
        if(*it == p) continue;
        dfs(*it, n);
        dp[n][0] += dp[*it][1];
        dp[n][1] += min(dp[*it][0], dp[*it][1]);
    }
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N-1; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        vt[x].push_back(y);
        vt[y].push_back(x);
    }
    dfs(1, 0);
    printf("%d\n", min(dp[1][0], dp[1][1]));
    return 0;
}

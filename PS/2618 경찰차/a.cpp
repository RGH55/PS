#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using pii = pair<int, int>;

int N, W;
pii a[1005];
int dp[1005][1005];
int from[1005][2];
vector<int> vt;

int dist(int x, int y)
{
    return abs(a[x].first - a[y].first) + abs(a[x].second - a[y].second);
}

int main()
{
    scanf("%d %d", &N, &W);
    for(int i=1; i<=W; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = {x, y};
    }
    for(int i=1; i<=W; i++){
        for(int j=0; j<i-1; j++){
            dp[i][j] = dp[i - 1][j] + dist(i - 1, i);
            dp[j][i] = dp[j][i - 1] + dist(i - 1, i);
        }
        dp[i][i - 1] = dp[0][i - 1] + abs(1 - a[i].first) + abs(1 - a[i].second);
        dp[i - 1][i] = dp[i - 1][0] + abs(N - a[i].first) + abs(N - a[i].second);
        from[i][0] = 0;
        from[i][1] = 0;
        for(int j=1; j<i-1; j++){
            if(dp[i][i - 1] > dp[j][i - 1] + dist(j, i)){
                dp[i][i - 1] = dp[j][i - 1] + dist(j, i);
                from[i][0] = j;
            }
            if(dp[i - 1][i] > dp[i - 1][j] + dist(j, i)){
                dp[i - 1][i] = dp[i - 1][j] + dist(j, i);
                from[i][1] = j;
            }
        }
    }
    pii ans = {0, W};
    for(int i=0; i<W; i++){
        if(dp[ans.first][ans.second] > dp[i][W]) ans = {i, W};
        if(dp[ans.first][ans.second] > dp[W][i]) ans = {W, i};
    }
    printf("%d\n", dp[ans.first][ans.second]);
    for(int i=W; i>0; i--){
        if(ans.first == i){
            vt.push_back(1);
            if(ans.first - 1 == ans.second) ans.first = from[ans.first][0];
            else ans.first--;
        }
        else{
            vt.push_back(2);
            if(ans.second - 1 == ans.first) ans.second = from[ans.second][1];
            else ans.second--;
        }
    }
    for(vector<int>::reverse_iterator it = vt.rbegin(); it != vt.rend(); ++it) printf("%d\n", *it);
    return 0;
}
